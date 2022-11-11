#include<stdio.h>

int main(){
    int n,fact=1;
printf("Give the number of which you want to print factorial but it should be less than or equal to 12\n");
scanf("%d",&n);if(n>12){printf("Invalid entry\n"); main();}
for(int i=1;i<=n;i++){
    fact=fact*i;
}printf("The factorial is %d\n",fact);main();
return 0;
}