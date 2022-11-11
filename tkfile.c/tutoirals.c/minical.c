#include<stdio.h>//REMAIN INCOMPLETE
#include<math.h>
int add(int a,int b,int c,int d);
int sub(int a,int b,int c,int d);
int multi(int a,int b,int c,int d);
int divi(int a,int b,int c,int d);
int main(){
    printf("Welcome to MINI CALCULATOR\nPress 0 to exit the calculator\n");
    int a,b,c,d;
printf("give your first digit\n");
scanf("%d",&a);
 if (a==0){printf("you have ended the program\n");
    return 0;}
printf("give your second digit\n");
scanf("%d",&b);
printf("give your third digit\n");
scanf("%d",&c);
printf("give your fourth digit\n");
scanf("%d",&d);
int perf;
printf("enter 1 for adition\n2 for subtraction\n3 for multiplication\n4 for division\n");
scanf("%d",&perf);
switch(perf){
    case 1:
    printf("the sum of the digits is : %d\n",add(a,b,c,d));
    break;
    case 2:
   sub(a,b,c,d) ;
    printf("the subrtraction of the digits is : %d\n",sub(a,b,c,d));
    break;
    case 3:
    multi(a,b,c,d);
    printf("the multiplication of the digits is : %d\n",multi(a,b,c,d));
    break;
    case 4:
    divi(a,b,c,d);
    printf("the division of the digits is : %d\n",divi(a,b,c,d));
    break;}
  printf("----------------------------\n            THANKS          \n----------------------------\n");
  main();
   return 0;
}
int add(int a,int b,int c,int d ){
 int s;
    s=(a+b+c+d);
    return s;
}
int sub(int a,int b,int c,int d){
int s;
        s=a-b-c-d;
        return s;
}
int multi(int a,int b,int c,int d){
int m;
m=a*b*c*d;
return m;
}
int divi(int a,int b,int c,int d){
  int x;
        x=(a/b)*(c/d);
        return x;
}