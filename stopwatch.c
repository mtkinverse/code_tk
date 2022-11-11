#include<stdio.h>
#include<windows.h>
#include<unistd.h>
void main(){
int min,hour,sec,ap,h2,min2,sec2;
printf("Give on which the SMALLEST hand lie: ");
scanf("%d",&hour);
printf("press 1 for pm\npress 2 for am\nNOTE : if you want to enter 12pm press 2 \n");
scanf("%d",&ap);
switch(ap){
    case 2:break;
    case 1:
    hour=12+hour;break;
    // default:printf("invalid Entry\n");break;
}
printf("Give the value on shich LARGER hand lie : ");
scanf("%d",&min);min=min*5;
printf("Give the value on which LARGEST hand lie : ");
scanf("%d",&sec);sec=sec*5;
printf("Give the stopping time :");
scanf("%d:%d:%d",&h2,&min2,&sec2);
for(int i=1;i<=24;i++){
    if(hour>=24){hour=0;i=24;}
    for(int i=1;i<=60;i++){
        if(min>=60){min=0;i=60;}
        for(int i=1;i<=60;i++){
            if(sec>=60){sec=0;i=60;}
            sleep(1);system("cls");
            printf("%d:%d:%d",hour,min,sec);
            if(hour==h2&&min==min2&&sec==sec2){printf("\nThe time is Ended\n");return;}
            sec++;
        }
        min++;
    }
    hour++;
}
}