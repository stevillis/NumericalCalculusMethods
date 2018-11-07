#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <math.h>

int main(void){
	setlocale(LC_ALL, "Portuguese");
	int i, j, k, n, m = 1;
	float soma = 0, d_r = 1, E = 0; 
	float max_xi = 0, max_d = 0, dif = 0, Beta_max = 0, aux1 = 0, aux2 = 0, aux3 = 0;
	float **A, *B, *x, *Beta, *aux;
	
	printf("\t\t--------------------------------------\n");
	printf("\t\tMétodo de Gauss-Seidel - SMS Produções\n");
	printf("\t\t--------------------------------------\n\n"); 	
	printf("Informe a dimensão do sistema de equações: "); 	
	scanf("%d", &n); 	//Quantidade de linhas
	A = (float **) malloc(n * sizeof(float *)); 	//Cria uma coluna de ponteiros para ponteiros de float	
	for(i = 0; i < n; i++){ 	//Cria um array de float
		A[i] = (float *) malloc(n * sizeof(float));
	}
	
	printf("\nInforme os coeficientes das equações\n"); 	////Leitura dos dados da matriz A
	for(i = 0; i < n; i++){
		for(j = 0; j < n; j++){
			printf("Informe o coeficiente a%d%d: ", i + 1, j + 1);
			scanf("%f", &A[i][j]);
		}
	}	
	
//Critério de Sassenfeld	
	Beta = (float *) malloc(n * sizeof(float)); 	//Aloca memória para o vetor Beta		
	for(i = 0; i < 1; i++){ 		//Calculando Beta_1
		for(j = 0; j < n; j++){
			if(i != j){ 	//B1 = (|a12| + |a13| + ... + |a1n|)/|a11|
				aux1 += fabs(A[i][j]); 	//Fixa a linha e soma todos os elementos desta linha
			}
		}
		Beta[i] = aux1/fabs(A[i][i]); 	//
		printf("\nBeta1 = %f\n", Beta[i]);
		Beta_max = Beta[i]; 	
	}
	
	for(i = 0; i < n; i++){ 	//Calculando Beta_n
		for(j = 0; j < n; j++){
			if(i != j && i > j){
				aux2 += fabs(A[i][j])*Beta[j]; 	//Soma das multiplicações de Aij com Beta
			}
			if(i != j && i < j){
				aux3 += fabs(A[i][j]); 	//Soma dos termos Aij que não multiplicam Beta
			}
		}
		if(i != 0 && j != 0){ 	//i == 0 e j == 0 é Beta1, que possui outro método para ser encontrado
			Beta[i] = (aux2 + aux3)/fabs(A[i][i]); 	//aux2 + aux3 é a soma dos Aij multiplicados por Beta ou não
			printf("Beta%d = %f\n", i + 1, Beta[i]);
			if(Beta[i] > Beta_max){
				Beta_max = Beta[i]; 	//Beta_max é o maior dos Betas
			}
		}
		//Garantia de que as variáveis da próxima iteração iniciarão com 0
		aux2 = 0;
		aux3 = 0;	
	} 	
//Critério de Sassenfeld
	if(Beta_max < 1){ 	//Se Beta_max < 1, o critério de Sassenfeld garante que o sistema converge!
		printf("----------------------\n");
		printf("Betamáx = %f < 1\n", Beta_max);
		printf("----------------------\n\n"); 
		printf("--------------------------------------------------------------\n");
		printf("Vale o critério de Sassenfeld e temos garantia de convergência\n");
		printf("--------------------------------------------------------------\n\n");
		printf("Informe as constantes das equações \n");
		B = (float *) malloc(n * sizeof(float)); 	//Aloca memória para o vetor de constantes
		for(k = 0; k < n; k++){ 	//Leitura dos dados do vetor B
			printf("Informe o coeficiente b%d: ", k + 1);
			scanf("%f", &B[k]);
		}
		
		x = (float *) malloc(n * sizeof(float)); 	//Aloca memória para o vetor de soluções
		aux = (float *) malloc(n * sizeof(float)); 	//Aloca memória para o vetor auxiliar
		printf("\n");
		for(j = 0; j < n; j++){
			printf("Informe um valor inicial para x%d: ", j + 1);
			scanf("%f", &x[j]);
			aux[j] = x[j]; 	//aux recebe os valores iniciais de x
		}
		
		printf("\nInforme a precisão: ");
		scanf("%f", &E);
		while(d_r > E){ 	
			printf("\nIteração %d\n", m++); 	//Quantidade de iterações
			for(i = 0; i < n; i++){ 	//Aqui começa o método
				for(j = 0; j < n; j++){
					if(i != j){
						soma += A[i][j]*x[j];
					}
				}	
				x[i] = (B[i] - soma)/A[i][i];
				printf("x%d = %.10f\n", i + 1, x[i]);	
				soma = 0;		
				
				dif = fabs(x[i] - aux[i]); 	//Maior valor da diferença x^(k + 1) - x^k 
				if(dif > max_d){
					max_d = dif; 	//max_d é o maior valor da diferença entre o x atual e o x anterior
				}
				if(x[i] > max_xi){ 	//Maior valor de x_i
					max_xi = x[i]; 	//max_xi é o maior valor das soluções do vetor x
				}
			} 	//Fim do método	
			
			d_r = 100*max_d/max_xi; 	//Cálculo do Erro
			printf("Precisão do loop: %.10f%%\n", d_r);
			
			for(i = 0; i < n; i++){ 	//Valores da iteração anterior
				aux[i] = x[i]; 	//aux recebe os valores da iteração anterior do vetor de soluções x
			}	
			
			//Garantia de que as variáveis da próxima iteração iniciarão com 0
			max_d = 0;
			max_xi = 0;
		} 	//Fim das iterações
		
		printf("\n--------\n");
		printf("Soluções");
		printf("\n--------\n");
		for(k = 0; k < n; k++){ 	
			printf("x%d = %.10f \n", k + 1, x[k]);
		}
		free(B); 	//Liberando memória do vetor B
		free(x); 	//Liberando memória do vetor x
	}
	else{
		printf("\n----------------------\n");
		printf("Beta_máx = %f > 1\n", Beta_max);
		printf("----------------------\n"); 
		printf("O sistema de equações, da forma que está, não converge para as soluções!\n");
	for(i = 0; i < n; i++){ 	//Liberando memória das linhas de A
		free(A[i]);
	}
	free(A); 	//Liberando memória das colunas de A	
}
}
