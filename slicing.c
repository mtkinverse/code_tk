#include<stdio.h>
void slice(char *st,int n,int m){
    int i=0;
    while((n+i)<m){
        st[i]=st[i+n];
        i++;
    }
    st[i]='\0';
}
void main(){
char st[]="Tahakhan";
slice(st,1,4);
printf("%s",st);
}