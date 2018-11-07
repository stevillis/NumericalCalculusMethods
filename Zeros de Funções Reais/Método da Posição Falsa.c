#include <stdio.h>
#include <math.h>
#include <locale.h>

int main(void){
	setlocale(LC_ALL, "Portuguese");
	int i = 1;
	float p = 0, q = 0, r = 0, s = 0; 	//Coeficientes da equação
	float E = 0, x = 0, a = 0, b = 0, y = 0, Ea = 999;
	float fx = 0, fa = 0, fb = 0; 	//Funções a serem calculadas
	
	printf("\t\t---------------------------------------\n");
	printf("\t\tMétodo da Falsa Posição - SMS Produções\n");
	printf("\t\t---------------------------------------\n"); 

	printf("Informe o coeficiente de x³: ");
	scanf("%f", &p);
	printf("Informe o coeficiente de x²: ");
	scanf("%f", &q);
	printf("Informe o coeficiente de x: ");
	scanf("%f", &r);
	printf("Informe o termo independente: ");
	scanf("%f", &s);
	printf("A função é: f(x) = %.2fx³ + %.2fx² + %.2fx + %.2f\n", p, q, r, s);	
	
	printf("\nInforme o intervalo que contém a raiz da equação\n");
	printf("a: ");
	scanf("%f", &a);
	printf("b: ");
	scanf("%f", &b);
	
	fa =  p*pow(a, 3) + q*pow(a, 2) + r*pow(a, 1) + s; 	//Cálculo para saber se o intervalo contém a raiz
	fb =  p*pow(b, 3) + q*pow(b, 2) + r*pow(b, 1) + s;
	
	if(fa*fb < 0){ 	//Se f(a)*f(b) < 0, então esse intervalo [a, b] contém a raiz
		printf("\nInforme a precisão: ");
		scanf("%f", &E);
		
		while(Ea > E){ 	//Enquanto o erro relativo aproximado for maior que o erro informado, continue a calcular
			printf("\nIteração %d\n", i++); 	//i conta as iterações
			
			fa = p*pow(a, 3) + q*pow(a, 2) + r*pow(a, 1) + s; 	//Calcula a função f(a)
			printf("f(a) = %.10f\n", fa);
			fb = p*pow(b, 3) + q*pow(b, 2) + r*pow(b, 1) + s; 	//Calcula a função f(b)
			printf("f(b) = %.10f\n", fb);
			
			x = (a*fb - b*fa)/(fb - fa); 	//Calcula a raiz aproximada que é a média ponderada do intervalo que contém a raiz
			printf("x = %.10f\n", x);
			
			fx =  p*pow(x, 3) + q*pow(x, 2) + r*pow(x, 1) + s; 	//Calcula a função f(x)
			if(fx*fa > 0){
				printf("Sinal de f(x)*f(a): + \n");
				a = x;
			}
			else{
				printf("Sinal de f(x)*f(a): - \n");
				b = x;
			}
			printf("a = %.10f \n", a);
			printf("b = %.10f \n", b);
			printf("x_n = %.10f\n", x); 	//x_novo
			printf("x_v = %.10f\n", y); 	//x_velho
			
			Ea = fabs(100*(x - y)/x);
			printf("Erro Relativo Aproximado: %.10f%% \n", Ea); 	//Mostra a precisão de cada loop							
			y = x; 	//y é usado como "x anterior"
		}
		printf("---------------------------------\n");
		printf("A raiz aproximada é: %.10f\n", x);
		printf("---------------------------------\n");
	}
	else
		printf("O intervalo não contém a raiz!\n");
}
