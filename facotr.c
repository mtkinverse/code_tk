#include<stdio.h>

int main(){
int num,sum=0;
printf("Give the number\n");
scanf("%d",&num);
if(num<0){printf("Invalid Entry\n");return 0;}
else if(num==0){printf("No factors\nThe sum of the series of the factors is 0\n");}
printf("The factors of the given number are :");
for(int i=1;i<num;i++){
    if(num%i==0){printf("%d",i);sum=sum+i;printf(",");}else{continue;}
}printf("%d",num);sum=sum+num;
printf("\nThe sum of the series of the facotrs is %d\n",sum);
return 0;
}