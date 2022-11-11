#include<stdio.h>
void main(){
	int no1,no2;
	printf("Give the first number\n");
	scanf("%d",&no1);
	printf("Give the second number\n");
    scanf("%d",&no2);
    if(no2==0){printf("Qotient not possible\nThe sum of the numbers is %d \nsubraction is %d\nproduct is %d\nreminder is %d",no1+no2,no1-no2,no1*no2,no1%no2); }
    else{printf("The sum of the numbers is %d \nsubraction is %d\nproduct is %d\nquotient is %d\nreminder is %d",no1+no2,no1-no2,no1*no2,no1/no2,no1%no2);
    }
}