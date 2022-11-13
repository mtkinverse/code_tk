#include<stdio.h>

void storevalue(int arr[],int n){
    if(n<=0){
        scanf("%d",&arr[n]);
        return;
    }
scanf("%d",&arr[n]);
storevalue(arr,--n);
}

int calmax(int arr[],int n){
    if(n<=0)return arr[0];
    if(arr[0]<arr[n]){
        arr[0]=arr[n];
    }
    calmax(arr,--n);
}


void main(){
    int n;
printf("\nInput the number of elements and the elements to be stored in array : ");
scanf("%d",&n);
int arr[n];
storevalue(arr,--n);

printf("\nThe maximum value is %d\n",calmax(arr,n));
}