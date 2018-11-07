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
	printf("\t\tM�todo de Gauss-Seidel - SMS Produ��es\n");
	printf("\t\t--------------------------------------\n\n"); 	
	printf("Informe a dimens�o do sistema de equa��es: "); 	
	scanf("%d", &n); 	//Quantidade de linhas
	A = (float **) malloc(n * sizeof(float *)); 	//Cria uma coluna de ponteiros para ponteiros de float	
	for(i = 0; i < n; i++){ 	//Cria um array de float
		A[i] = (float *) malloc(n * sizeof(float));
	}
	
	printf("\nInforme os coeficientes das equa��es\n"); 	////Leitura dos dados da matriz A
	for(i = 0; i < n; i++){
		for(j = 0; j < n; j++){
			printf("Informe o coeficiente a%d%d: ", i + 1, j + 1);
			scanf("%f", &A[i][j]);
		}
	}	
	
//Crit�rio de Sassenfeld	
	Beta = (float *) malloc(n * sizeof(float)); 	//Aloca mem�ria para o vetor Beta		
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
				aux2 += fabs(A[i][j])*Beta[j]; 	//Soma das multiplica��es de Aij com Beta
			}
			if(i != j && i < j){
				aux3 += fabs(A[i][j]); 	//Soma dos termos Aij que n�o multiplicam Beta
			}
		}
		if(i != 0 && j != 0){ 	//i == 0 e j == 0 � Beta1, que possui outro m�todo para ser encontrado
			Beta[i] = (aux2 + aux3)/fabs(A[i][i]); 	//aux2 + aux3 � a soma dos Aij multiplicados por Beta ou n�o
			printf("Beta%d = %f\n", i + 1, Beta[i]);
			if(Beta[i] > Beta_max){
				Beta_max = Beta[i]; 	//Beta_max � o maior dos Betas
			}
		}
		//Garantia de que as vari�veis da pr�xima itera��o iniciar�o com 0
		aux2 = 0;
		aux3 = 0;	
	} 	
//Crit�rio de Sassenfeld
	if(Beta_max < 1){ 	//Se Beta_max < 1, o crit�rio de Sassenfeld garante que o sistema converge!
		printf("----------------------\n");
		printf("Betam�x = %f < 1\n", Beta_max);
		printf("----------------------\n\n"); 
		printf("--------------------------------------------------------------\n");
		printf("Vale o crit�rio de Sassenfeld e temos garantia de converg�ncia\n");
		printf("--------------------------------------------------------------\n\n");
		printf("Informe as constantes das equa��es \n");
		B = (float *) malloc(n * sizeof(float)); 	//Aloca mem�ria para o vetor de constantes
		for(k = 0; k < n; k++){ 	//Leitura dos dados do vetor B
			printf("Informe o coeficiente b%d: ", k + 1);
			scanf("%f", &B[k]);
		}
		
		x = (float *) malloc(n * sizeof(float)); 	//Aloca mem�ria para o vetor de solu��es
		aux = (float *) malloc(n * sizeof(float)); 	//Aloca mem�ria para o vetor auxiliar
		printf("\n");
		for(j = 0; j < n; j++){
			printf("Informe um valor inicial para x%d: ", j + 1);
			scanf("%f", &x[j]);
			aux[j] = x[j]; 	//aux recebe os valores iniciais de x
		}
		
		printf("\nInforme a precis�o: ");
		scanf("%f", &E);
		while(d_r > E){ 	
			printf("\nItera��o %d\n", m++); 	//Quantidade de itera��es
			for(i = 0; i < n; i++){ 	//Aqui come�a o m�todo
				for(j = 0; j < n; j++){
					if(i != j){
						soma += A[i][j]*x[j];
					}
				}	
				x[i] = (B[i] - soma)/A[i][i];
				printf("x%d = %.10f\n", i + 1, x[i]);	
				soma = 0;		
				
				dif = fabs(x[i] - aux[i]); 	//Maior valor da diferen�a x^(k + 1) - x^k 
				if(dif > max_d){
					max_d = dif; 	//max_d � o maior valor da diferen�a entre o x atual e o x anterior
				}
				if(x[i] > max_xi){ 	//Maior valor de x_i
					max_xi = x[i]; 	//max_xi � o maior valor das solu��es do vetor x
				}
			} 	//Fim do m�todo	
			
			d_r = 100*max_d/max_xi; 	//C�lculo do Erro
			printf("Precis�o do loop: %.10f%%\n", d_r);
			
			for(i = 0; i < n; i++){ 	//Valores da itera��o anterior
				aux[i] = x[i]; 	//aux recebe os valores da itera��o anterior do vetor de solu��es x
			}	
			
			//Garantia de que as vari�veis da pr�xima itera��o iniciar�o com 0
			max_d = 0;
			max_xi = 0;
		} 	//Fim das itera��es
		
		printf("\n--------\n");
		printf("Solu��es");
		printf("\n--------\n");
		for(k = 0; k < n; k++){ 	
			printf("x%d = %.10f \n", k + 1, x[k]);
		}
		free(B); 	//Liberando mem�ria do vetor B
		free(x); 	//Liberando mem�ria do vetor x
	}
	else{
		printf("\n----------------------\n");
		printf("Beta_m�x = %f > 1\n", Beta_max);
		printf("----------------------\n"); 
		printf("O sistema de equa��es, da forma que est�, n�o converge para as solu��es!\n");
	for(i = 0; i < n; i++){ 	//Liberando mem�ria das linhas de A
		free(A[i]);
	}
	free(A); 	//Liberando mem�ria das colunas de A	
}
}
