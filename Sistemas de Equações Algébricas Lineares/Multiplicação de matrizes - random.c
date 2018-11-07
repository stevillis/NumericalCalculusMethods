#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <time.h>

int main(void){
	setlocale(LC_ALL, "Portuguese");
	srand((unsigned) time(NULL));
	
	int i, j, k, n;
	int ai, aj, bi, bj, ci, cj;
	int **A, **B, **C; 	// A, B e C s�o matrizes de duas dimens�es
	
	printf("Informe a quantidade de linhas da matriz A:");
	scanf("%d", &ai);
	//Cria um array de ponteiros (int *)
	A = (int **) malloc(ai * sizeof(int *)); 	//Aqui cria-se uma coluna de ponteiros para ponteiros de inteiros
	printf("Informe a quantidade de colunas da matriz A:");
	scanf("%d", &aj);
	//Cria um array de int
	for(i = 0; i < ai; i++){
		A[i] = (int *) malloc(aj * sizeof(int));
	}
	//Leitura dos dados da matriz A
	for(i = 0; i < ai; i++){
		for(j = 0; j < aj; j++){
			A[i][j] = rand()%3;
			printf("%d ", A[i][j]);
		}
		printf("\n");
	}	
	
	printf("\nInforme a quantidade de linhas da matriz B:");
	scanf("%d", &bi);
	//Cria um array de ponteiros (int *)
	B = (int **) malloc(bi * sizeof(int *)); 	//Aqui cria-se uma coluna de ponteiros para ponteiros de inteiros
	printf("Informe a quantidade de colunas da matriz:");
	scanf("%d", &bj);
	//Cria um array de int
	for(i = 0; i < bi; i++){
		B[i] = (int *) malloc(bj * sizeof(int));
	}
	//Leitura dos dados da matriz B
	for(i = 0; i < bi; i++){
		for(j = 0; j < bj; j++){
			B[i][j] = rand()%2;
			printf("%d ", B[i][j]);
		}
		printf("\n");
	}	
	
	if(aj == bi){ 	//Se num de colunas da 1� for igual ao num de linhas da 2�
		n = aj; 	//n ser� o limite do la�o de itera��o
		
		//Cria um array de ponteiros (int *)
		C = (int **) malloc(ai * sizeof(int *)); 	//Aqui cria-se uma coluna de ponteiros para ponteiros de inteiros
		//Cria um array de int
		for(i = 0; i < ai; i++){
			C[i] = (int *) malloc(bj * sizeof(int));
		}
		//Multiplica��o das matrizes A e B
		printf("\nC = A*B\n");
		for(i = 0; i < ai; i++){
			for(j = 0; j < bj; j++){
				//La�o para multiplica��o dos elementos das matrizes
				for(k = 0; k < n; k++){
					C[i][j] += A[i][k]*B[k][j];	
				}
			printf("%d ", C[i][j]);
			}
			printf("\n");
		}
	}
	else{
		printf("\nN�o � poss�vel multiplicar as matrizes\n");
	}
	
	//Liberando mem�ria das linhas de A
	for(i = 0; i < ai; i++){
		free(A[i]);
	}
	//Liberando mem�ria das colunas de A
	free(A);
	
	//Liberando mem�ria das linhas de B
	for(i = 0; i < bi; i++){
		free(B[i]);
	}
	//Liberando mem�ria das colunas de B
	free(B);
	
	//Liberando mem�ria das linhas de C
	for(i = 0; i < ai; i++){
		free(C[i]);
	}
	//Liberando mem�ria das colunas de C
	free(C);
}
