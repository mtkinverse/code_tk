#include<stdio.h>
int main(){
printf("\n\nThis is the front of a house\n\n");
char arr[5] = {'*','*','*','*','*'};
for (int i=0 ; i <= 4 ; i++){
if(i==0 || i==1 || i==3 || i==4 ){printf("\t");continue;}printf("%c\t",arr[i]); }printf("\n");
for (int i=0 ; i<=4 ; i++){
    if(i==0 || i==4){printf("\t"); continue; }printf("%c\t",arr[i]);}printf("\n");
for (int i=0 ; i <= 4 ; i++){printf("%c\t",arr[i]); }printf("\n");
for (int i=0 ; i <= 4 ; i++){printf("%c\t",arr[i]); }printf("\n");
for (int i=0 ; i <= 4 ; i++){
 if( i==2 ){printf("\t"); continue; }printf("%c\t",arr[i]);
 }printf("\n");
for (int i=0 ; i <= 4 ; i++){
  if(i==2){printf("\t");continue;}  
    printf("%c\t",arr[i]); }printf("\n");
for (int i=0 ; i <= 4 ; i++){if(i==2){printf("\t");continue;}printf("%c\t",arr[i]); }printf("\n");
for (int i=0 ; i <= 4 ; i++){if(i==2){printf("\t");continue;}printf("%c\t",arr[i]); }printf("\n");
printf("\n\nThis is the outline of the house\n\n");
for (int i=0 ; i <= 4 ; i++){
if(i==0 || i==1 || i==3 || i==4 ){printf("\t");continue;}printf("%c\t",arr[i]); }printf("\n");
for (int i=0 ; i<=4 ; i++){
    if(i==0 || i==2 || i==4){printf("\t"); continue; }printf("%c\t",arr[i]);}printf("\n");
for (int i=0 ; i <= 4 ; i++){
   if(i==1 || i==2 || i==3){printf("\t");continue;} 
    printf("%c\t",arr[i]); }printf("\n");
for (int i=0 ; i <= 4 ; i++){printf("%c\t",arr[i]); }printf("\n");
for (int i=0 ; i <= 4 ; i++){
 if( i==2 ){printf("\t"); continue; }printf("%c\t",arr[i]);
 }printf("\n");
for (int i=0 ; i <= 4 ; i++){
  if(i==2){printf("\t");continue;}  
    printf("%c\t",arr[i]); }printf("\n");
for (int i=0 ; i <= 4 ; i++){if(i==2){printf("\t");continue;}printf("%c\t",arr[i]); }printf("\n");
for (int i=0 ; i <= 4 ; i++){if(i==2){printf("\t");continue;}printf("%c\t",arr[i]); }printf("\n");
   
    return 0;
}
