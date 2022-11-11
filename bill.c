#include<stdio.h>
void main(){
    int id,units;char name[50];float bill,scharge,p_unit;
    printf("Hi we are calculating the bill\n---------------------------------------\n give the customer number,name,and number of units\n");
    scanf("%d%s%d",&id,&name,&units);
    printf("Customer id: %d\nCustomer name :%s\nUnit consumed:%d\n",id,name,units);
if(units<200){bill=units*1.20;if(bill<100)bill=100;p_unit=1.20;}
else if(units>=200&&units<400){bill=units*1.50;if(bill>400){scharge=bill*0.15;}p_unit=1.50;}
else if(units>=400&&units<600){bill=units*1.80;if(bill>400){scharge=bill*0.15;}p_unit=1.80;}
else if(units>600){bill=units*2.00;if(bill>400){scharge=bill*0.15;}p_unit=2.00;}
printf("Amount charges %.2f per unit:%.2f\nsurcharge amount: %.2f\nnet payable amount:%.2f\n",p_unit,bill,scharge,bill+scharge);

}