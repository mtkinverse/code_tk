#include<stdio.h>
#include<windows.h>
#include<unistd.h>
void main(){char ch1=':';int secs,min,hour;
printf("Give the value at which second's hand lies\n");
scanf("%d",&secs);if(secs>12){printf("Invalid entry\n");return;}secs=secs*5;
printf("Give the value on which minute's hand lies\n");
scanf("%d",&min);if(min>12){printf("Invalid Entry\n");return; } min=min*5;
printf("Give the value on which small hand lies\n");
scanf("%d",&hour);if(hour>12){printf("Invalid Entry\n");return;}
for(int i=1;i<13;i++){
    if(i>=12)i=1;
    //printf("%d",hour);
    if (hour>=12){hour=0;}
    for(int i=1;i<61;i++){//if(i==60)i=0;
        //printf("%c%d",ch1,min);
        if(min>=60){min=0;i=61;}
        for(int i=1;i<=60;i++){if(secs>=60){secs=0;i=61;}
            system("cls"); printf("%d%c%d%c%d",hour,ch1,min,ch1,secs);secs++;
            sleep(1);
        }
        min++;
    }
    hour++;
}




}