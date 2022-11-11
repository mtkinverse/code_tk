#include<stdio.h>
void main(){
int ice=60,ice_hr=50,no_ice,cost,days,hr,check,acost=0,rem;
float s;
printf("Give the number of icecreams : ");
scanf("%d",&no_ice);
printf("Do you want to run the machine in 16 hours or 8 hours\nEnter 8,16 : ");
scanf("%d",&check);
switch(check){
case 8:
days=no_ice/400;
hr=no_ice%400;
s=hr/50.0;
cost=no_ice*ice;
printf("It will take %d days and %.2f hours\nThe cost is : %d\n",days,s,cost);
break;
case 16:
days=no_ice/800;
hr=no_ice%800;
s=hr/50.0;
rem=no_ice%400;no_ice-=rem;
if(no_ice>400){
cost=((400*days)+rem)*60;
acost=(no_ice-(400*days))*(120);}
else cost=no_ice*ice;
printf("It will take %d days and %.2f hours\nCost for %d icecreams in 8 hours : %d\nCost for %d icecreams in other 8 hours : %d\nThe cost is : %d\n",days,s,no_ice-(400*days)+rem,cost,no_ice-(400*days),acost,cost+acost);
break;	

}
}
