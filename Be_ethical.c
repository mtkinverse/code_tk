#include<stdio.h>
#include<string.h>

void main(){
char arr[20];
char *uneth[]={"stupid","ugly","pathetic","Alas"};
char *eth[]={"the great","vibrant","shiny","Wow"};

printf("enter an input string and receive the output string\n");

while(1){
    if((scanf("%s",arr))==0)break;
    for(int i=0;i<4;i++){
        if(strcmp(arr,uneth[i])==0)strcpy(arr,eth[i]);
    }
    printf("%s ",arr);
}



}