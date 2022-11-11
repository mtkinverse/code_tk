#include<stdio.h>

void main(){
int acc,n,i;
float bal,total=0,chg,credit,l_credit;
    printf("Give the account number (-1 to end ): ");
    scanf("%d",&acc);
    if(acc<0)return;
    printf("Enter the beginning balance : ");
    scanf("%f",&bal);
    printf("Enter the number of products you would like to enter : ");
    scanf("%d",&n);
for(i=1;i<=n;i++){
    printf("Enter the charges of the product %d : ",i);
    scanf("%f",&chg);
    total=total+chg;
}
    printf("Enter the total credits : ");
    scanf("%f",&credit);
    bal=bal+total-credit;
    printf("Enter the credit limit : ");
    scanf("%f",&l_credit);
    printf("\nCustomer account : %d\nCredit limit : %.2f\nNew balance : %.2f\n",acc,l_credit,bal);
    if(bal>l_credit)printf("Credit limit exceeded !\n");
    else printf("Credit limit not exceeded\n");
}