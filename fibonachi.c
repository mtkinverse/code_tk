#include<stdio.h>

int main(){
int n1=1;
int n2=1;
int n,_n;
printf("Enter the number of your fibonachi series\n");
scanf("%d",&n);
if (n==1){printf("%d\n",n1);return 0;}else if(n==2){printf("%d %d\n",n1,n2);return 0;}
printf("%d %d",n1,n2);
for (int i=2;i<n;i++){
_n=n1+n2;
n1=n2;
n2=_n;
printf(" %d",_n);
}
printf("\n");
return 0;
}