#include<stdio.h>
#include<math.h>
void swap(int*x,int*y);
int main(){
    printf("swapping the variable\n");
    int x,y;
    printf("give the value of x\n");
    scanf("%d",&x);
    printf("give the value of y\n");
    scanf("%d",&y);
swap(&x,&y);
printf("the value of x is %d\nthe value of y is %d\n",x,y);
return 0;
}
void swap(int*x,int*y){
int t= *x;
 *x = *y;
*y=t;
}