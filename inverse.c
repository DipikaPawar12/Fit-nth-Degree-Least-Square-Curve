//Main File is "LSSolution.c" Please run that file

// RREF form to find Inverse 
void upperTraingularForm(float**matrix,float** inverse,int n,int m){
	int tp,i,j,k;
	float pivot, temp;
    if(n>m){
        tp=m-1;
    }
        else{
            tp=n;
    }
        for (i = 0; i <tp; i++) {
            pivot = matrix[i][i];
            if(pivot == 0) {
                int exchangeWith = findNonZeroPivot(matrix, i, i,m);
                if (exchangeWith != -1) {
                     rowExchange(matrix, i, exchangeWith,n);
                    pivot = matrix[i][i];
                } else {
                    continue;
                }
            }
            for ( k = i + 1; k < m; k++) {
                temp = (float) matrix[k][i];
                for ( j = 0; j < n; j++) {
                    matrix[k][j] += ((-1) * matrix[i][j] * temp) / pivot;
                    inverse[k][j]+=((-1) * inverse[i][j] * temp) / pivot;
                }                
            }
        }
}
void rrefForm(float** matrix, float** inverse,int n, int m){
	int tp,i,j,k;
	float temp,pivot;
	if(n>m){
            tp=m;
        }
        else{
            tp=n;
        }
        for (i = tp-1; i >=0; i--) {
            pivot = matrix[i][i];
            if (pivot == 0) {
                continue;
            }
			for(j=0;j<n;j++){
				inverse[i][j]/=pivot;
				matrix[i][j]/=pivot;
			}if(i!=0){				
	            for (k = i - 1; k >= 0; k--) {
	                temp = (float) matrix[k][i];
	                for ( j = 0; j < n; j++) {
	                    matrix[k][j] += ((-1) * matrix[i][j] * temp);
	                    inverse[k][j]+=((-1) * inverse[i][j] * temp) ;
	                }
	               
	            }
	    	}
	       
        }
}  
/*2
1 0
2 0
3 1*/
int findNonZeroPivot(float **matrix, int zeroPivotRow, int index,int m) {
	int i;
        for ( i = zeroPivotRow + 1; i < m; i++) {
            if (matrix[i][index] != 0) {
                return i;
            }
        }
        return -1;
}
void rowExchange(float **matrix, int row1, int row2,int n) {
    float swap,sw;
    int i;
    for (i = 0; i <n; i++) {
        swap = matrix[row1][i];
        matrix[row1][i] = matrix[row2][i];
        matrix[row2][i] = swap;      
    }
}
