#include<stdio.h>

void swapit(int n1,int n2){
    printf("After swapping n1=%d , n2=%d\n",n2,n1);
}

void actualswap(int *n1,int *n2){
    int var=*n1;
    *n1=*n2;
    *n2=var;
}

void main(){
int n1,n2;
printf("Give the first number : ");
scanf("%d",&n1);
printf("Give the second number : ");
scanf("%d",&n2);
printf("--> Swapping without pointers\n\nBefore swapping n1=%d,n2=%d\n",n1,n2);
swapit(n1,n2);
printf("\n--> Swapping with pointers\n\nBefore swapping n1=%d,n2=%d\n",n1,n2);
actualswap(&n1,&n2);
printf("After swapping n1=%d , n2=%d\n",n1,n2);


}