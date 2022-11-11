#include<stdio.h>
void main(){
    int sel,sal,bonus;
    float sum=0;
   while(sal>60000){
printf("Give the basic salary :");
scanf("%d",&sal);
if(sal>60000){
printf("Enter the amount you sale today : ");
scanf("%d",&sel);
if(sel>=10000000)bonus=(float) sel*0.035;
else bonus=(float)sel*0.02;
printf("Your salary is %d  $\nIn which the bonus is %d $\n",sal+bonus,bonus);
sum=sum+(sal+bonus); 
}printf("Program has been ended\n");
   }
   printf("The net salary is %.2f\n",sum); 
}