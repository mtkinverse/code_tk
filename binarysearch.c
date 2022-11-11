#include<stdio.h>

void main(){
// printf("Give the number of elements from which you want ot share : ");
// scanf("%d",&n);
int l=0,n=0,var;
int arr[]={25,63,35,15,26,78,1,12,26};
while(arr[l++]!='\0'){
    n++;
}

///First sorting the array

for(int j=1;j<=(n-l);j++,l++){
    for(int i=0;i<n;i++){
        if(arr[i]>arr[l]){
            var=arr[l];
            arr[l]=arr[i];
            arr[i]=var;
        }
    }
}
for(int i=0;i<n;i++)printf("%d",arr[i]);
int lb=0,ub=n,mid;
printf("Give the variable you want to check : ");scanf("%d",var);
while(var!=mid){
    mid=ub/2;
    for(int i=lb;i<ub;i++){
    if(var<arr[mid])ub=mid-1;
    else if(var>arr[mid])lb=mid+1;
    if(arr[mid]==arr[lb]||arr[mid]==arr[ub]){
        printf("No matchings available \n");return;
    }
    }
}
printf("It is the %d element of array\n",mid+1);
}