#include<stdio.h>
#include<math.h>
int main(){
printf("HI and welcome to the argstorm checker \n");
    int A=3;
    int X;
    printf("GIve the three digit number\n");
    scanf("%d",&X);
    int a;
    printf("enter the first digit\n");
    scanf("%d",&a);
    int K= pow(a,A);
    if(a<=0){
        printf("Please restart and provide three digit number\n") ;
         return 0;
    }
    int b;
    printf("provide the second digit\n");
    scanf("%d",&b);
    int L= pow(b,A);
    int c;
    printf("lavitate the third digit\n");
    scanf("%d",&c);
    int M= pow(c,A);
    int D = (L+M+K) ;
    if(X == D ){
        printf("your number is argstorm number\n");
    }else{
        printf("your number is not argstorm number\n");
    }
    printf("------------THANKS---------------\n");
    return 0;
}