#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <conio.h>
main(){
	int i,j,n,x,k=0,cont=0,iter;
	float erro;
	printf("***************************************\n");
	printf("    Metodo Gauss-Seidel (Matricial) \t\n");
	printf("***************************************\n");
	printf("Informe o numero de incognitas do sistema:");
	scanf("%d",&n);
//	printf("\nEntre com o numero de iteracoes:");
//	scanf("%d",&iter);
	printf("\nEntre com o valor do erro:");
	scanf("%f",&erro);
	float A[n][n],B[n][1],X[n][1],Xi[n][1],D[n][n],S[n][n],I[n][n],DI[n][n],ident[n][n],G[n][n],F[n][1],GX[n][1],AX[n][1],R[n][1];
	float pivo=0,p=0,m=0;
	float soma=0,aux=0,dif=0;
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
	
	
//Calculando a Diagonal
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			if(i==j){
				D[i][j]=A[i][j];
			}else{
				D[i][j]=0;
			}
		}
	}
		
	printf("\n\nMatriz Diagonal de A:\n");	
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
			if(i<=j){
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

	//Identidade
	for (i = 0; i < n; i++){
	    for (j = 0; j < n; j++){
		if (i == j){
		    ident[i][j] = 1;
		    }
		else {
		    ident[i][j] = 0;
		    }
		}
	}
	    
// Somando a matriz Diagonal com a Inferior
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			DI[i][j]=D[i][j]+I[i][j];
		}
	}
	printf("\n\nMatriz D+I:\n");	
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			printf("%.4f",DI[i][j]);
			printf("\t");	
	}
		printf("\n");
	}			    
//Calculando a matriz inversa de (D+I)
for(j = 0; j < n; j++){
    pivo = DI[j][j];
    p=pivo/pivo;
    for(k = 0; k < n; k++){
		DI[j][k] = (DI[j][k])/(pivo); 
		ident[j][k] = (ident[j][k])/(pivo); 
        }
    
	for(i = 0; i < n; i++){
		if(i != j){
			m = DI[i][j]/p;
           	for(k = 0; k < n; k++){
			DI[i][k] = (DI[i][k]) - (m*DI[j][k]); 
			ident[i][k] = (ident[i][k]) - (m*ident[j][k]);  
    			}
    		}
    	}  
}
	printf("\n\nMatriz Inversa de DI:\n");	
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			printf("%.4f",ident[i][j]);
			printf("\t");	
	}
		printf("\n");
	}



//G=-(D+I)^-1 * S
	for(i = 0; i < n; i++) {
		for(j = 0; j <n; j++) {
			G[i][j] = 0;
			for(x = 0; x < n; x++) {
				aux +=  -ident[i][x] * S[x][j];
			}
			G[i][j] = aux;
			aux = 0;
		}
	}



//Matriz G
	printf("\n\nMatriz G:\n");	
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			printf("%.4f",G[i][j]);
			printf("\t");	
	}
		printf("\n");
	}
	
//Multiplicando F=InversaDI * B	
	for(i = 0; i < n; i++) {
		for(j = 0; j < 1; j++) {
			F[i][1] = 0;
			aux = 0;
			for(k = 0; k < n; k++) {
				aux +=  ident[i][k] * B[k][1];
			}
			F[i][j] = aux;
		}
	}	
	printf("\n\nMatriz F:\n");
	for(i = 0; i < n; i++) {
		for(j = 0; j < 1; j++) {
			printf("%.4f", F[i][j]);
		}
		printf("\n\n");
	}
	
//X=G*Xi+F		
	do{
		for(i = 0; i < n; i++) {
			for(j = 0; j < 1; j++) {
				GX[i][j] = 0;
				aux = 0;
			for(x = 0; x < n; x++) {
				aux +=  G[i][x] * Xi[x][j];
			}
			GX[i][j] = aux;
		}
	}

	
	
//Calculando Resultado
	for(i = 0; i < n; i++) {
		for(j = 0; j < 1; j++) {
			X[i][j]=GX[i][j]+F[i][j];
			dif=fabs(X[i][j])-fabs(Xi[i][j]);
			Xi[i][j]=X[i][j];
		}
		
	//Criterio de Parada	
		if(fabs(dif)>erro){
			para=1;
		}
		else{
			para=0;				
		}
		
}	
	}while(para==1);
	printf("\n**************");		
	printf("\nResultados:\n");
	printf("Matriz X:\n");
	for(i = 0; i < n; i++) {
		for(j = 0; j < 1; j++) {
			printf("%.4f", X[i][j]);
		}
		printf("\n");
	}

printf("**************\n");	

//Conferindo Valores
	//A*X
	aux=0;
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
}

