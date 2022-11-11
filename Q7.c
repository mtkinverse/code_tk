#include<stdio.h>
void main(){
int i,j,n,num,sum=0;
printf("Give the size of the array : ");
scanf("%d",&n);
int arr[n];
printf("Give the number : ");
scanf("%d",&num);
printf("Give the elements of the array\n");
for( i=0;i<n;i++){
    printf("Give the element %d : ",i+1);
    scanf("%d",&arr[i]);
}
for( j=0;j<n;sum=0,j++){
    for( i=j;i<n;i++){
        sum+=arr[i];
        if(sum==num){
            printf("The sum of elements %d to %d gives %d\n",j+1,i+1,num);
            return;
        }
    }
}
printf("The value does not found by sum of any element\n");

}