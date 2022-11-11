#include<stdio.h>
void main(){
    int check,n,a,b,rem,msg;
    char ch1,ch2,ch3,ch4;
    printf("Hi and welcome to the Cryptography\nDo you want to encrypt or decrypt the code ?\n1- Encryption\n2- Decryotion\n");
    scanf("%d",&check);
    switch(check){
        case 1:
        printf("Give the string : ");
        scanf("%d",&msg);
        printf("The Envrypted message would be : ");
        while(1){
		a=msg%10;
		msg=msg/10;if(msg<=0){printf("%c",65+a);break;}
		b=msg%10;
		msg=msg/10;
        rem=(a*10)+b;
		if(rem<26&&a>0){printf("%c",rem+65);
			}else{printf("%c%c",a+65,b+65);}
		}
        break; 
        case 2:
               printf("Give the code you want to deccrypt : ");
               scanf(" %c%c%c%c",&ch1,&ch2,&ch3,&ch4);
               ch4-=65;rem=ch4%10;printf("%d",rem);ch4=ch4/10;if(ch4>0)printf("%d",ch4);
               ch3-=65;rem=ch3%10;printf("%d",rem);ch3=ch3/10;if(ch3>0)printf("%d",ch3);
               ch2-=65;rem=ch2%10;printf("%d",rem);ch2=ch2/10;if(ch2>0)printf("%d",ch2);
               ch1=ch1-65;rem=ch1%10;printf("%d",rem);ch1=ch1/10;if(ch1>0)printf("%d",ch1);
        break;
        default :printf("Invalid Entry\n");

    }printf("\n");
}