#include <stdio.h>
#include <stdlib.h>
#include<time.h>
#include<string.h>
#include <locale.h>
#include <math.h>
float f(float x)
{
  return x*(1+pow(x,3));
}
	
main(){
	float a,b,h,x,sum,area,cif,soma;
	float sup,inf;
	int coef,n;
	printf("Informe o valor do intervalo A:");
	scanf("%f",&a);
	printf("Informe o valor do intervalo B:");
	scanf("%f",&b);
	printf("Informe um valor par para N:");
	scanf("%d",&n);
	h=(b-a)/n;
	printf("I \t Xi \t\t F(xi) \t\t Ci \t Ci*F(xi)\n");
	printf("=========================================================\n");
	for (int i = 0; i < n+1; i++)
	  {
	  	if(i==0 || i==n){
			coef=1;	
		  }
		 else{
		 	if(i%2==0){
		 		coef=2;
			 }
			 else{
			 	coef=4;
			 }
		 }   
		cif=coef*f(a);
	    a=a+h;
		soma=soma+cif;		  
		printf("%d \t %.4f \t %.4f \t %d \t %.4f\n",i,a,f(a),coef,cif);    	
	  }
	area=(soma*h)/3;
	printf("=========================================================\n");
	printf("Soma: %.4f\n",soma); 
	printf("Area: %.4f\n",area);
}
