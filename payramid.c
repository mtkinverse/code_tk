#include<stdio.h>

void main(){
    int n,i,j;
printf("Enter the number of repitaions : ");
scanf("%d",&n);
for(j=0;j<n;j++){printf("\t\t\t");
    for(i=0;i<n-j;i++)printf(" ");
    for(i=0;i<=j;i++)printf("*");
    for(i=j;i>0;i--)printf("*");
    printf("\n");
}int count=0;
for(j=1,i=1;count<=4;j++){
    printf("%d ",i);
    if(i==j){
        printf("\n");i++;count++;j=0;
    }
}


}