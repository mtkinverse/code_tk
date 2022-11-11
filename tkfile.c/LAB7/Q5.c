#include<stdio.h>

void main(){
int check,num,rem=0,new;
char a,b,c,d,e;
printf("Give the type of data\n1-numeric\n2-Textual\n3-Symbols\n");
scanf("%d",&check);
switch(check){
    case 1:
    printf("Give the number : ");
    scanf("%d",&num);
    new=num;
    while(num>0){
        check=num%10;
        num/=10;
        check=check*check*check;
        rem=rem+check;
    }if(rem==new)printf("It is an argstorm number\n");
    else printf("It is not an argstorm number\n");
    break;
    case 2:
    printf("GIve the charcacters : ");
    scanf(" %c%c%c%c%c",&a,&b,&c,&d,&e);
    if(a==e&&b==d)printf("The given text is palindrone\n");
    else printf("It is not a palindrone\n");
    break;
    case 3:
    printf("give the character : \n");
    scanf(" %c",&a);
    for(b=1;b<=5;b++){
        for(c=1;c<=5;c++){
            if((b>1&&b<5)&&(c>1&&c<5))printf("  ");
            else printf("%c ",a);
        }printf("\n");
    }
     break;
    default:printf("Invalid entry\n");
}



}