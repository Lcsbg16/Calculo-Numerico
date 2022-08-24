#include <stdio.h>
#include <stdlib.h>
#include<time.h>
#include<string.h>
#include <locale.h>
#include <math.h>
float f(float x)
{
  return  1/pow(x,6);
}
	
main(){
	float a,b,n,h,x,soma,area;
	int coef;
	printf("Informe o valor do intervalo A:");
	scanf("%f",&a);
	printf("Informe o valor do intervalo B:");
	scanf("%f",&b);
	printf("Informe o numero de trapezios a serem utilizados:");
	scanf("%f",&n);
	h=(b-a)/n;
	printf("I \t Xi \t\t F(xi) \t\t Ci \tCi*F(xi)\n");
	for (int i = 0; i < n; i++)
	  {
	  	if(i==0 || i==n-1){
	  		coef=1;
		  }else{
		  	coef=2;
		  }
	  	printf("%d \t %f \t %f \t %d \t %f\n",i,a,f(a),coef,f(a + h));
	    soma=soma+(f(a)+f((a + h)))*h/2;
	    a=a+h;
	  }
	area=soma;
	printf("\nArea: %.4f\n", area);
}

