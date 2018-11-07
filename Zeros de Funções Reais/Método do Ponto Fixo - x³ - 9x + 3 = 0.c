#include <stdio.h>
#include <math.h>
#include <locale.h>

int main(void){
	setlocale(LC_ALL, "Portuguese");
	int i = 1;
	float E = 0, x = 0, y = 0, Ea = 999;
	float fx = 0; 	//Função de iteração
	
	printf("\t\t------------------------------------\n");
	printf("\t\tMétodo do Ponto Fixo - SMS Produções\n");
	printf("\t\t------------------------------------\n"); 
	printf("\t\tf(x) =  x³ - 9x + 3\n\n");
	
	printf("Informe o chute inicial para a raiz da equação\n");
	printf("x0: ");
	scanf("%f", &x);
	printf("\nInforme a precisão: ");
	scanf("%f", &E);
	
	while(Ea > E){
		printf("\nIteração %d\n", i++);
	
		fx = (pow(x, 3))/9 + 0.333333333; 	//Calcula a função f(xi) 	// [ fx é a função de iteração ]
		printf("phi(x%d) = %.10f\n", i - 2, fx);
		
		x = fx; 	//valor de x na iteração atual
		printf("x_n = %.10f\n", x);
		printf("x_v = %.10f\n", y);
		
		Ea = fabs(100*(x - y)/x); 	//Cálculo do Erro Relativo Aproximado
		printf("Precisão do loop: %.10f%% \n", Ea);				
		y = x; 	//y recebe o valor de x na iteração anterior
	}
	printf("------------------------------------\n");
	printf("A raiz aproximada é: %.10f\n", x);
	printf("------------------------------------\n");
}
