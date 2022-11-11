#include<stdio.h>

int main(){
int num,sum=0;
printf("Give the number\n");
scanf("%d",&num);
for(int i=1;i<num;i++){
    if(num%i==0){sum=sum+i;}else{continue;}
}if(num==sum){printf("The given integer %d is perfect\n",num);}else{printf("the given integer is not perfect\n");}
return 0;
}