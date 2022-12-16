#include<stdio.h>
void f(void){
    char c;
    if((c=getchar())!='\n'){
        f();
        printf("%c",c);
    }else return;
}
void main(){
printf("Give the string\n");
f();
puts("");


}