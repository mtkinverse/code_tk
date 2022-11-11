#include<stdio.h>
int main(){
int N;
do{
    //int N;
printf("give the number you want to check OR\n press 0 to end the program\n");
scanf("%d",&N);
if(N==1,N==2,N==3,N==5,N==7){
printf("it is a prime number\n");}
else if(N==0){printf("you have stopped the program thanks\n");}
else if(N%2==0){printf("it is not a prime number\n");}
else if(N%3==0){printf("it is not a prime number\n");}
else if(N%5==0){printf("it is not a prime number\n");}
else if(N%7==0){printf("it is not a prime number\n");}
else{printf("it is a prime number\n");}
}while(N!=0||N!=0);
 return 0;
}