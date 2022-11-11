#include<stdio.h>

void main(){
int n=10,num,rem,count=0;
printf("Give the number : ");
scanf("%d",&num);
    rem=0;
while(num>0){
    
    rem=(rem*10)+(num%10);
    num/=10;
}num=rem;
while(num>0){
    rem=num%n;
    num/=10;
    switch(rem){
        case 0:printf("zero ");break;
        case 1:printf("One ");break;
        case 2:printf("two ");break;
        case 3:printf("three ");break;
        case 4:printf("four ");break;
        case 5:printf("five ");break;
        case 6:printf("six ");break;
        case 7:printf("seven ");break;
        case 8:printf("eight ");break;
        case 9:printf("nine ");break;
    }
count++;
}
printf("\nThe length is %d\n",count);
}