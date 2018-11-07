#include <stdio.h>
#include <math.h>
#include <locale.h>

int main(void){
	setlocale(LC_ALL, "Portuguese");
	int i = 1;
	float E = 0, x = 0, a = 0, y = 0, Ea = 999;
	float fx = 0; 	//Função de iteração
	
	printf("\t\t------------------------------------\n");
	printf("\t\tMétodo do Ponto Fixo - SMS Produções\n");
	printf("\t\t------------------------------------\n"); 
	printf("\t\tEquação: x² + x - 6 = 0\n\n");
	
	printf("Informe o chute inicial para a raiz da equação\n");
	printf("a: ");
	scanf("%f", &a);
	printf("Informe a precisão: ");
	scanf("%f", &E);

	x = sqrt(6 - a); 	//x = f(x0) 	[ x recebe o valor do chute inicial na função de iteração ]
	printf("x = %.10f\n", x);
	
	while(Ea > E){
		printf("\nIteração %d\n", i++);
	
		fx = sqrt(6 - x); 	//Calcula a função f(xi) 	// [ fx é a função de iteração ]
		printf("f(x) = %.10f\n", fx);
		
		y = x; 	//y recebe o valor de x na iteração anterior
		printf("x_velho = %f\n", y);
		x = fx; 	//valor de x na iteração atual
		printf("x_novo = %f\n", x);
		
		Ea = fabs(100*(x - y)/x); 	//Cálculo do Erro Relativo Aproximado
		printf("Precisão do loop: %.10f%% \n\n", Ea);				
	}
	
	//Mostra a raiz aproximada	
	printf("------------------------------------\n");
	printf("A raiz aproximada é: %.10f\n", x);
	printf("------------------------------------\n");
}
