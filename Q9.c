#include<stdio.h>

void main(){
    int i,a,b,j,var;
int arr[][3]={1,2,3,4,5,6,7,8,9};
printf("Matrix before the exchange of rows is\n");
for(j=0;j<3;j++){
for(i=0;i<3;i++){
    printf("%d\t",arr[j][i]);
}printf("\n");
}
printf("Give the number of rows you want to exchange : ");
scanf("%d %d",&a,&b);
for(j=b-1,i=0;i<3;i++){
    var=arr[j][i];
    arr[j][i]=arr[a-1][i];
    arr[a-1][i]=var;
}
for(j=0;j<3;j++){
    for(i=0;i<3;i++){
         printf("%d\t",arr[j][i]);
    }printf("\n");
}
}