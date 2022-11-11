#include<stdio.h>

void main(){
int row,col,i,j,sum=0;
printf("NOTE : Give any square matrix only\nGive the number of rows : ");
scanf("%d",&row);
printf("Give the number of columns : ");
scanf("%d",&col);
if(row!=col){
    printf("The given matrix is not a square matrix\n");return;
}
int arr[row][col];
for(j=0;j<row;j++){
for(i=0;i<col;i++){
    printf("Give the element of matrix[%d][%d] : ",j+1,i+1);
   scanf("%d",&arr[j][i]);
}

}
//since row and col are equal for square matrix
for(i=0,j=0;i<row&&j<row;i++,j++){
    sum+=arr[i][j];
}
printf("The sum of the elements is %d\n",sum);

}