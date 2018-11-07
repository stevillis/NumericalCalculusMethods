#include <stdio.h>
#include <conio.h>
#include <math.h>
#include <locale.h>

/* Ra�zes: -318.684, 328.151 */

int main(void){
	setlocale(LC_ALL, "Portuguese");
	int i = 1; 	//Contador de itera��o
	float E = 0, R = 0, a = 0, b = 0, y = 0, Ea = 1;
	float f_R = 0, raizR = 0, f_a = 0, raizA = 0, f_b = 0, raizB = 0;
	
	printf("\t\t-------------------------------\n");
	printf("\t\tM�todo da Bissec��o: - SMS Ltda\n"); 	//Mensagem de apresenta��o do m�todo
	printf("\t\t-------------------------------\n"); 
	printf("Determinar o valor de R que satisfa�a f(R) = 0, onde \n");
	printf("f(R) = ( e^(-0.005*R) ) * ( cos( 0.05*sqrt(2000 - 0.01*R�)) ) - 0.01\n");
	printf("As ra�zes s�o: -318.684 e 328.151\n\n");
	
	printf("Informe o intervalo que cont�m a raiz da equa��o \n");
	printf("a: ");
	scanf("%f", &a); 	//Leitura do limite inferior
	printf("b: ");
	scanf("%f", &b); 	//Leitura do limite superior
	
	raizA = sqrt(2000 - 0.01*( pow(a, 2) ) ); 	//Calcula o valor da raiz quadrada em a
	f_a = ( 1/exp(0.005*a) ) * (cos(raizA*0.05)) - 0.01; 	//Calcula o valor da fun��o em a
	
	raizB = sqrt(2000 - 0.01*( pow(b, 2) ) ); 	//Calcula o valor da raiz quadrada em b
	f_b = ( 1/exp(0.005*b) ) * (cos(raizB*0.05)) - 0.01; 	//Calcula o valor da fun��o em b
	
	if(f_a*f_b < 0){ 	//Se f(a)*f(b) < 0, ent�o esse o intervalo [a, b] cont�m a raiz
		printf("Informe a precis�o: ");
		scanf("%f", &E); 	//Leitura da precis�o
		while(Ea > E){
			printf("\nItera��o %d \n", i++); 	//Mostra o n�mero da itera��o
			R = (a + b)/2; 	//Calcula a m�dia dos limites
			printf("R = %.10f \n", R); 	//Mostra o valor de R na itera��o
			Ea = fabs( (R - y)/R )*100; 	//Calcula o Erro Relativo Percentual Aproximado
			y = R; 	//y � o valor de R na itera��o anterior
			printf("Erro Relativo Percentual: %.30f%% \n", Ea); 	//Mostra o valor do Erro Relativo Percentual Aproximado
			
				raizR = sqrt(2000 - 0.01*( pow(R, 2) ) ); 	//Calcula o valor da raiz quadrada em R 	
				f_R = ( 1/exp(0.005*R) ) * (cos(raizR*0.05)) - 0.01; 	//Calcula o valor valor da fun��o em R
				printf("f(R) = %.10f \n", f_R); 	//Mostra o valor de f(R)
			
				raizA = sqrt(2000 - 0.01*( pow(a, 2) ) ); 	//Calcula o valor da raiz quadrada em a
				f_a = ( 1/exp(0.005*a) ) * (cos(raizA*0.05)) - 0.01; 	//Calcula o valor da fun��o em a
				printf("f(a) = %.10f \n", f_a); 	//Mostra o valor de f(a)
		
			if(f_R*f_a > 0){
				printf("Sinal de f(x)*f(a) �: + \n");
				a = R; 	//Se f(R)*(f(a) > 0, a raiz est� mais pr�xima ao limite superior
			}
			else{
				printf("Sinal de f(R)*f(a) �: - \n");
				b = R; 	//Se f(R)*f(a) < 0, a raiz est� mais pr�xima ao limite superior
			}
			printf("a = %.10f \n", a); 	//Mostra o limite inferior
			printf("b = %.10f \n", b); 	//Mostra o limite superior
			
			printf("R velho = %.10f\n", y); 	//Mostra o valor de R velho
			printf("R novo = %.10f\n", R); 	//Mostra o valor de R novo
		};

	printf("--------------------------------------\n");
	printf("A raiz aproximada �: %.10f\n", R); 	//Mostra a raiz aproximada
	printf("--------------------------------------\n");
	}
	else
		printf("O intervalo n�o cont�m a raiz!\n");
		
	getch();
	printf("\n\nO que te fazia rir, hoje j� n�o tem mais gra�a!");
	getch();
}
