#include <stdio.h>
#include <stdlib.h>
#include <math.h>
main(){
	int i,j,n,k,cont=0,m,iter;
	float erro;
	printf("***************************************\n");
	printf("    Metodo Gauss-Jacobi (Matricial) \t\n");
	printf("***************************************\n");
	printf("Informe o numero de incognitas do sistema:");
	scanf("%d",&n);
//	printf("\nEntre com o numero de iteracoes:");
//	scanf("%d",&iter);
	printf("\nEntre com o valor do erro:");
	scanf("%f",&erro);
	float A[n][n],B[n][1],X[n][1],Xi[n][1],D[n][n],S[n][n],I[n][n],SI[n][n],J[n][n],E[n][1],JX[n][1],AX[n][1];
	float soma=0,aux,dif=0;
	int para=1;
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			J[i][j]=0;
		}
	}

		
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
		for(j=0;j<1;j++){
			printf("Entre com o elemento B[%d]: ",i+1);	
			scanf("%f",&B[i][1]);
		}
	}
	printf("\n\nMatriz B:\n");
	for(i=0;i<n;i++){
		printf("%2.f\n",B[i][1]);	
	}

	printf("\n\nEntre com os valores para um chute inicial:\n");
	for(i=0;i<n;i++){
		for(j=0;j<1;j++){
			printf("Entre com o elemento Xi[%d]: ",i+1);	
			scanf("%f",&Xi[i][1]);
		}
	}
	
//Montando Matriz Diagonal Inversa	
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			if(i==j){
				D[i][j]=1/A[i][j];
			}else{
				D[i][j]=0;
			}
		}
	}	
	printf("\n\nMatriz inversa da Diagonal de A:\n");	
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			printf("%.4f",D[i][j]);
			printf("\t");	
	}
		printf("\n");
	}
	
// Montando a Matriz Inferior	
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			if(i<j || i==j){
				I[i][j]=0;
			}else{
				I[i][j]=A[i][j];
			}
		}
	}	
	
	printf("\n\nMatriz Inferior:\n");	
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			printf("%.4f",I[i][j]);
			printf("\t");	
	}
		printf("\n");
	}
	
	
		
// Montando a Matriz Superior	
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			if(i>j || i==j){
				S[i][j]=0;
			}else{
				S[i][j]=A[i][j];
			}
		}
	}
		
	printf("\n\nMatriz Superior:\n");	
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			printf("%.4f",S[i][j]);
			printf("\t");	
	}
		printf("\n");
	}	
	
// Somando a matriz Superior com a Inferior
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			SI[i][j]=S[i][j]+I[i][j];
		}
	}
	
	printf("\n\nMatriz Superior + Inferior:\n");	
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			printf("%.4f",SI[i][j]);
			printf("\t");	
	}
		printf("\n");
	}
	
		
// Multiplicaçao de matrizes		
	
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			for(k=0;k<n;k++){
				J[i][j]=J[i][j]-D[i][k]*SI[k][j];	
			}
		}
	}		
//Printando o J

	printf("\n\nMatriz J:\n");
		for(i=0;i<n;i++){
			for(j=0;j<n;j++){
				printf("%.4f",J[i][j]);
				printf("\t");	
		}
			printf("\n");
		}
	
//Calculando e Printando E
	for(i = 0; i < n; i++) {
		for(j = 0; j < 1; j++) {
			E[i][1] = 0;
			aux = 0;
			for(k = 0; k < n; k++) {
				aux +=  D[i][k] * B[k][1];
			}
			E[i][j] = aux;
		}
	}
	
	printf("\n\nMatriz E:\n");
	for(i = 0; i < n; i++) {
		for(j = 0; j < 1; j++) {
			printf("%.4f", E[i][j]);
		}
		printf("\n\n");
	}


//J*Xi
	//while(cont<iter){
	do{
		for(i = 0; i < n; i++) {
			for(j = 0; j < 1; j++) {
				JX[i][j] = 0;
				aux = 0;
			for(k = 0; k < n; k++) {
				aux +=  J[i][k] * Xi[k][j];
			}
			JX[i][j] = aux;
		}
	}
	/*printf("\n\nMatriz JX:\n");
	for(i = 0; i < n; i++) {
		for(j=0;j<1;j++) {
			printf("%.4f",JX[i][j]);
		}
		printf("\n\n");
	}*/
	
	
//Calculando Resultado
	for(i = 0; i < n; i++) {
		for(j = 0; j < 1; j++) {
			X[i][j]=JX[i][j]+E[i][j];
			dif=fabs(X[i][j])-fabs(Xi[i][j]);
			Xi[i][j]=X[i][j];
		}
		
	//Criterio de Parada	
		if(fabs(dif)>erro){
			//printf("Continua %f\n",dif);
			para=1;
		}
		else{
			//printf("Para %f\n",dif);
			para=0;				
		}
		
}
	printf("\n\nMatriz X:\n");
	for(i = 0; i < n; i++) {
		for(j=0;j<1;j++) {
			printf("%.4f",X[i][j]);
		}
		printf("\n\n");
	}
	}while(para==1);
	//Printando Resultado
	printf("\nResultados:\n");
	printf("Matriz X:\n");
	for(i = 0; i < n; i++) {
		for(j = 0; j < 1; j++) {
			printf("%.4f", X[i][j]);
		}
		printf("\n\n");
	}
	
	
//Conferindo Valores
	//A*X
	aux=0;
	int x;
	for(i = 0; i < n; i++) {
		for(j = 0; j < 1; j++) {
			AX[i][j] = 0;
			aux = 0;
		for(x = 0; x < n; x++) {
			aux +=  A[i][x] * X[x][j];
		}
		AX[i][j] = aux;
		}
	}
	printf("Substituindo os valores das icognitas nas equacoes temos os seguintes resultados:\n");	
	for(i=0;i<n;i++){
		for(j=0;j<1;j++){
			printf("%.4f",AX[i][j]);
		}
		printf("\n");
}	
	return 0;						    	
}
