//Main File is "LSSolution.c" Please run that file
//Print the 2D matrix
void print(float **A,int m,int n){
	int i,j;
	for(i=0;i<m;i++){
		for(j=0;j<n;j++){
			printf("%f ",A[i][j]);
		}
		printf("\n");
	}
}

// Transpose of some matrix
void transpose(float** C,float** A,int m,int n){
	int i,j;
	for(i=0;i<m;i++){
		for(j=0;j<n;j++){
			C[j][i]=A[i][j];
		}
	}
}

//Multiply two matrices
void multiplication(float**A,float **B,float **C,int row1,int row2,int colomn1,int colomn2){
	int i,j,k;
	for(i=0;i<row1;i++){
		for(j=0;j<colomn2;j++){
			C[i][j]=0;      
			for(k=0;k<row2;k++){  
				C[i][j]+=A[i][k]*B[k][j];      
			}
		}
	}
}

// Store value in txt file
void values(float constant[],int n){
	FILE *fp;
	int i;
	float x,y,w;
	fp=fopen("LS.dat","w");
	x=-400;
	while(x<=400){
		y=0;
		int kk=n;
		for(i=0;i<n;i++){
		    w=constant[i]*pow(x,kk-1);
			y=y+w;
			kk--;
		}
		fprintf(fp,"%f     %f\n",x,y);
		x=x+0.1;
	}
	fclose(fp);
	getch();
}
