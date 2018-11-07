#include <stdio.h>
#include <math.h>
#include <locale.h>

float erro(float n, float v);

int main(void){
	setlocale(LC_ALL, "Portuguese");
	int i = 1; 	//i é apenas um contador
	float p = 0, q = 0, r = 0, s = 0; 	//Variáveis do polinômio
	float E = 0, x = 0, a = 0, b = 0, y = 0, Ea = 1;
	float fx = 0, fa = 0, fb = 0, xi = 0, aux1 = 0, aux2 = 0;
	
	printf("\t\t---------------------------------\n");
	printf("\t\tMétodo da Secante - SMS Produções\n");
	printf("\t\t---------------------------------\n"); 
	
	//Leitura dos coeficientes da equação
	printf("Informe o coeficiente de x³: ");
	scanf("%f", &p);
	printf("Informe o coeficiente de x²: ");
	scanf("%f", &q);
	printf("Informe o coeficiente de x: ");
	scanf("%f", &r);
	printf("Informe o termo independente: ");
	scanf("%f", &s);
	printf("A função é: f(x) = %.2fx³ + %.2fx² + %.2fx + %.2f\n", p, q, r, s);	
	
	//Leitura dos dados iniciais
	printf("Informe o chute inferior x0: ");
	scanf("%f", &a);
	printf("Informe o chute superior x1: ");
	scanf("%f", &b);
	printf("Informe a precisão: ");
	scanf("%f", &E);
		
	while(fabs(Ea) > E){
		printf("\nIteração %d\n", i++);
	
		fa =  p*pow(a, 3) + q*pow(a, 2) + r*pow(a, 1) + s; 	//Calcula f(xi)
		printf("f(x%d) = %f\n", i - 2, fa);
		fb = p*pow(b, 3) + q*pow(b, 2) + r*pow(b, 1) + s; 	//Calcula f(x + 1)
		printf("f(x%d) = %f\n", i - 1, fb);
	
		aux1 = fb*b - fb*a;
		aux2 = fb - fa;
		x = b - aux1/aux2; 	//Calcula a raiz aproximada
		printf("x%d = %f\n", i, x);
	
		//Mostra a precisão de cada loop			
		Ea = erro(x, y);
		printf("Precisão do loop: %.10f \n\n", Ea);				
		y = x; 	//y recebe o "x anterior"
		
		a = b; 	//x0 recebe x1
		b = x; 	//x1 recebe x2		
	}

	//Mostra a raiz aproximada	
	printf("------------------------------------\n");
	printf("A raiz aproximada é: %.10f\n", x);
	printf("------------------------------------\n");		
}

//Erro Relativo Aproximado
float erro(float n, float v){
	float Ea = 0;

	printf("x_velho = %f\n", v);
	printf("x_novo = %f\n", n);
	Ea = (n - v)/n;
	return Ea;	
}
