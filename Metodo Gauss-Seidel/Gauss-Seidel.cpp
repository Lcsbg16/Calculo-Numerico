#include <stdio.h>
#include <stdlib.h>
#include <math.h>
main(){
	int i,j,n,k,cont=0,m;
	float erro;
	printf("*********************************\n");
	printf("\t Metodo Gauss-Seidel  \t\n");
	printf("*********************************\n");
	printf("Informe o numero de incognitas do sistema:");
	scanf("%d",&n);
	float A[n][n],B[n],X[n],Xi[n];
	float dif=0,soma;
	int para=1;
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			printf("Entre com o elemento A[%d][%d] : ",i+1,j+1);
			scanf("%f",&A[i][j]);
		}
	}
	printf("\n\nMatriz A:\n");
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			printf("%2.f",A[i][j]);
			printf("\t");	
	}
		printf("\n");
	}

	printf("\n\nEntre com os valores da matriz B (termos independentes):\n");
	for(i=0;i<n;i++){
		printf("Entre com o elemento B[%d]: ",i+1);	
		scanf("%f",&B[i]);
	}
	printf("\n\nMatriz B:\n");
	for(i=0;i<n;i++){
		printf("%2.f\n",B[i]);	
	}	
	printf("\nInforme o valor do Erro:");
	scanf("%f",&erro);
	
	printf("\n\nEntre com os valores para um chute inicial:\n");
	for(i=0;i<n;i++){
		printf("Entre com o elemento Xi[%d]: ",i+1);	
		scanf("%f",&Xi[i]);
	}
	    
	do{
		for(int i=0;i<n;i++) {
	        soma=0;
	        for(int j=0;j<n;j++) {
	            if(i!=j) {
	                soma+=A[i][j]*Xi[j];
	            }
	        }
	        	X[i]=(1/A[i][i])*(B[i]-soma);
	        	printf("X(%d) = %f\n",i+1,X[i]);
	        	dif=fabs(X[i])- fabs(Xi[i]);
	        	Xi[i]=X[i];
				if(fabs(dif)>erro){
					para=1;
				}else 
					para=0;					
	    }	   
		printf("\n");     	
	    }while(para==1);
	    	
	return 0;
}
