#include<stdio.h>
void main(){
    int n;
    printf("Give the size of the array : ");
    scanf("%d",&n);
int arr[n],i,j;
for( i=0;i<n;i++){
    printf("Give the element %d : ",i+1);
    scanf("%d",&arr[i]);
}
printf("The value ");
for( j=0;j<8;j++){
for( i=0;i<8;i++){
    if(arr[j]==arr[i]&&arr[i]!=-1&&i!=j){
        printf("%d ",arr[i]);
        arr[i]=-1;
    }   
}
}
for(i=0;i<8;i++){
if(arr[i]==-1){
printf("occurs more than once\n");
return;
}
}printf("do not repeated\n");
}