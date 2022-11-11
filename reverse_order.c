#include<stdio.h>

int main(){
char char1='A',char2='B',char3='C';
// scanf("%c",&char1);
// scanf("%c",&char2);   why characters are always unable to scan perfectly
// scanf("%c",&dummy);
// scanf("%c",&char3);
printf("The reverse order of %c%c%c is %c%c%c\n",char1,char2,char3,char3,char2,char1);

return 0;
}