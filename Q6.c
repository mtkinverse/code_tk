#include <stdio.h>
void main(){
	int j,i,row2,col2,row1,col1;
	printf("Input rows and columns of the matrix A \n");
	scanf("%d",&row1);
    scanf("%d",&col1);
    int mata[row1][col1];
    for(j=0;j<row1;j++){
    	for(i=0;i<col1;i++){
            printf("Give the element of the matrix[%d][%d] : ",j,i);
    		scanf("%d",&mata[j][i]);
		}
	}
   printf("Input rows and columns of the matrix B \n");
	scanf("%d",&row2);
    scanf("%d",&col2);
    int matb[row2][col2];
    for(j=0;j<row2;j++){
    	for(i=0;i<col2;i++){
            printf("Give the element of the matrix[%d][%d] : ",j,i);
    		scanf("%d",&matb[j][i]);
		}
	}
	if(row2==col1){
		printf("The multiplication of the matrix is \n");
        int k,mul=0,matc[row1][col2];
		for(j=0;j<row1;j++){
			for(k=0;k<col2;k++){
			   for(i=0;i<col2;i++){
				mul+=mata[j][i]*matb[i][k];
			}
            matc[j][k]=mul;
            mul=0;
            printf("%d\t",matc[j][k]);
		}
		printf("\n");
        }
		
		
	}else printf("The matrix cannot be multiplied\n");
	
}