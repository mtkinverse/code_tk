#include<stdio.h>
int worker(int cal[],int n);
int officer(int cal[],int n);
int peon(int cal[],int n);
int sweeper(int cal[],int n);
int main(){
    printf("Welcome to salary checker\nenter 0 to exit\n");
    int g;
        printf("enter password\n");
        scanf("%d",&g);
        if(g==4581){
    int n;
    printf("enter the total days you were present\n");
    scanf("%d",&n);
    if (n<=30){
    int cal[]={30,n};
    int cls;
    printf("enter your status\n1 for worker\n2 for officer\n3 for peon\n4 for sweeper\n");
    scanf("%d",&cls);
    switch(cls){
        case 1: 
printf("total days:30\ndays you present:%d\nallounce:2000\nfund detected:1000\n",n );
        worker(cal,n);
printf("your salary is: %d\n",worker(cal,n));break;
case 2:
printf("total days:30\ndays you present:%d\nfund detected:3000\n",n );
officer(cal,n);
printf("your salary is: %d\n",officer(cal,n));break;
case 3:
printf("total days:30\ndays you present:%d\nallounce=\n",n );
peon(cal,n);
printf("your salary is: %d\n",peon(cal,n));break;
case 4:
printf("total days:30\ndays you present:%d\nallounce:2000\n",n );
sweeper(cal,n);
printf("your salary is: %d\n",sweeper(cal,n));break;
}}else{printf("invalid entry\n");main();}

}else if(g==0){
    printf("you have ended the program THANKS\n"); return 0;
}else{printf("invalid entry\n");main();}
main();
return 0;
}
int worker(int cal[],int n){
    int spd=1600;
    int tdays=cal[0]-(cal[0]-cal[1]);
    int tsalary=spd*tdays +1000;
    return tsalary;
}
int officer(int cal[],int n){
    int spd=5000;
    int tdays=cal[0]-(cal[0]-cal[1]);
    int tsalary=spd*tdays -3000;
    return tsalary;}
    int peon(int cal[],int n){
    int spd=650;
    int tdays=cal[0]-(cal[0]-cal[1]);
    int tsalary=spd*tdays +2000;
    return tsalary;}
    int sweeper(int cal[],int n){
    int spd=400;
    int tdays=cal[0]-(cal[0]-cal[1]);
    int tsalary=spd*tdays +2000;
    return tsalary;}