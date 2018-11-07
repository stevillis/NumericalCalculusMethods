#include <stdio.h>
#include <math.h>
#include <locale.h>

int main(void){
	setlocale(LC_ALL, "Portuguese");
	int i = 1;
	float E = 0, x = 0, a = 0, y = 0, Ea = 999;
	float fx = 0;
	
	printf("\t\t------------------------------------\n");
	printf("\t\tMétodo do Ponto Fixo - SMS Produções\n");
	printf("\t\t------------------------------------\n"); 
	printf("\t\tEquação: e^(-x) - x = 0\n\n");
	
	//Leitura dos dados iniciais
	printf("Informe o chute inicial para a raiz da equação\n");
	printf("a: ");
	scanf("%f", &a);
	printf("Informe a precisão: ");
	scanf("%f", &E);
	
	x = exp(-a); 	//x = f(x0) 	[ O primeiro valor para a raiz é o valor do chute na função de iteração ]
	printf("x0 = %.10f\n", x);
	
	//Iteração do método [ Considerando a função de iteração e suas derivadas contínuas ]
	while(Ea > E){ 	//Enquanto o erro relativo aproximado for maior que o erro informado, continue a calcular
		printf("\nIteração %d\n", i++); 	//i conta as iterações
	
		fx =  exp(-x); 	//Calcula a função f(xi) 	[ fx é a função de iteração ] 	
		printf("f(x) = %.10f\n", fx);
		
		y = x; 	//y recebe o valor de x na iteração anterior
		printf("x_velho = %.10f\n", y);
		x = fx; 	//valor de x na iteração atual 	[ x_(k + 1) = phi(x_k) ]
		printf("x_novo = %.10f\n", x);
		
		Ea = fabs(100*(x - y)/x); 	//Cálculo do Erro Relativo Aproximado
		printf("Erro Relativo Aproximado: %.10f%% \n\n", Ea); 	//Mostra a precisão de cada loop
	}
	
	//Mostra a raiz aproximada	
	printf("------------------------------------\n");
	printf("A raiz aproximada é: %.10f\n", x);
	printf("------------------------------------\n");
}
