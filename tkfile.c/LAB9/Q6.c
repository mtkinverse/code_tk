#include<stdio.h>

float calvol(int h,int a){
    return (float)(a*a)*0.33*h;
}

float getdata(int h,int a){
    printf("Give the value of height(h) : ");
    scanf("%d",&h);
    printf("Give the value of a : ");
    scanf("%d",&a);
    return calvol(h,a);
}

void main(){
    int h,a;

float vol=getdata(h,a);
printf("The volume of the cone is %.2f units\n",vol);

}