#include<stdio.h>
#include<math.h>
int sumdig(int n);
int main(){
    int n;
    do{
   printf("give the number you want to calulate their sum of digit\nOr enter zero to exit the program\n");
   scanf("%d",&n);
   if(n==0){printf("you have ended the program thanks\n"); return 0;}
   printf("The sum of the digits of %d is : %d\n", n,sumdig(n));
    }while(n!=0||n!=0);
    return 0;
}
int sumdig(int n){
if (n==0){return 0;}
int r,z=0;
int t= n;
while (t!=0){
 r= t%10;
 z= z+r;  
 t=t/10;
}return z;
}