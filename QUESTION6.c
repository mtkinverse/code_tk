#include<stdio.h>
void main(){
    int week,vac;
    printf("\n-> HI kindly acknowledge me if it is a weekday\n1. YES\n2. NO\nEnter your choice (1,2) :");
    scanf("%d",&week);
    printf("\n-> Are there vications\n1. YES\n2. NO\nEnter choice (1,2): ");
    scanf("%d",&vac);
    if((week==2&&vac==1)||(week==1&&vac==1)||(week==2&&vac==2))printf("\t\t\tTRUE\n");
    else printf("\t\t\tFALSE\n");
}