#include <stdio.h>
#include <stdlib.h>
#include<time.h>
#include<string.h>
#include <locale.h>
#include <math.h>

float f(float x)
{
	return x*x-9;
}
int main(void){
	float a,b,c,m,fm,erro=0.01;
	int Ni,cont=1;
	while(f(a)*f(b)>0){
	
	printf("Informe o valor do limite inferior:");
	scanf("%f",&a);
	printf("\nInforme o valor do limite superior:");
	scanf("%f",&b);
	if(f(a)*f(b)>0)
		printf("f(a)*f(b)>0, informe outros valores para o intervalo!\n");		
}
	printf("\nInforme o numero de interecoes desejadas:");
	scanf("%d",&Ni);
	c=b-a;
	m=(a+b)/2;
	while (c>erro)
	{
		if(f(a)*f(m)<0)
		{
			b=m;
		}
		if(f(a)*f(m)>0)
		{
			a=m;
		}				
		c=b-a;
		m=(a+b)/2;
		cont++;
		if(cont>=Ni){
			break;
		}
		
		
	}
	printf("Raiz: %f\nInteracoes: %d\nf(%f) = %f",m,cont,m,f(m));
	
return 0;
}
