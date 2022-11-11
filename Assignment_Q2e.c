#include<stdio.h>
void main(){int n,age;char ch;
    printf("For how many persons you want to check the elgibility\n");
    scanf("%d",&n);
    while(n){
        printf("Give the age : ");
        scanf("%d",&age);
        if(age>=18){
            printf("Urban or Rural ?\n(U,R) : ");
            scanf(" %c",&ch);if(ch=='u'||ch=='U')printf("Elgible for the vaccination. Kindly proceed to the counter\n");  
        }else if(age<18){
            printf("Urban or Rural ?\n(U,R) : ");
            scanf(" %c",&ch);if(ch=='R'||ch=='r')printf("Not Elgible for the vaccination. Kindly wait for the vaccination\n");
        }
     n--;   
    }
}