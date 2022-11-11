#include<stdio.h>
#include<conio.h>
#include<windows.h>
#include<unistd.h>
void printscreen(int count[],int a);
int ticketcheck(int count[],int a);
int maxcount(int count[],int a);
void printscreen(int count[],int a){system("cls");
printf("ONE STOP STUDENT FACILATING CENTRE\n");
printf("          CURRENTLY SERVING         \n");
printf("|----------|------------|-----------|\n");
printf("| COUNTER 1| COUNTER 2  | COUNTER 3 |\n");
printf("|----------|------------|-----------|\n");
printf("|    %d     |     %d      |     %d     |\n",count[0],count[1],count[2]);
printf("|__________|____________|___________|\n");
printf("press T to get ticket\nPress C for checking your ticket\n");
}

int ticketcheck(int count[],int a){int no_ticket,q=maxcount(count,a);
    system("cls");printf("Give the number of your tocken\n");
    scanf("%d",&no_ticket);
    for(int i=0;i<=2;i++){
        if(no_ticket==count[i])return ++i;
    }if(no_ticket<q)return 0;
    else return -2;
}
int maxcount(int count[],int a){
    if(count[0]>count[1]){
        if(count[0]>count[2])return (1+count[0]);
        else return(1+count[2]);
    }else if(count[1]>count[2])return(1+count[1]);
    else return(1+count[2]);
}
                      void main(){char checker;int ticket[500],count[]={0,0,0};int check,a=3;
int t=0;
    for(int i=0,j=1;i<=499;i++,j++){
ticket[i]=j;
    }
    while(count[t]!=500){
    printscreen(count,a);
    scanf(" %c",&checker);
switch(checker){
    case 't':
    case 'T':system("cls");
    printf("your ticket number is %d",ticket[t]);++t;
    sleep(2);
    printscreen(count,a);
    break;
    case 'c':
    case 'C':
    system("cls");
    check=ticketcheck(count,a);
    if(check==1||check==2||check==3)printf("Go to the counter %d\n",check);
    else if(check==0)printf("Your turn has passed away\n");
    else printf("Wiat for your turn\n");sleep(2);printscreen(count,a);
    break;
    case 'W':case 'w':
    if((maxcount(count,a)>=ticket[t])){printf("Tickets are not available\n");
    }else count[0]=maxcount(count,a);
    sleep(2);printscreen(count,a);
    break;
    case 'a':case 'A':
    if((maxcount(count,a)>=ticket[t])){printf("Tickets are not available\n");
    }else count[1]=maxcount(count,a);
    sleep(3);printscreen(count,a);
    break;
    case 'd': case 'D':
    if((maxcount(count,a)>=ticket[t])){printf("Tickets are not available\n");
    }else count[2]=maxcount(count,a);
    sleep(2);printscreen(count,a);
    break;
    default:printf("Give the right option\n");system("cls");
    sleep(2);
}}
}