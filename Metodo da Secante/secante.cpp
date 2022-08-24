#include <stdio.h>
#include <stdlib.h>
#include<time.h>
#include<string.h>
#include <locale.h>
#include <math.h>
float funcao(float x){

	return x*x-6;
}
int main(void){
	
	float x0,x1,x2,c,erro;
	int Ni,cont;
	
	printf("Informe um valor para 'a' no intervalo [a,b]:");
	scanf("%f",&x0);
	printf("\nInforme um valor para 'b' no intervalo [a,b]:");
	scanf("%f",&x1);
	printf("\nInforme o valor do erro:");
	scanf("%f",&erro);	
	printf("\nInforme o numero maximo de interacoes:");
	scanf("%d",&Ni);
	c=x1-x0;
	printf("\nK \t   x0 \t\t        F(x0) \t\t      x1 \t\t F(x1) \t\t     x2 \t\t F(x2)\n");
	printf("--------------------------------------------------------------------------------------------------------------------------------\n");
	
	while (fabs(funcao(x2))>erro)
	{
	
	x2=x1 - funcao(x1)*((x1-x0)/(funcao(x1)-funcao(x0)));
	printf("%d \t| %f \t| F(%.2f) = %.4f \t| %f \t| F(%.2f) = %.4f \t| %f \t| F(%f)= %.4f\n",cont+1,x0,x0,funcao(x0),x1,x1,funcao(x1),x2,x2,funcao(x2));
	c=x1-x0;
	x0=x1;
	x1=x2;	
	cont++;
	if(cont>=Ni){
		break;
	}
	}	
	printf("\n--------------------------------");
	printf("\nNumero de Iteracoes:%d.\nRaiz:%f.\nF(%f)=%f.",cont,x2,x2,funcao(x2));		
	return 0;
}
