#include <stdio.h>
int main(){
int a,b,c,d,e,lrge;
int x1,x2,x3,x4,x5,x6,x7,x8;
printf("enter your number here\n");
scanf("%d%d%d%d%d",&a,&b,&c,&d,&e);
x1=(a-b);if (x1>0){x2=a;}else if (x1<=0){x2=b;}
x3=(x2-c);if (x3>0){x4=x2;}else if(x3<=0){x4=c;}
x5=(x4-d);if (x5>0){x6=x4;}else if(x5<=0){x6=d;}
x7=(x6-e);if (x7>0){lrge=x6;}else if(x7<=0){lrge=e;}
printf("highest number is %d\n",lrge);
    return 0;
}