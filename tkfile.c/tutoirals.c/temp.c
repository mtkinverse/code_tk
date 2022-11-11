#include<stdio.h>
#include<math.h>
void hot(int n);
void cold(int n);
int main(){
   int n;
   while(n!=0){
    printf("press 0 to end the program\nOR Povide your temperature here\n");
    scanf("%d",&n);
   if(n==0){printf("you have ended the program\nThanks\n");}else
    if(n>32&&n<=60){hot(n);}else if(n<=20&&n>0){cold(n);}else
    if(n>20&&n<=32){printf("you have a moderate temperature\n");}else if(n>60){printf("Invalid entry\n");}
   }
    return 0;
}
void hot(int n){
    printf("you have a hot atmosphere\n");
}
void cold(int n){
    printf("you have a cold atmosphere\n");
}