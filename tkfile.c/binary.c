#include<stdio.h>

void main(){

int large,less,a,b,i,rem,zero=0,one=0;
printf("Give 1 Decimal : ");
scanf("%d",&large);
for(i=2;i<=5;i++){
    printf("Give the %d decimal : ",i);
    scanf("%d",&a);
    if(a>large)large=a;
    else if(a<less)less=a;
}b=less+large;
printf("\nsum is : %d\nMaximum number : %d\nminimum number : %d\n",b,large,less);
rem=0;
do{
    rem=(rem*10)+(b%2);
    if(b%2==0)zero++;
    else one++;
    b/=2;
}while(b>0);
rem=rem+b%2;
printf("The binary output is : %d\nThe number of xero are %d\nThe number of one are %d\n",rem,zero,one);


}