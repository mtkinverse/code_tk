#include<stdio.h>

int main(){
int arr[100],num,dum,rem,a,b,c,sum=0;
printf("Give the number you want to check\n");
scanf("%d",&num);dum=num;
for(int i=0;i<num;i++){
    rem=num%10;arr[i]=rem;
    num=num-rem;num=num/10;
    arr[i]=arr[i]*arr[i]*arr[i];
    sum=sum+arr[i];if(num==0){break;}
}if(sum==dum){printf("The %d is cuboid\n",dum);}else{printf("The number is not cuboid\n");}
return 0;
}