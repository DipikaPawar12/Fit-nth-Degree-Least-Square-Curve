#include <stdio.h> 
#include <stdlib.h> 
#include<math.h>
#include "inverse.c"
#include "OtherNeed.c"
void transpose(float**,float**,int ,int);
void print(float**,int ,int);
void multiplication(float**,float **,float **,int ,int,int ,int );
void upperTraingularForm(float**,float**,int,int );
void rrefForm(float**, float**,int , int );
int findNonZeroPivot(float **, int , int ,int );
void rowExchange(float **, int , int ,int );
void values(float [],int );

// second degree equation
// y=a*x*x+b*x+c
// n=degree of equation
int main(){
	int n,m,i,j;
	printf("Enter no of rows of a matrix:\n");
	scanf("%d",&m);
	printf("Enter degree of equation(columns):\n");
	scanf("%d",&n);
	n=n+1;
	float **A,**At,**T,**inverse,**tmp, **b,**ab;
	
	
	
	A= malloc(sizeof(int*) * m); 
   	for(i = 0; i < m; i++) {
      	A[i] = malloc(sizeof(int*) * n);
   	}
   	
   	At= malloc(sizeof(int*) * n); 
   	for(i = 0; i < n; i++) {
      	At[i] = malloc(sizeof(int*) * m);
   	}
   	T= malloc(sizeof(int*) * n); 
   	for(i = 0; i < n; i++) {
      	T[i] = malloc(sizeof(int*) * n);
   	}
   	inverse= malloc(sizeof(int*) * n); 
   	for(i = 0; i < n; i++) {
      	inverse[i] = malloc(sizeof(int*) * n);
   	}
  	tmp= malloc(sizeof(int*) * n); 
   	for(i = 0; i < n; i++) {
      	tmp[i] = malloc(sizeof(int*) * m);
   	}
	b=malloc(sizeof(int*)*m);
   	for(i = 0; i < m; i++) {
      	b[i] = malloc(sizeof(int*) * 1);
   	}
   	ab=malloc(sizeof(int*)*n);
   	for(i = 0; i < n; i++) {
      	ab[i] = malloc(sizeof(int*) * 1);
   	}
   	
   	
   	
   	//printf("enter coffiecents of ax^2+bx+c(x^2,x,1)(Whole matrix A):");
   	printf("Enter the x values... %d rows",m);
   	for(i=0;i<m;i++){
   		scanf("%f",&A[i][n-2]);
   	}
	for(i=0;i<m;i++){
		for(j=0;j<n;j++){
			A[i][j]=pow(A[i][n-2],(n-j-1));
		}
	}
	print(A,m,n);
	printf("enter solution:");
	for(i=0;i<m;i++){
		for(j=0;j<1;j++){
			scanf("%f",&b[i][j]);
		}
	}
	//(A^T*A)x = A^T*b. Here, x is coffiecient matrix a,b,c and b is solution
	transpose(At,A,m,n); //A^T	
	multiplication(At, A, T,n,m,m,n); //T=(A^T*A)
	for(i=0;i<n;i++){  //Identity matrix of nxn
   		for(j=0;j<n;j++){
   			if(i==j){
   				inverse[i][j]=1;
			}
			else
   				inverse[i][j]=0;
		 
		}
	}
	
	upperTraingularForm(T,inverse,n, n); 
	rrefForm(T, inverse,n, n); //inverse=(A^T*A)^-1
	multiplication( inverse, At,tmp,n,n,n,m); //(A^T*A)*A^T
	multiplication (tmp, b,ab,n,m,m,1); //x=(A^T*A)*A^T*b
	printf("\n(a,b,c,...)=");
	print(ab,n,1); //vlaue of coffiecients degree+1
	float consta[n];
	
	for(i=0;i<n;i++){
		consta[i]=ab[i][0];
	}
	
	//Predict y for some value x
	printf("enter one x value:\n");
	float h;
	scanf("%f",&h);
	float y=0,z=0;
	int kk=n;
	for(i=0;i<n;i++){
			z=consta[i]*pow(h,kk-1);
			y=y+z;
			kk--;
	}
	printf("predicted y value is:%f\n",y);
	values(consta,n);
	
	
	
	//Free the pointers
	for(i = 0; i < m; i++) {
        	free(A[i]);
    	}
    free(A);
	for(i = 0; i < n; i++) {
        	free(At[i]);
    	}
    free(At);
    for(i = 0; i < n; i++) {
        	free(inverse[i]);
    	}
    free(inverse);
	for(i = 0; i < n; i++) {
        	free(T[i]);
    	}
    free(T);
    for(i = 0; i < n; i++) {
        	free(tmp[i]);
    	}
    free(tmp);
	for(i = 0; i < m; i++) {
        	free(b[i]);
    	}
    free(b);
    for(i = 0; i < n; i++) {
        	free(ab[i]);
    	}
    free(ab);
}













