#include<stdio.h>
void main(){
    int count=0,wrong=0;
    char a,b;
    printf("Enter the characters :\n");
    a=getche();
    while(count<2){
        b=getche();
        if(b==(a+1)||b==(a-1))count++;
        else {count=0;}
        wrong++;
        a=b;
    }printf("\nYou have entered %d characters\n",wrong+1);
}