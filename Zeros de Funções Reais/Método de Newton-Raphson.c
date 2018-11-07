#include <stdio.h>
#include <math.h>
#include <locale.h>

int main(void){
	setlocale(LC_ALL, "Portuguese");
	int i = 1;
	float p = 0, q = 0, r = 0, s = 0; 	//Coeficientes da equação
	float E = 0, x = 0, y = 0, Ea = 999;
	float fx = 0, fa = 0; 	//fa é a função f(x) e fx é a função f'(x)

	printf("\t\t----------------------------------------\n");
	printf("\t\tMétodo de Newton-Raphson - SMS Produções\n");
	printf("\t\t----------------------------------------\n");

	printf("Informe o coeficiente de x³: ");
	scanf("%f", &p);
	printf("Informe o coeficiente de x²: ");
	scanf("%f", &q);
	printf("Informe o coeficiente de x: ");
	scanf("%f", &r);
	printf("Informe o termo independente: ");
	scanf("%f", &s);
	printf("A função é: f(x) = %.2fx³ + %.2fx² + %.2fx + %.2f\n", p, q, r, s);

	printf("Informe o chute inicial para a raiz da equação\n");
	printf("x0: ");
	scanf("%f", &x);
	while( (3*p*pow(x, 2) + 2*q*pow(x, 1) + r) == 0){ 	//Evita divisão por zero
		printf("Escolha outro valor para o chute inicial!\n");
		printf("x0: ");
		scanf("%f", &x);
	}
	printf("\nInforme a precisão: ");
	scanf("%f", &E);

	while(Ea > E){ 	//Supondo as derivadas primeira e segunda da função contínuas
		printf("\nIteração %d\n", i++); 	//i conta o número de iterações

		fa =  p*pow(x, 3) + q*pow(x, 2) + r*pow(x, 1) + s; 	//Calcula f(x_k)
		printf("f(x%d) = %.10f\n", i  - 2, fa);

		fx = 3*p*pow(x, 2) + 2*q*pow(x, 1) + r; 	//Derivada da função no ponto x_k
		printf("f'(x%d) = %.10f\n", i - 2, fx);

		x = x - fa/fx; 	//Calcula a raiz aproximada x_(k + 1)
		printf("x%d = %.10f\n", i - 1, x);

		printf("x_n = %.10f\n", x);
		printf("x_v = %.10f\n", y);

		Ea = fabs(100*(x - y)/x); 	//Cálculo do Erro Relativo Aproximado
		printf("Erro Relativo Aproximado: %.10f%% \n", Ea); 	//Mostra a precisão de cada loop
		y = x; 	//y recebe o "x anterior"
	}
	printf("------------------------------------\n");
	printf("A raiz aproximada é: %.15f\n", x); 		//Mostra a raiz aproximada
	printf("------------------------------------\n");
}
