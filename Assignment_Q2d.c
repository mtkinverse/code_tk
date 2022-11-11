#include<stdio.h>
void main(){int n,age;char ch;
   printf("For how many persons you want to check the elgibility\n");
    scanf("%d",&n);
    for(n;n;n--){
    printf("Enter the age of person : ");
    scanf("%d",&age);
    printf("Form urban or rural area ?\n (U,R) : ");
    scanf(" %c",&ch);
    if((ch=='u'||ch=='U')&&age>=18)printf("Elgible for the vaccination. Kindly proceed to the counter\n");
    else if((ch=='r'||ch=='R')&&age<18)printf("Not Elgible for the vaccination. Kindly wait for the vaccination\n");
    }
}