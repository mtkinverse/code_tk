#include<stdio.h>
void main(){
     char ch;int countl=0,countv=0,countc=0;
    while(ch!=13){
        ch=getch();printf("%c",ch);
        if(ch=='a'||ch=='e'||ch=='i'||ch=='o'||ch=='u')countv++;
        else countc++;
        if(ch!=32) countl++;
    }printf("you have typped %d characters out of which %d are vowels and %d are consonants\n",countl,countv,countc);
    while((ch=getche())!=13){
        if(ch=='a'||ch=='e'||ch=='i'||ch=='o'||ch=='u')countv++;
        else countc++;
        countl++;
    }printf("you have typped %d characters out of which %d are vowels and %d are consonants\n",countl,countv,countc);

    while((ch=getch())!=13){
        if(ch=='a'||ch=='e'||ch=='i'||ch=='o'||ch=='u')countv++;//IT will take input but do not print it
        else countc++;
        countl++;
    printf("you have typped %d characters out of which %d are vowels and %d are consonants\n",countl,countv,countc);
}
//PRINTING THE ASCII VALUES OF CHARACTERS
while((ch=getch())){
    printf("%c , %d\n",ch,ch);
}
}