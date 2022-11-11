#include<stdio.h>

void main(){
int a,b,c,d,fd,sd,roll,dig;
printf("Give your roll number : ");
scanf("%d",&roll);
a=roll%100;roll/=100;
b=roll%100;
dig=a*b;
printf("First digits : %d\nsecond digits : %d\nThe Multiplication of %d and %d is %d\n",b,a,a,b,dig);
if(dig%2==0||dig%3==0||dig%5==0||dig%7==0)printf("It is not a prime number\n");
else printf("prime number\n");


}