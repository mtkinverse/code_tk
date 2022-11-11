#include<stdio.h>
void swap(char value[],int n);
int main(){
int n=2;
printf("swapping the variable\n");
char value[100];
printf("give the value of x\n");                    //INCOMPLETE UNSATISFIED
scanf("%c",&value[0]);
printf("give the value of y\n");
scanf("%c",&value[1]);
swap(value,n);
printf("the value of x is %c and the value of y is %c \n",value[0],value[1]);
char j;
printf("press enter to exit or press any key to start the program again\n");
scanf("%c",&j);
if(j=='\n'){printf("ended\n");return 0;}else{
main();}
    return 0;
}
void swap(char value[],int n){
    char t=value[0];
    value[0] = value[1];
    value[1] = t;
}