#include<stdio.h>
int arr[]={0,1,0,1,0,1,0,1,0,1};

int sum_it(int n){

if(n<=0)return 0;
else return arr[n]+sum_it(n-2);

}

void main(){

int n=sizeof(arr)/sizeof(int);
printf("The sum of the elements of array is \n");
if(n%2==0)
    printf("Even index : %d\nOdd index : %d\n",sum_it(n-1),sum_it(n-2));
    else 
    printf("Odd index : %d\nEven index : %d\n",sum_it(n-1),sum_it(n-2));

}