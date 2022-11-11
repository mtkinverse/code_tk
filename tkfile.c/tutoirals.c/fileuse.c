#include<stdio.h>    /// Intputting string from user to no.txt furthure the text of atset.txt is also copied
void vow(char new[100]);
char printwel(char wel[100]);
int main(){
    FILE *fptr;
    fptr = fopen("no.txt","r");
    char ch;
    ch=fgetc(fptr);
    while(ch != EOF){    ///taking input character by character
        printf("%c",ch);
        ch = fgetc(fptr);
    }
printf("\n");
    fclose(fptr);
    fptr = fopen("no.txt","w");//to ad  the material and not to erase the existing one
    char new[100];             // just repalce w with a 
    printf("give the text you want to add\n");
    fgets(new,100,stdin);
    fprintf(fptr,"%s",new);
    fclose(fptr);
    vow(new);
    printf("\n");
    fptr = fopen("atest.txt","r");
    char atest[100];
     fgets(atest,100,fptr);// inputting whole text from atest.txt by just 
    fclose(fptr);             //replacing stdin from fptr in fgets function not fgetc function
    fptr = fopen("no.txt","a");
    fprintf(fptr,"%s",atest);  //idf you want to completely replace the materoial from a test
    fclose(fptr);              //stored in atest[100] just replace a(append) with w(write)
    return 0;
}
void vow(char new[100]){
    int count = 0;
    char x;
for(int i=0;i <= 100;i++) {
    x = new[i];    
    if(x=='a' || x=='e' || x=='i' || x=='o' || x=='u' ){
        count++;
    }
    }printf("it contains %d vowels\nwhich  are\t",count);
    char m;
    int j;
    char wel[100];
    for( j=0; j<=100; j++){
        m=new[j];if (m=='\0'){return;}else if(m=='a' || m=='e' || m=='i' || m=='o' || m=='u' ){
        printf("%c,",m);
        m=wel[j];
        }
    }
}