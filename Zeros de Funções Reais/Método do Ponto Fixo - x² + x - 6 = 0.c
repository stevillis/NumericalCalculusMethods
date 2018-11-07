#include <stdio.h>
#include <math.h>
#include <locale.h>

int main(void){
	setlocale(LC_ALL, "Portuguese");
	int i = 1;
	float E = 0, x = 0, a = 0, y = 0, Ea = 999;
	float fx = 0; 	//Fun��o de itera��o
	
	printf("\t\t------------------------------------\n");
	printf("\t\tM�todo do Ponto Fixo - SMS Produ��es\n");
	printf("\t\t------------------------------------\n"); 
	printf("\t\tEqua��o: x� + x - 6 = 0\n\n");
	
	printf("Informe o chute inicial para a raiz da equa��o\n");
	printf("a: ");
	scanf("%f", &a);
	printf("Informe a precis�o: ");
	scanf("%f", &E);

	x = sqrt(6 - a); 	//x = f(x0) 	[ x recebe o valor do chute inicial na fun��o de itera��o ]
	printf("x = %.10f\n", x);
	
	while(Ea > E){
		printf("\nItera��o %d\n", i++);
	
		fx = sqrt(6 - x); 	//Calcula a fun��o f(xi) 	// [ fx � a fun��o de itera��o ]
		printf("f(x) = %.10f\n", fx);
		
		y = x; 	//y recebe o valor de x na itera��o anterior
		printf("x_velho = %f\n", y);
		x = fx; 	//valor de x na itera��o atual
		printf("x_novo = %f\n", x);
		
		Ea = fabs(100*(x - y)/x); 	//C�lculo do Erro Relativo Aproximado
		printf("Precis�o do loop: %.10f%% \n\n", Ea);				
	}
	
	//Mostra a raiz aproximada	
	printf("------------------------------------\n");
	printf("A raiz aproximada �: %.10f\n", x);
	printf("------------------------------------\n");
}
