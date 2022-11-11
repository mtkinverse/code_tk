#include<stdio.h>

void main(){
int var,l=0,arr[]={6,3,2,5,7,0};
int n=sizeof(arr)/sizeof(int);
for(int j=0;j<n;j++,l++){
for(int i=0;i<n-l;i++){
    if((arr[i+1]-arr[i])<0){
        var=arr[i+1];
        arr[i+1]=arr[i];
        arr[i]=var;
    }
}
}
printf("The sorted array is : ");
for(int i=0;i<n;i++)printf("%d ",arr[i]);

}