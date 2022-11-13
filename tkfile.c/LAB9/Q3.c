#include<stdio.h>
#include<string.h>
void main(){
char s1[50],s2[50],dum;
int i,check;
printf("How many groups are there : ");
scanf("%d",&i);
scanf("%c",&dum);
while((i--)>0){
printf("Give the First string : ");
gets(s1);
printf("Give the Second string : ");
gets(s2);
check=strcmp(s1,s2);
if(check==0) printf("The strings are equal\n");
else if(check==1) printf("The first string is greater than the second one\n");
else printf("The second string is greater than the first one\n");

}
}