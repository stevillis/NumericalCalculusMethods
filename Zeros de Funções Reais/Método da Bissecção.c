#include <stdio.h>
#include <math.h>
#include <locale.h>

int main(void){
	setlocale(LC_ALL, "Portuguese");
	int i = 1;
	float p = 0, q = 0, r = 0, s = 0; 	//p, q, r e s s�o os coeficientes da equa��o
	float E = 0, x = 0, a = 0, b = 0, y = 0, Ea = 999; 
	float f_x = 0, f_a = 0, f_b = 0; 	//Fun��es a serem calculadas
	
	printf("\t\t-----------------------------------\n");
	printf("\t\tM�todo da Bissec��o - SMS Produ��es\n");
	printf("\t\t-----------------------------------\n"); 
	
	printf("Informe o coeficiente de x�: ");
	scanf("%f", &p);
	printf("Informe o coeficiente de x�: ");
	scanf("%f", &q);
	printf("Informe o coeficiente de x: ");
	scanf("%f", &r);
	printf("Informe o termo independente: ");
	scanf("%f", &s);
	printf("A fun��o �: f(x) = %.2fx� + %.2fx� + %.2fx + %.2f\n", p, q, r, s);	
	
	printf("\nInforme o intervalo que cont�m a raiz da equa��o\n");
	printf("a: ");
	scanf("%f", &a);
	printf("b: ");
	scanf("%f", &b);
	f_a =  p*pow(a, 3) + q*pow(a, 2) + r*pow(a, 1) + s; 	//C�lculo para saber se o intervalo cont�m a raiz
	f_b =  p*pow(b, 3) + q*pow(b, 2) + r*pow(b, 1) + s;
	
	if(f_a*f_b < 0){ 	//Se f(a)*f(b) < 0, ent�o esse intervalo [a, b] cont�m a raiz
		printf("\nInforme a precis�o: ");
		scanf("%f", &E);	
		while(Ea > E){ 	//Enquanto o erro relativo aproximado for maior que o erro informado, continue a calcular
			printf("\nItera��o %d \n", i++); 	//i conta o n�mero de itera��es
			
			f_a = p*pow(a, 3) + q*pow(a, 2) + r*pow(a, 1) + s; 	//Calcula a fun��o f(a)
			printf("f(a) = %.10f \n", f_a);
			
			x = (a + b)/2; 	//A raiz � a m�dia do intervalo que cont�m a raiz
			printf("x = %.10f \n", x);
			
			f_x =  p*pow(x, 3) + q*pow(x, 2) + r*pow(x, 1) + s; 	//Calcula a fun��o f(x)
			printf("f(x) = %.10f \n", f_x);
			if(f_x*f_a > 0){ 	//Se f(x)*f(a) > 0, o limite inferior passa a ser x
				printf("Sinal de f(x)*f(a): + \n");
				a = x;
			}
			else{ 	//Se f(x)*f(a) < 0, o limite superior passa a ser x
				printf("Sinal de f(x)*f(a): - \n");
				b = x;
			}
			printf("a = %.10f \n", a);
			printf("b = %.10f \n", b);
			printf("x_n = %.10f\n", x); 	//x_novo
			printf("x_v = %.10f\n", y); 	//x_velho
			
			Ea = fabs(100*(x - y)/x); 	//C�lculo do Erro Ea = | (x_n - x_v)/x_n |
			printf("Erro Relativo Aproximado: %.10f%% \n", Ea); 	//Mostra a precis�o de cada loop	
			y = x; 	//y � usado como "x anterior"
		}
		printf("---------------------------------\n");
		printf("A raiz aproximada �: %.10f\n", x);
		printf("---------------------------------\n");
	}
	else
		printf("O intervalo n�o cont�m a raiz!\n");	
}
