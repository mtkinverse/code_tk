#include<stdio.h>
void main(){
	int arr[]={1,3,64,98,45,56,12,0,35};
	int j,i,n,var,lb=0,ub=(sizeof(arr)/sizeof(int)),mid=ub/2,key;
	printf("The present array is : ");
	for(i=0;i<ub;i++)printf("%d ",arr[i]);
	printf("\nAfter sorting it is : ");
	n=ub;
	for(j=0;j<ub;j++,n--){
		for(i=lb;i<n;i++){
			if(arr[i]>arr[i+1]){
				var=arr[i+1];
				arr[i+1]=arr[i];
				arr[i]=var;
			}
		}
	}
	for(j=lb;j<ub;j++)printf("%d ",arr[j]);
	printf("\nGive the value you want to trace in the array : ");
	scanf("%d",&key);
	while(key!=arr[mid]){
		if(key<arr[mid])ub=mid-1;
		else if(key>arr[mid])lb=mid+1;
		if(mid==lb||mid==ub){
		printf("Value does not found\n");return;}
		mid=(ub+lb)/2;
	}
	printf("The value is found at index %d OR %d location\n",mid,mid+1);
}	