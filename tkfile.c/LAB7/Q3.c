#include<stdio.h>

void main(){
    int x;
    float  time,vit=0;
    char ch;
printf("Gieve the time you stay under sun : ");
scanf("%f",&time);
if(time>50)
{x=time-50;
    vit=vit+0.50*(time-x);
}else if(time>0)vit=0.50*time;
time=time-50;
if(time>100){
    x=time-100;
    vit=0.50*(time-x);
}else if(time>0)vit=vit+0.75*time;
    time=time-100;
if(time>100){
    x=time-100;
    vit=1.20*(time-x);
}else if(time>0) vit=vit+1.20*time;
    time=time-100;
if(time>0){
    vit=vit+1.50*time;
}
printf("Is it a summer season ?\nyes or no (y,n) : ");
scanf(" %c",&ch);
switch(ch){
    case 'Y':case 'y':
    vit=vit+(vit*0.20);
    break;
}
printf("The total vitamin consumed is %.2f Cal\n",vit);
}