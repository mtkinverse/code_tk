#include<stdio.h>
void main(){
    int B=200,F=50,P=500,S=150,type,bquan,pquan,fquan,squan,bprice,pprice,fprice,sprice,price=0,checkb=0,checkp=0,checkf=0,checks=0;
    char ord;
    printf("\n\n               MTK Online Resturant System\n");
    printf("                          WELCOME !\n\n");
    printf("B- Burger (RS. %d)\nF- French Fries (RS. %d)\nP- Pizza (RS. %d)\nS- Sandwich (RS. 150)\n",B,F,P,S);
    printf("How many types of snacks you want to order : ");
    scanf("%d",&type);
    for(int i=1;i<=type;i++){
        printf("Enter snack %d you want to order : ",i);
        scanf(" %c",&ord);
        switch(ord){
            case 'B':bprice=B;checkb=B;
            printf("Enter Quantity : ");
        scanf("%d",&bquan);
        if(bquan<0||bquan==0)printf("Invalid Entry\n");
        else price=price+bprice*bquan;
        break;
            case 'F':fprice=F;checkf=F;
            printf("Enter Quantity : ");
        scanf("%d",&fquan);
        if(fquan<0||fquan==0)printf("Invalid Entry\n");
        else price=price+fprice*fquan;
            break;
            case 'P':pprice=P;checkp=P;
            printf("Enter Quantity : ");
        scanf("%d",&pquan);
        if(pquan<0||pquan==0)printf("Invalid Entry\n");
        else price=price+pprice*pquan;
            break;
            case 'S':sprice=S;checks=S;
            printf("Enter Quantity : ");
        scanf("%d",&squan);
        if(squan<0||squan==0)printf("Invalid Entry\n");
        else price=price+sprice*squan;
        break;
        default: printf("Please Restart and provide Correct letters\n");
        }}
        printf("\n---------------------------------------------------------------------------------\nYou have ordered !\n");
        
        if(checkb==B){printf("%d Burger (s) value : %d PKR\n",bquan,bquan*B);}
        if(checkf==F){printf("%d French Fries (s) value : %d PKR\n",fquan,fquan*F);}
        if(checkp==P){printf("%d Pizza (s) value : %d PKR\n",pquan,pquan*P);}
        if(checks==S){printf("%d Sandwiches (s) value : %d PKR\n",squan,squan*S);}
        
    printf("Total : %d PKR\n\nThanks for the placement of order .. Have a nice day\n\n",price);
}
