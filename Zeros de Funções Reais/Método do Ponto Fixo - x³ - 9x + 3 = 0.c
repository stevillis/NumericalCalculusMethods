#include <stdio.h>
#include <math.h>
#include <locale.h>

int main(void){
	setlocale(LC_ALL, "Portuguese");
	int i = 1;
	float E = 0, x = 0, y = 0, Ea = 999;
	float fx = 0; 	//Fun��o de itera��o
	
	printf("\t\t------------------------------------\n");
	printf("\t\tM�todo do Ponto Fixo - SMS Produ��es\n");
	printf("\t\t------------------------------------\n"); 
	printf("\t\tf(x) =  x� - 9x + 3\n\n");
	
	printf("Informe o chute inicial para a raiz da equa��o\n");
	printf("x0: ");
	scanf("%f", &x);
	printf("\nInforme a precis�o: ");
	scanf("%f", &E);
	
	while(Ea > E){
		printf("\nItera��o %d\n", i++);
	
		fx = (pow(x, 3))/9 + 0.333333333; 	//Calcula a fun��o f(xi) 	// [ fx � a fun��o de itera��o ]
		printf("phi(x%d) = %.10f\n", i - 2, fx);
		
		x = fx; 	//valor de x na itera��o atual
		printf("x_n = %.10f\n", x);
		printf("x_v = %.10f\n", y);
		
		Ea = fabs(100*(x - y)/x); 	//C�lculo do Erro Relativo Aproximado
		printf("Precis�o do loop: %.10f%% \n", Ea);				
		y = x; 	//y recebe o valor de x na itera��o anterior
	}
	printf("------------------------------------\n");
	printf("A raiz aproximada �: %.10f\n", x);
	printf("------------------------------------\n");
}
