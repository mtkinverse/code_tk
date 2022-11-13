#include<stdio.h>

void storevalue(int arr[],int n){
if(n<=0){
    scanf("%d",&arr[0]);
    return;}
scanf("%d",&arr[n]);
storevalue(arr,--n);
}

int calmax(int arr[],int n,int max){
    if(n<=0)return max;
    if(max<arr[n])max=arr[n];
    calmax(arr,--n,max);
}

int calmin(int arr[],int n,int min){
    if(n<=0)return min;
    if(min>arr[n])min=arr[n];
    calmin(arr,--n,min);
}

void main(){
int n;
printf("\nGive the number of values you want to enter in the array : ");
scanf("%d",&n);
int arr[n];
storevalue(arr,--n);
int max=arr[0],min=arr[0];
printf("The maximum value is %d\n",calmax(arr,n,max));
printf("The minimum value is %d\n",calmin(arr,n,min));


}