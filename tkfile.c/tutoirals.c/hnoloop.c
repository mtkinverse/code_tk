#include<stdio.h>

int main(){
    int n;
    printf("Enter the total numbers you want to check\n");
    scanf("%d",&n);
   int arr[n];
printf("Enter your numbers here\n");
for(int i=0;i<n;i++){
    scanf("%d", &arr[i]);
}int ret,x;
for(int i=0,j=0;j<n,i<=n;i++){
    x=(arr[j++]-arr[j]);
    if(x<=0){ret==arr[j]; }else if (x>0){ret==arr[j++];}
    if(j==n){break;}
}
printf("highest number is %d\n",ret);
return 0;}