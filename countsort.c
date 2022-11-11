#include<stdio.h>

void main(){
int arr[]={9,1,3,6,8,2,2,5};
int max=arr[0],n=sizeof(arr)/sizeof(int);
printf("The current array is : ");
for(int i=1;i<n;i++){
   if(max<arr[i])max=arr[i];printf("%d ",arr[i]);
}
//Finding the maximum value from the give array and initializing second array 
//to max+1 size so that is can store count of all values from arr[i] in its index
max++;
//here it is saying that we cannot initialize the variable sized array with 0 thats why I am initialzing it with 10(value of max)
int a=0,newarr[10]={0};
for(int i=0;i<n;i++){
    ++newarr[arr[i]];
}
for(int i=0;i<max;i++)
   printf("%d ",newarr[i]);
int sum=0;
for(int i=0;i<max;i++){
 sum+=newarr[i];
 newarr[i]=sum;
}printf("\n");
for(int i=0;i<max;i++)
 printf("%d ",newarr[i]);
max=0;
int aux[n];printf("\nAuzilary nhi ho gya\n");
for(int i=0;i<n;i++){
   max=newarr[arr[i]]-1;
   aux[max]=arr[i];
   --newarr[arr[i]];
}
printf("The sorted array is : ");
for(int i=0;i<n;i++)printf("%d ",aux[i]);


}