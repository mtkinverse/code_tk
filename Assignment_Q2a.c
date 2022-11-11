#include<stdio.h>
void main(){
int n,age;
char ch;
printf("For how many persons you want to check the elgibility\n");
scanf("%d",&n);
for(n;n;n--){
    printf("Enter the age of person : ");
    scanf("%d",&age);
    printf("Form urban or rural area ?\n (U,R) : ");
    scanf(" %c",&ch);
    switch(ch){
        case 'R': case 'r':
        if(age<18)printf("Not Elgible for the vaccination. Kindly wait for the vaccination\n");
        break;
        case 'u':case 'U':
        if(age>=18)printf("Elgible for the vaccination. Kindly proceed to the counter\n");
        break;
        default:printf("\nInvalid Entry\n");
    }
}
}