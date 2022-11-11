#include<stdio.h>
#include<string.h>
int count(char name[100]);
int length(char name[100]);
int main(){
   printf("HI and welcome to the counter\n");
    char name[100];
    printf("enter your word here\n");
    fgets(name,100,stdin);
    printf("it has a lenght of %d\nit contains %d vowels\nwith %d consonants\n",length(name),count(name),length(name)-count(name));  
    printf("\n\tprinting character length with strlen\n");
    int x=strlen(name);
    printf("it has a lenght of %d\nit contains %d vowels\nwith %d consonants\n",x-1,count(name),length(name)-count(name));  

    char n;
    printf("enter to start the program again OR enter any key to exit\n");
    scanf("%c",&n);
 if(n=='\n'){
    main();
    }else{return 0;}
    return 0;
}
int length(char name[100]){
    int count=0;
    for(int i=0;name[i]!='\0';i++){
        count++;
    }return count-1;
}
int count(char name[100]){
    int count=0;
    for(int i=0;name[i]!='\0';i++){
        if (name[i]=='a'||name[i]=='e'||name[i]=='i'||name[i]=='o'||name[i]=='u'){
            count++;
        }
    }return count;
}