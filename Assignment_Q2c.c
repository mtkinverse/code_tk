#include<stdio.h>
void main(){int n,age;char ch;
    printf("For how many persons you want to check the elgibility\n");
    scanf("%d",&n);
    while(n){
    printf("Urban or rural ?\n(U,R) : ");
    scanf(" %c",&ch);
    switch(ch){
        case 'U':case 'u':
    printf("Give prson's age : ");
    scanf("%d",&age);
           if(age>=18)printf("Elgible for the vaccination. Kindly proceed to the counter\n");
        break;
        case 'R':case 'r':
    printf("Give person's age : ");
    scanf("%d",&age);
           if(age<18)printf("Not Elgible for the vaccination. Kindly wait for the vaccination\n");
        break;
        default:printf("Invalid Entry\n");
    }n--;
    }
}