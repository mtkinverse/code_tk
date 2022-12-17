#include<stdio.h>
float speed1=50,speed2=70,dist=100,speed_bee=100;

float cal(float val,int n){
    if(n>=3)return speed2;
    if(n==0){
        val=speed_bee;
        return (val*cal(val,++n));
    }
    if(n==1){
        val=dist;
        return cal (val,++n);
    }
    if(n==2){
        return val/=(speed1+cal(val,++n));
    }
}

void main(){
printf("The total distance traveled by the honey is : %.2f m/s\n",cal(0,0));



}