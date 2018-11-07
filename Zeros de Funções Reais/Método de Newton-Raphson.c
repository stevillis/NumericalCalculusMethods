#include <stdio.h>
#include <math.h>
#include <locale.h>

int main(void){
	setlocale(LC_ALL, "Portuguese");
	int i = 1;
	float p = 0, q = 0, r = 0, s = 0; 	//Coeficientes da equa��o
	float E = 0, x = 0, y = 0, Ea = 999;
	float fx = 0, fa = 0; 	//fa � a fun��o f(x) e fx � a fun��o f'(x)

	printf("\t\t----------------------------------------\n");
	printf("\t\tM�todo de Newton-Raphson - SMS Produ��es\n");
	printf("\t\t----------------------------------------\n");

	printf("Informe o coeficiente de x�: ");
	scanf("%f", &p);
	printf("Informe o coeficiente de x�: ");
	scanf("%f", &q);
	printf("Informe o coeficiente de x: ");
	scanf("%f", &r);
	printf("Informe o termo independente: ");
	scanf("%f", &s);
	printf("A fun��o �: f(x) = %.2fx� + %.2fx� + %.2fx + %.2f\n", p, q, r, s);

	printf("Informe o chute inicial para a raiz da equa��o\n");
	printf("x0: ");
	scanf("%f", &x);
	while( (3*p*pow(x, 2) + 2*q*pow(x, 1) + r) == 0){ 	//Evita divis�o por zero
		printf("Escolha outro valor para o chute inicial!\n");
		printf("x0: ");
		scanf("%f", &x);
	}
	printf("\nInforme a precis�o: ");
	scanf("%f", &E);

	while(Ea > E){ 	//Supondo as derivadas primeira e segunda da fun��o cont�nuas
		printf("\nItera��o %d\n", i++); 	//i conta o n�mero de itera��es

		fa =  p*pow(x, 3) + q*pow(x, 2) + r*pow(x, 1) + s; 	//Calcula f(x_k)
		printf("f(x%d) = %.10f\n", i  - 2, fa);

		fx = 3*p*pow(x, 2) + 2*q*pow(x, 1) + r; 	//Derivada da fun��o no ponto x_k
		printf("f'(x%d) = %.10f\n", i - 2, fx);

		x = x - fa/fx; 	//Calcula a raiz aproximada x_(k + 1)
		printf("x%d = %.10f\n", i - 1, x);

		printf("x_n = %.10f\n", x);
		printf("x_v = %.10f\n", y);

		Ea = fabs(100*(x - y)/x); 	//C�lculo do Erro Relativo Aproximado
		printf("Erro Relativo Aproximado: %.10f%% \n", Ea); 	//Mostra a precis�o de cada loop
		y = x; 	//y recebe o "x anterior"
	}
	printf("------------------------------------\n");
	printf("A raiz aproximada �: %.15f\n", x); 		//Mostra a raiz aproximada
	printf("------------------------------------\n");
}
