#include<stdio.h>

struct date{
    int day,month,year;
}d;

void main(){
printf("Gve the present date (DD:MM:YY) : ");
scanf("%d:%d:%d",&d.day,&d.month,&d.year);
printf("GIVEN DATE : %d:%d:%d\nGive the days you want to add : ",d.day,d.month,d.year);
int end;
scanf("%d",&end);
for(int i=1;i<=end;i++){

 d.day++;

 if(d.month<=7){

    if(d.month%2==0){
       if(d.day>30){d.month++;d.day=1;}
    }else if(d.day>31){d.month++;d.day=1;}

 }else if(d.month<=12){
    if(d.month%2==0){
        if(d.day>31){d.month++;d.day=1;}
    }else if(d.day>30){d.month++;d.day=1;}
 }
if(d.month>12){
    d.month=1;
    d.year++;
    }   
}
printf("The present date is : %d:%d:%d\n",d.day,d.month,d.year);

}