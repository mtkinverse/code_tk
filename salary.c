#include<stdio.h>

int main(){
int salary=0,overtime,pay_hours,hours;
printf("Enter the hours you worked\n");
scanf("%d",&hours);
printf("Enter the pay per hour\n");
scanf("%d",&pay_hours);
salary=pay_hours*hours;
if(hours>40){overtime=pay_hours*(1.5*(hours-40));salary=salary+overtime;
printf("your salary is with bonus %d\n",salary);
 }else{printf("your salary is %d",salary);}
return 0;
}