#include<stdio.h>
void main(){
    int no,age,gen,ans,rem=0;
    printf("Input a four digit number : ");
    scanf("%d",&no);
    printf("Enter your age : ");
    scanf("%d",&age);
    printf("Enter your gendre\n1-Male\n0- Female\n");
    scanf("%d",&gen);
    no=no+age+gen;
    for(int i=0;i<4;i++){
        rem=rem+(no%10);
        no=no/10;
    }
    rem=rem%5;
    printf("Give your verification code : ");
    scanf("%d",&ans);
    if(ans==rem)printf("Correct\n");
    else printf("Incorrect\n");
}