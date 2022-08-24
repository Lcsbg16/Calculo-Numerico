#include <stdio.h>
#include <stdlib.h>
#include <math.h>
float f(float x){
	return exp(x);
}
main(){
	float a,b,n;
	float xm,h,somatorio,area;
	printf("\tMetodo dos Retangulos\n");
	printf("*******************************\n");
	printf("Informe o valor de A:");
	scanf("%f",&a);
	printf("Informe o valor de B:");
	scanf("%f",&b);
	printf("Informe o numero de retangulos:");
	scanf("%f",&n);		
	//h=(a+b)/n;
	h=(b-a)/n;
	printf("----------------------------------\n");
	printf("I \t    Xm \t\tF(Xm)    |\n");
	printf("----------------------------------\n");	
	for(int i=0;i<n;i++){
		xm=(i*h+(i+1)*h)/2;
		somatorio=somatorio+f(xm);
		printf("%d \t| %.4f \t| %.4f |\n",i,xm,f(xm));
	}
	printf("----------------------------------\n");	
	area=somatorio/n;
	printf("\nSomatorio: %.4f\nArea: %.4f.",somatorio,area);
	return 0;
}
