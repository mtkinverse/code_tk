#include<stdio.h>
//INCOMPLETE programg
int main(){
int pur,rem,B30,B20,B10,quar,dime,penni;
printf("Enter the purchase under 50$\n");
scanf("%d",&pur);
if(pur>=50){printf("Invalid Entry\n");return 0;}
rem=pur%30;pur=pur-rem;B30=pur/30;
pur=rem;rem=pur%20;pur=pur-rem;B20=pur/20;
pur=rem;rem=pur%10;pur=pur-rem;B10=pur/10;
rem=rem*100;pur=rem;
rem=pur%25;pur=pur-rem;quar=pur/25;
pur=rem;rem=pur%10;pur=pur-rem;dime=pur/10;
penni=rem;
printf("it can be %d bills of 30$, %d bills of 20$, %d bills of 10$\nalso we have %d coins of quarters,%d of dimes,%d penni\n",B30,B20,B10,quar,dime,penni);
return 0;
}