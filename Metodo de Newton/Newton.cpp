#include <stdio.h>
#include <stdlib.h>
#include<time.h>
#include<string.h>
#include <locale.h>
#include <math.h>
float funcao(float x){
	return x*x-9;
}
float derivada(float x){
	return ((funcao(x+0.001)-funcao(x))/0.001);
}

int main(void){
	float x0,x1,x2,c,erro;
	int k,cont=0;
	printf("Informe um valor inicial para x:");
	scanf("%f",&x0);
	printf("\nInforme o valor do erro:");
	scanf("%f",&erro);	
	printf("\nInforme o numero maximo de interacoes:");
	scanf("%d",&k);
	printf("\nK \t   Xk-1 \t\t  F(Xk-1) \t\t F'(Xk-1) \t\t Xk \n");
	printf("-------------------------------------------------------------------------------------------\n");
	while (fabs(funcao(x1))>erro){
	
	x1=x0-(funcao(x0)/derivada(x0));
	printf("%d \t %f \t\t %f \t\t %f \t\t %f\n",cont+1,x0,funcao(x0),derivada(x0),x1);	
	
	x0=x1;
	cont++;

	if(cont>=k){
		break;
	}		
}
	printf("\n--------------------------------");
	printf("\nNumero de Iteracoes:%d.\nRaiz:%f.\nF(%f)=%f.",cont,x1,x1,funcao(x1));		
	return 0;
}
