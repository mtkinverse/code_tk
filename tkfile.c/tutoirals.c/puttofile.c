#include<stdio.h>
int main(){
FILE *fptr;
fptr=fopen("hello.c","a");
char text[100];
//printf("enter the text you want to add\n");
fgets(text,100,fptr);
//fprintf(fptr,"%s",text);
fclose(fptr);
puts(text);printf("\n");
    return 0;
}