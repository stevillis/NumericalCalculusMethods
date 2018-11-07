#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main(void){
	setlocale(LC_ALL, "Portuguese");
	int i, j, k, n, a, b;
	float m, s;
	float **A; 	//Matriz das equações Ax = B
	float *B; 	//Vetor de soluções Ax = B
	float *x; 	//Vetor de soluções do sistema [ x = x_1, x_2,...,x_n ]
	
	printf("\t\t---------------------------------------------\n");
	printf("\t\tMétodo da Eliminação de Gauss - SMS Produções\n");
	printf("\t\t---------------------------------------------\n\n"); 
	printf("Informe a dimensão do sistema de equações: "); 	//Quantidade de linhas
	scanf("%d", &n);
	
	printf("\nInforme os coeficientes das equações\n");
	A = (float **) malloc(n * sizeof(float *)); 	//Cria uma coluna de ponteiros para ponteiros de float	
	for(i = 0; i < n; i++){ 	//Cria um array de float
		A[i] = (float *) malloc(n * sizeof(float));
	}
	for(i = 0; i < n; i++){ 	//Leitura dos dados da matriz A
		for(j = 0; j < n; j++){
			printf("Informe o coeficiente a%d%d: ", i + 1, j + 1);
			scanf("%f", &A[i][j]);
		}
	}	
	
	printf("\nInforme as constantes das equações \n");
	B = (float *) malloc(n * sizeof(float)); 	//Aloca memória para o vetor de constantes
	for(k = 0; k < n; k++){ 	//Leitura dos dados do vetor de constantes B
		printf("Informe o coeficiente b%d: ", k + 1);
		scanf("%f", &B[k]);
	}

//Eliminação	
	x = (float *) malloc(n * sizeof(float)); 	//Aloca memória para o vetor de soluções
	printf("\nMatriz triangular superior: \n");
	for(k = 0; k < n - 1; k++){
		for(i = k + 1; i < n; i++){
			m = A[i][k]/A[k][k]; 	//m a ser multiplicado
			for(j = k + 1; j < n; j++){
				A[i][j] -= m * A[k][j]; 	//A_(ij) recebe ele mesmo menos m*A_(kj)
			}
			B[i] -= m* B[k]; 	//B_i recebe ele mesmo menos m*B_k 
			A[i][k] = 0; 	//Zera os elementos abaixo da diagonal principal
			
			for(a = 0; a < n; a++){ 	//Mostra os elementos da matriz A e do vetor B
				for(b = 0; b < n; b++){	
					printf("%.2f ", A[a][b]) ; 	//Índices a e b são para evitar conflito com os índices i e j
				}
				printf ("%.2f\n", B[a]);
			}
			printf("\n");
		}
	} 	
//Eliminação
//Resolução do Sistema
	x[n - 1] = B[n - 1]/A[n - 1][n - 1]; 	//Substituição regressiva do último valor de x
	for(k = n - 2; k >= 0; k--){ 	//Substituição regressiva das outras soluções
		s = 0;
		for(j = k + 1 ; j < n; j++){
			s += A[k][j]*x[j]; 	//Soma dos termos isolados de x_k
		}
		x[k] = (B[k] - s)/A[k][k]; 	//Valores de x(k)
	}
//Resolução do Sistema
	printf("Soluções: \n");
	for(k = 0; k < n; k++){ 	
		printf("x%d = %.2f \n", k + 1, x[k]);
	}
	
	for(i = 0; i < n; i++){ 	//Liberando memória das linhas de A
		free(A[i]);
	}
	free(A); 	//Liberando memória das colunas de A
	free(B); 	//Liberando memória do vetor B
	free(x); 	//Liberando memória do vetor x
}
