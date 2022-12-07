#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void shift_cipper(char *str){
int n=strlen(str);

for(int i=0;i<n;i++){

    if((str[i]<'x'||str[i]<'X')&&(str[i]<'y'||str[i]<'Y')&&(str[i]<'z'||str[i]<'Z')){
        str[i]+=3;

       } else switch(str[i]){

            case 'X': str[i]='A';break;
            case 'x': str[i]='a';break;
            case 'Y': str[i]='B';break;
            case 'y': str[i]='b';break;
            case 'Z': str[i]='C';break;
            case 'z': str[i]='c';break;
            
        }
    }

}

void sort_by(char *str,int to,int lb){
    int n=strlen(str);
str=(char*)realloc(str,((n+to)+1)*sizeof(char));

    for(int i=n-1;i>(lb+to)i++){
        str[i+to]=str[i];
    }
    
    str[n+to]=0;

    return str;

}

void pflab(char *str,int ub,int lb){
    if(str[lb]=='s'||str[lb+1]==s||str[lb+2]==s)
    {
       strcpy(str,sort_by(str,2,lb));
        str[lb]='P';
        str[lb+1]='F';
        str[lb+2]='L';
        str[lb+3]='a';
        str[lb+4]='b';
    }

}

void change_vow(char *str,int ub,int lb){
    for(int i=lb;i<ub;i++){
        switch(str[i]){
            case 'a':case 'A':
            case 'e':case 'E':
            case 'i':case 'I':
            case 'o':case 'O':
            case 'u':case 'U':
            str=sort_by(str,2,i);
             if(i%2==0){
                str[i]='V';
                str[++i]='O';
                str[++i]='W';
                }
            else {
                str[i]='v';
                str[++i]='o';
                str[++i]='w';
            }
            break;
            
        }
    }
}

void main(){

FILE *fptr=fopen("string.txt","r");

char *str=(char*)malloc(1);
int n=0;char c;
while((c=fgetc(fptr))!=EOF){
    n++;
    str=(char*)realloc(str,n*sizeof(char));
    str[n-1]=c;
}
str=(char*)realloc(str,(n+1)*sizeof(char));
str[n]=0;
int i=0,lb=0;
while(str[i]!='\0'){

    while(str[i]!=32){i++;}
    int ub=i;
    chage_vow(str,ub,lb);

    i++;
    lb=i;
}
 i=0,lb=0;
while(str[i]!='\0'){

    while(str[i]!=32){i++;}
    int ub=i;
    if((ub-lb)==3)pflab(str,ub,lb);

    i++;
    lb=i;
}

    
    shift_cipper(str);


}