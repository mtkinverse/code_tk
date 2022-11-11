#include<stdio.h>
int main(){
printf("\n\nThis is my name \n\n");
char arr[14] = {'*','*','*','*','*','*','*','*','*','*','*','*','*','*'};
for(int i=0 ; i <=13 ; i++){
    if(i==9 ){printf("\t"); continue;}
     printf("%c\t",arr[i]);}printf("\n");
for (int i=0 ; i <= 13 ; i++){
    if(i==0 || i==1 || i==3 || i==4 || i==6 || i==9 || i==12){printf("\t");continue;}
    printf("%c\t",arr[i]);}printf("\n");
for (int i=0 ; i <=13 ; i++){
   if(i==0 || i==1 || i==3 || i==4 || i==6 || i==9 || i==12){printf("\t");continue;} 
    printf("%c\t",arr[i]);}printf("\n");
for (int i=0 ; i<=13 ; i++){
    if(i==0 || i==1 || i==3 || i==4){printf("\t");continue;}
    printf("%c\t",arr[i]);}printf("\n");
for(int i=0 ; i <=13 ; i++){
    if(i==0 || i==1 || i==3 || i==4 || i==6 || i==9 || i==12){printf("\t"); continue;}
     printf("%c\t",arr[i]);}printf("\n");
for (int i=0 ; i <= 13 ; i++){
    if(i==0 || i==1 || i==3 || i==4 || i==6 || i==9 || i==12){printf("\t");continue;}
    printf("%c\t",arr[i]);}printf("\n");
for (int i=0 ; i <=13 ; i++){
   if(i==0 || i==1 || i==3 || i==4 || i==6 || i==9 || i==12){printf("\t");continue;} 
    printf("%c\t",arr[i]);}printf("\n");

    return 0;
}