#include <stdio.h>
#include <stdlib.h>
#include <math.h>

float f(float x)
{
	return exp(x)-1;
}
int main(void){
	float a,b,c,m,fm,erro;
	int Ni,cont=0;

	
	printf("Informe o valor do limite inferior:");
	scanf("%f",&a);
	printf("\nInforme o valor do limite superior:");
	scanf("%f",&b);
	printf("\nInforme o valor do erro:");
	scanf("%f",&erro);
	printf("\nInforme o numero de interecoes desejadas:");
	scanf("%d",&Ni);
	c=b-a;
	printf("\nK \t  A \t\t    B \t\t     m \t     \t     f(m)\n");
	printf("----------------------------------------------------------------------------------\n");	
	while(c>erro){
		m=(a+b)/2;
		printf("%d  \t %f \t %f \t %f \t f(%f) = %f\n",cont,a,b,m,m,f(m));
		if(f(a)*f(m)<0)
		{
			b=m;	
		}
		if(f(a)*f(m)>0)
		{
			a=m;
		}
		c=b-a;
		cont++;
		if(cont >= Ni){
			break;
	}
	}
	printf("\n--------------------------------");
	printf("\nNumero de Iteracoes:%d.\nRaiz:%f.\nF(%f)=%f.",cont,m,m,f(m));	
return 0;
}
