#include <stdio.h>
#include <math.h>
#include <locale.h>

int main(void){
	setlocale(LC_ALL, "Portuguese");
	int i = 1;
	float E = 0, x = 0, a = 0, y = 0, Ea = 999;
	float fx = 0;
	
	printf("\t\t------------------------------------\n");
	printf("\t\tM�todo do Ponto Fixo - SMS Produ��es\n");
	printf("\t\t------------------------------------\n"); 
	printf("\t\tEqua��o: e^(-x) - x = 0\n\n");
	
	//Leitura dos dados iniciais
	printf("Informe o chute inicial para a raiz da equa��o\n");
	printf("a: ");
	scanf("%f", &a);
	printf("Informe a precis�o: ");
	scanf("%f", &E);
	
	x = exp(-a); 	//x = f(x0) 	[ O primeiro valor para a raiz � o valor do chute na fun��o de itera��o ]
	printf("x0 = %.10f\n", x);
	
	//Itera��o do m�todo [ Considerando a fun��o de itera��o e suas derivadas cont�nuas ]
	while(Ea > E){ 	//Enquanto o erro relativo aproximado for maior que o erro informado, continue a calcular
		printf("\nItera��o %d\n", i++); 	//i conta as itera��es
	
		fx =  exp(-x); 	//Calcula a fun��o f(xi) 	[ fx � a fun��o de itera��o ] 	
		printf("f(x) = %.10f\n", fx);
		
		y = x; 	//y recebe o valor de x na itera��o anterior
		printf("x_velho = %.10f\n", y);
		x = fx; 	//valor de x na itera��o atual 	[ x_(k + 1) = phi(x_k) ]
		printf("x_novo = %.10f\n", x);
		
		Ea = fabs(100*(x - y)/x); 	//C�lculo do Erro Relativo Aproximado
		printf("Erro Relativo Aproximado: %.10f%% \n\n", Ea); 	//Mostra a precis�o de cada loop
	}
	
	//Mostra a raiz aproximada	
	printf("------------------------------------\n");
	printf("A raiz aproximada �: %.10f\n", x);
	printf("------------------------------------\n");
}
