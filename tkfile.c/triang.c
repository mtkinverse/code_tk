#include<stdio.h>
int main(){
char arr[4]={'*','*','*','*'};
 int i;
//  for ( i == 2; i != 3 ;i++){
   printf("\t\t\t"); printf("%c\t\n",arr[0]);
   printf("\t\t\t");for (int i=0 ; i != 2 ; i++){
    printf("%c\t",arr[i]);
   }printf("\n");
   printf("\t\t\t");for (int i=0 ; i != 3 ; i++){
    printf("%c\t",arr[i]);}printf("\n");
    printf("\t\t\t");for (int i=0 ; i <= 3 ; i++ ){
        printf("%c\t",arr[i]);}printf("\n");
        printf("\t\t\t");for (int i=0 ; i<=2 ; i++){
printf("%c\t",arr[i]);  }printf("\n");
printf("\t\t\t");for(int i=0 ; i <=1 ; i++){printf("%c\t",arr[i]);}
printf("\n\t\t\t%c\n",arr[0]);

return 0;
}