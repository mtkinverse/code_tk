#include <stdio.h>
main(){
	int arr[10],i,sum=0;
	char ch;
	printf("Give the array : ");
	for(i=0;i<10;i++){
	scanf("%d",&arr[i]);
	sum+=arr[i];
	}
	printf("The sum of the provided array is %d\n",sum);
}
