#include<stdio.h>
#include<string.h>
void main(){
	printf("Give the first name : ");
	char st1[50];
	scanf("%s",st1);
	printf("Give the last name : ");
	char st2[20];
	scanf("%s",st2);
	strcat(st1,st2);
	int i=0,n=strlen(st1)-1;
   for(i=0;i<=n/2;i++){
   	char var=st1[0+i];
   	st1[0+i]=st1[n-i];
    st1[n-i]=var;
   }
   puts(st1);
	
}