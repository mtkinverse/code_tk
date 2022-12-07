#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
#include<conio.h>
#include<windows.h>

void gotoxy(int x,int y){
    COORD CRD;
    CRD.X=x;
    CRD.Y=y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),CRD);
}

struct log_info{
   char name[20],pass[20],id[20],uname[20];
   int lev;
}a;

char checker[20];
int check;

int check_id(char *str){
struct log_info var; 
    FILE *search=fopen("logininfo.bin","rb");

    if(search==NULL) {
        printf("Error Exist\n");
        exit(0);
        }
exit(0);
    while(!(feof(search))){
        fread(&var,sizeof(struct log_info),1,search);
        if(strcmp(var.id,str)==0){
            fclose(search);
            free(search);
            return 1;}
    }
    
    return 0;

}

char* get_string_nospace(){
    int ind=0;char c;
    char *pas1=(char*)malloc(sizeof(char));

            while((c=getche())!=13){

            if((c>='A'&&c<='Z')||(c>='a'&&c<='z')){
                ind++;
                if(ind>=19){
                    // gotoxy(10,10);
                    // printf("Note number of characters Exceeded !\n");
                    ind=18;
                }
                pas1=(char*)realloc(pas1,ind*sizeof(char));
                pas1[ind-1]=c;
                //  gotoxy(20,20);
                //  printf(" \r");
                }
                
            else{
                //  gotoxy(20,30);
                //  printf("Note donot Enter any character other than Alphabets and  some special characters (%c,%c,%c,%c,%c)",58,59,60,61,62);    

                 if(c==8){
                    ind--;
                    if(ind>0){
                    printf(" \b");
                    pas1=(char*)realloc(pas1,ind*sizeof(char));

                    }else ind=0;
                 }if(c==32)printf("\b");
                }
            }
puts("");
            return pas1;
}

char* assign_id(){


    char *id=(char*) calloc(6,sizeof(char));
    do{
    srand(time(NULL));
    for(int i=0;i<5;i++){
        id[i]=48+rand()%43;
    }
    id[6]=0;
    }while(check_id(id));
    return id;

    
}

void encrypt_pass(char *arr){

  int n=strlen(arr);
  int mb=(n+4)/2;
puts("\ninencryption");
  arr=(char*) realloc(arr,(n+4)*sizeof(char));
puts("\ninencryption");

  for(int i=(n+4)-1;i>(mb+4);i--){
     arr[i]=arr[i-4];
  }

puts("\ninencryption");
  arr[mb+1]='0';
  arr[mb+2]='t';
  arr[mb+3]='k';
  arr[mb+4]='0';
  
puts("teh current encrypted stirng : ");puts(arr);
    switch(arr[0]){

       case 'a':case 'A':  
       case 'e':case 'E':  
       case 'i':case 'I':  
       case 'o':case 'O':  
       case 'u':case 'U':  
puts("teh current encrypted stirng : ");puts(arr);
puts("\ninencryption after mid before vowel");
            n=strlen(arr);
            arr=(char*) realloc(arr,(n+2)*sizeof(char));
puts("\ninencryption");
            
            for(int i=(n+2)-1;i>1;i--){
               arr[i]=arr[i-2];
            }

puts("\ninencryption");
            arr[0]='V';
            arr[1]='w';

        break;

        default : 

            n=strlen(arr);
            arr=(char*)realloc(arr,(n+3)*sizeof(char));
            
            arr[n-1]='C';
            arr[n]='n';
            arr[n+1]='s';
            arr[n+2]=0;

        break;    
    }
}

void main(){
    char c;
    system("cls");

    printf("Sing up or login to enjoy the game \n0- Signup\n1- Login\n2- Play Demo");
    scanf("%d",&check);
    
    switch(check){

case 0:
        fflush(stdin);
    printf("Give the your name : ");
    gets(a.name);
    printf("Give the user name with which you will login next time \n");
    gets(a.uname);

        do{
            printf("give the password you want to create : ");
            strcpy(checker,get_string_nospace());         
            printf("Renter the password for the sake of confirmation : ");
            strcpy(a.pass,get_string_nospace());
            if(strcmp(checker,a.pass)==0)break;
            else printf("please Enter the correct password try Again !");
        }while(1);

    encrypt_pass(a.pass);
    puts("\nThe password after encryption is :");puts(a.pass);
    printf("We will assign you an id with record number Kindly note it duly for it may require for other process\n");
    strcpy(a.id,assign_id());
    printf("your id is %s \n",a.id);
    a.lev=1;
struct log_info var;
 FILE *fw=fopen("login_info.bin","ab");
fwrite(&var,sizeof(struct log_info),1,fw);
 fclose(fw);   
break;


}
}