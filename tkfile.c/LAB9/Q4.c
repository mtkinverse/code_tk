#include<stdio.h>

void checkposition(int marks){
    if(marks>=50&&marks<60)printf("You have been assigned to trainee engineer\n");
    if(marks>=60){
        int exp;
    printf("How many years of experience you have : \n");
    scanf("%d",&exp);
    if(exp==0)checkposition(50);
    else if(marks>=70&&exp>1)printf("You have been assigned the post of Associate developer\n");
    else if(exp==1)printf("You have been assigned the post of Assistant developer\n");
}
}

void main(){

int per,i=1,marks;
printf("How many person will be checked today : ");
scanf("%d",&per);
while((--per)>=0){
    printf("Give the marks of the person %d : ",i++);
    scanf("%d",&marks);
    checkposition(marks);
}


}