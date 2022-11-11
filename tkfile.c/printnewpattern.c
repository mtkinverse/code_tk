#include<stdio.h>
int main(){
 printf("\nThis is double style S\n\n");
  char arr[4][4]={{'*','*','*','*'},{'*','*','*','*',},{'*','*','*','*',},{'*','*','*','*',}};
   printf("\t\t\t");for(int i=0;i != 4 ;i++){
    printf("%c\t",arr[i][0]);}printf("\n");
    printf("\t\t\t");for(int i=0;i != 3 ;i++){
    printf("%c\t",arr[i][1]);}printf("\n");     ///PRINTING right triangle
    printf("\t\t\t");for(int i=0;i != 2 ;i++){
    printf("%c\t",arr[i][2]);}printf("\n");
    printf("\t\t\t");for(int i=0;i != 1 ;i++){
    printf("%c\t",arr[i][3]);}printf("\n");

    printf("\t\t\t");for(int i=0;i != 4 ;i++){
    printf("%c\t",arr[i][0]);}printf("\n");
    printf("\t\t\t");for(int i=0;i != 4 ;i++){
        if(i==0){printf("\t"); continue;}
    printf("%c\t",arr[i][1]);}printf("\n");     ///PRINTING upper right triangle
    printf("\t\t\t");for(int i=0;i != 4 ;i++){
        if(i==0 || i==1){printf("\t"); continue;}
    printf("%c\t",arr[i][2]);}printf("\n");
    printf("\t\t\t");for(int i=0;i != 4 ;i++){
        if(i==0 || i==1 || i==2){printf("\t"); continue;}
    printf("%c\t",arr[i][3]);}printf("\n");

    printf("\t\t\t");for(int i=0;i != 4 ;i++){
    printf("%c\t",arr[i][0]);}printf("\n");
    printf("\t\t\t");for(int i=0;i != 3 ;i++){
    printf("%c\t",arr[i][1]);}printf("\n");     ///PRINTING right triangle
    printf("\t\t\t");for(int i=0;i != 2 ;i++){
    printf("%c\t",arr[i][2]);}printf("\n");
    printf("\t\t\t");for(int i=0;i != 1 ;i++){
    printf("%c\t",arr[i][3]);}printf("\n");

    return 0;
}