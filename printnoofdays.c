#include<stdio.h>

int main(){
int rem,yrs,month,wk,days;
printf("Give the number of days\n");
scanf("%d",&yrs);
rem=yrs%365;
yrs=yrs-rem;
yrs=yrs/365;
month=rem;
rem=rem%30;
month=month-rem;
month=month/30;
wk=rem;
rem=rem%7;
wk=wk-rem;
wk=wk/7;
days=rem;
printf("It has %d years \n%d months \n%d weeks and \n%d days\n",yrs,month,wk,days);
return 0;
}