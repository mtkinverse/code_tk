#include<stdio.h>
#include<windows.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<time.h>
typedef struct info{
    char name[50];
    char date[12];
    int score;
} info;


struct log_info{
   char name[20],pass[20],uname[20];
   int lev;
}a,b,to_update,*user;

char checker[20];
int check;

void gotoxy(int x,int y){
    COORD CRD;
    CRD.X=x;
    CRD.Y=y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),CRD);
}

void instruct(int ,int);
void  highscores();
info* Readfile(int);
void printhardscreen();
void printeasyscreen();
void easylevel();
void hardlevel();
void multiplayer();
void resetgame();
void rategame();
void setscore_easy(int);
void setscore_hard(int);
void setscore_mtp(int);
int control1a(); 
int control1b();  
void controlmtp(char name1[],char name2[]);
int check_time();
void block_buster(struct log_info *);  
int level(int );
float** generate_blocks(int,int*);
void encrypt_pass(char*);
int login(struct log_info*);
int check_uname(char*,int*);
void update_record(struct log_info *);
void delete_rec(struct log_info*);
void upd_rec_userdefined(struct log_info*);
void serve_them_special(struct log_info*);


void main(){
    

        user=&b;
     while(!(login(user))){puts("Please Login or signup Again\n");user=NULL;user=&b;};
     
    int st,lev,hscores,check=0;
     
while(1){

     system("cls");
    
    system("cls");

	printf("\n\n-> Welcome %s \n\n",user->name);
    printf("\n\n1) Start\n2) View High scores\n3) Reset\n4) Quite\n5)To rate our game\n6) switch Block Buster\n7) To Delete Your account\n8) To change the password of the account\n\nEnter your choice (1----8) : ");
    scanf("%d",&st);

    switch(st){
        case 1:

        printf("\n\nSingle player or multiplayer ?\n\n0-single player\n1-Multiplayer\n\nEnter your choice (0,1) : ");
        scanf("%d",&lev);
        
        switch(lev){
        
        case 0:
        printf("\n\nselect level\n1- Easy\n2- Hard\n");
        scanf("%d",&lev);
        
        switch(lev){
            
            case 1:
            easylevel();
            break;
            
            case 2:
            hardlevel();
            break;
        }
        break;

        case 1:
        multiplayer();
        break;

        }
        break;

        case 2:
        highscores();
        break;

        case 3:
        resetgame();
        break;
        
        case 4:

        printf("You have exit the game\n\n------------------THANKS--------------------\n\n");
        free(user);
        exit(1);

        break;
        
        case 5:
        rategame();
        break;
        
        case 6:
        block_buster(user);
        break;

        case 7:
         delete_rec(user);
        break;

        case 8:
        upd_rec_userdefined(user);
        break;


        default:printf("Invalid Entry\n");
        return;
    }
}
}

void instruct(int players,int level){
    system("cls");
    switch(players){
        case 1:
        printf("--> Note that :\n-It will be a player and computer compitition\n");
        switch(level){
            case 0:
            printf("-You have 5 lifes in this level\n");
            break;
            case 1:
            printf("-You have 3 lifes in this level\n-This will be bit faster then the easy single player level\n");
            break;
        }printf("-Each touch of pad scores for 5\n-PRESS ""a"" to move in the left direction, and ""d"" to move in the right direction\n");
        break;
        case 2:
        printf("--> Note that :\n-It will be 2 players game\n-Player 1 can handle the pad with ""a"" and ""d"" while player 2 can handle the pad with ""4"" and ""6""\n-Each touch of pad scores 1\n**note that, There are two winning strategies:\n_ If ones score are greater than the other and also one of the scores is greater than 4, afterwards the player who leaves the ball will loose\n_ On the other hand if someone let the ball go third time no matter what score he has will loose!\n");
        break;
    }
    printf("______press any key to begin______\n");
    }




void  highscores(){
    
    int x,hscores,i=0;
    struct info *_score;


     printf("You want to view the scores of\n1-Easy level\n2-Hard level\n");
        scanf("%d",&hscores);

        switch(hscores){
            case 2:
          _score =Readfile(1);
    
  break;

            case 1:
          _score = Readfile(0);
            
  break;
}

            system("cls");
for(x=0;x<5;x++)
    printf("%d-> %s score on %s :%d\n",x+1,_score[x].name,_score[x].date,_score[x].score);
    free(_score);
            printf("\n\nPress any key to return to main menu\n");
            getch();
            return;

}

struct info* Readfile(int symbol){
    int n=0,i=0;
   struct info *_score;
    _score=(struct info *)calloc(1,sizeof(struct info));
   FILE *toread;

    if(symbol){
       toread=fopen("highscores_hard.txt","r");

    while(!(feof(toread))){
        n++;
        _score=(struct info *)realloc(_score,n*sizeof(struct info));
        fscanf(toread,"%s %s %d",_score[i].name,_score[i].date,&_score[i].score);
        i++;
    }
    }
    else {

       toread=fopen("highscores_easy.txt","r");
    while(!(feof(toread))){
        n++;
        _score=(struct info *)realloc(_score,n*sizeof(struct info));
        fscanf(toread,"%s %s %d",_score[i].name,_score[i].date,&_score[i].score);
        i++;
    }
    }
    fclose(toread);
    return _score;
}


void easylevel(){
  
  instruct(1,0);
  getch();
int score=control1a();

printf("\n\n\n\n\t\t\t\tGAME OVER\n\t\t\t\tYour Score : %d\n",score);
setscore_easy(score);
sleep(2);

printf("\n\t\t\t\tPress any key exit !");
getch();
return;

}

void hardlevel(){

instruct(1,1);
getch();

int score=control1b();

printf("\t\t\t\tThe game is over\n\t\t\t\tYour score : %d\n",score); 

setscore_hard(score);
printf("Press any key exit\n");

getch();
return;

}

void multiplayer(){

instruct(2,1);
getch();

system("cls");
printf("Give the name of the player 1 : ");

char c;
int n=0;
       char *name1=(char*)malloc(1*sizeof(char));
       char *name2=(char*)malloc(1*sizeof(char));

while((c=getche())!=13){
    if(c==32)printf("\b");
    if(c==8){
        n--;
        name1[n]=0;
        name1=(char*)realloc(name1,n*sizeof(char));
        printf(" \b");
        }

    else if((c>='A'&& c<='z')||(c>='a' && c<='z')){
        n++;
       name1=(char*)realloc(name1,sizeof(char)*n);
       name1[n-1]=c;
} 
}

    name1=(char*)realloc(name1,sizeof(char)*(n+1));
    name1[n]=0;

printf("\nGive the name of the player 2 : ");
c=0;
n=0;

while((c=getche())!=13){

    if(c==32)printf("\b");

    if(c==8){
        n--;
        if(n<=0)n=0;
        name2[n]=0;
        name2=(char*)realloc(name2,n*sizeof(char));
        printf(" \b");
        }

    else if((c>='A'&&c<='z')||(c>='a'&&c<='z')){
        n++;
       name2=(char*)realloc(name2,sizeof(char)*n);
       name2[n-1]=c;
} 
}

    name2=(char*)realloc(name2,sizeof(char)*(n+1));
    name2[n]=0;
    puts("");
    puts(name1);
    puts(name2);
    sleep(2);


controlmtp(name1,name2);
free(name1);
free(name2);
system("cls");

printf("\n\n\n\n\n\t\t\t\tThe game is over\n\n"); 
printf("\t\t\t\tPress any key exit\n");

getch();
return;

}

void resetgame(){
    
    FILE *fadmin=fopen("login_info.bin","rb");
    if(fadmin==NULL){
        printf("File cannot be opened !\n");
        exit(0);
    }
    
    fread(&a,sizeof(struct log_info),1,fadmin);
    fclose(fadmin);

    system("cls");
    printf("! ! ! ! !\n\n");
    printf("Give the user name and of Admin : ");
    fflush(stdin);
    gets(b.uname);
    
    if(strcmp(a.uname,b.uname)){
        printf("You are not the ADMIN !\n");
        sleep(3);
        return;
    }

    printf("Give the password of the admin : ");
    gets(b.pass);
    encrypt_pass(b.pass);

    if(strcmp(a.pass,b.pass)){
        printf("You are not the ADMIN !\n");
        sleep(3);
        return;
    }

    puts("Are you sure you want to reset the game\n\n1- yes\n");
    if(getch()!='1')return;
    

    FILE *easy;
    FILE *hard;
    FILE *ratin;
    FILE *info;
    int x,i;
    
    hard=fopen("highscores_hard.txt","w");
    if(hard==NULL){
        puts("File can't be opened");
        exit(0);
    }
    for(x=0;x<5;x++)
    fprintf(hard,"noname nodate 0\n");

    fclose(hard);

    easy=fopen("highscores_easy.txt","w");
    if(easy==NULL){
        puts("File can't be opened");
        exit(0);
    }

    for(x=0;x<5;x++)
    fprintf(easy,"noname nodate 0\n");
    fclose(easy);

    ratin=fopen("rating.txt","w");
    if(ratin==NULL){
        puts("File can't be opened");
        exit(0);
    }
    for(i=1;i<5;i++)fprintf(ratin,"0\n");
    fclose(ratin);

    info=fopen("temp.bin","wb");
    if(info==NULL){
        puts("File can't be opened");
        exit(0);
    }
    fclose(info);

    remove("login_info.bin");
    rename("temp.bin","login_info.bin");

    printf("The game have been reset\nPress any key to return to main menu\n");
    getch();
    exit(0);

}


void rategame(){

    char r,check[10];
    int rate[6]={0};
    int j,i;
    
    FILE *ratin;
    ratin=fopen("rating.txt","r");
    int l=1;

    while(!(feof(ratin))){
      fscanf(ratin,"%d",&rate[l++]);  
    }

fclose(ratin);

    system("cls");
    printf("Current rating :\n");
    for(j=1;j<=5;j++){
            printf("%d star reading : ",j);
        for(i=1;i<=rate[j];i++){
            printf("* ");
        }
        printf("\n");
    }

    printf("Press R to rate us or press any key to return main menu\n");

if(getch()=='R'){
    printf("How much stars do you want to give us\n\n1(awful)-----5(Excellent) : ");
    int ind;
    scanf("%d",&ind);
    ++rate[ind];


FILE *nratin;
nratin=fopen("rating.txt","w");


for(i=1;i<=5;i++){
    fprintf(nratin,"%d\n",rate[i]);
}
fclose(nratin);

    rategame();
}
return;

}

void setscore_easy(int score){
    
    int scor[5],j,i=0;
struct info *arr;
arr=Readfile(0);
   
   for(i=0;i<5;i++){
    if(score>arr[i].score){

        for(j=4;j>i;j--){
            strcpy(arr[j].name,arr[j-1].name);
            strcpy(arr[j].date,arr[j-1].date);
            arr[j].score=arr[j-1].score;
        }
        printf("Give your name : ");
        scanf("%s",arr[i].name);
        printf("Give date : ");
        scanf("%s",arr[i].date);
        arr[i].score=score;
        break;
    }
   }
   
   
   FILE *resy;
   resy=fopen("highscores_easy.txt","w");
   
for(i=0;i<5;i++)
    fprintf(resy,"%s %s %d \n",arr[i].name,arr[i].date,arr[i].score);
   
   fclose(resy);

}

void setscore_hard(int score){    
    info *arr;
    int j,scor[5],i=0;

arr=Readfile(1);
   
   for(i=0;i<5;i++){
    if(score>arr[i].score){

        for(j=4;j>i;j--){
            strcpy(arr[j].name,arr[j-1].name);
            strcpy(arr[j].date,arr[j-1].date);
            arr[j].score=arr[j-1].score;
        }
        printf("Give your name : ");
        scanf("%s",arr[i].name);
        printf("Give date : ");
        scanf("%s",arr[i].date);
        arr[i].score=score;
        break;
    }
   }
   
   
   FILE *rhard;
   rhard=fopen("highscores_hard.txt","w");
   
for(i=0;i<5;i++)
    fprintf(rhard,"%s %s %d\n",arr[i].name,arr[i].date,arr[i].score);
   
   fclose(rhard);

}


int control1a(){
    
    int ax=4,decidei=0,counti=0,score=0,life=5,i=40,j=1,f=1,count=0,s=1,padx=15,wave_for_multiballs=0;
    char ch;


while(1){
    
    system("color");
    system("cls");
printf("          ####################################################################\n");
printf("          #                                                     LIFE : %d     #\n",life);
printf("          #                                                  SCORE : %2d      #\n",score);
printf("          #                                                                  #\n");
printf("          #                                                                  #\n");
printf("          #                                                                  #\n");
printf("          #                                                                  #\n");
printf("          #                                                                  #\n");
printf("          #                                                                  #\n");
printf("          #                                                                  #\n");
printf("          #                                                                  #\n");
printf("          #                                                                  #\n");
printf("          #                                                                  #\n");
printf("          #                                                                  #\n");
printf("          #                                                                  #\n");
printf("          #                                                                  #\n");
printf("          #                                                                  #\n");              
printf("          #                                                                  #\n");              
printf("          #                                                                  #\n");              
printf("          #                                                                  #\n");              
printf("          #                                                                  #\n");              
printf("          #                                                                  #\n");              
printf("          #                                                                  #\n");              
printf("          #                                                                  #\n");              
printf("          #                                                                  #\n");              
printf("          ####################################################################\n");

    gotoxy(i,j);
    printf("*");
    

    char c;
    while(kbhit()&&(c=getch())){
            if(c=='a')padx-=2;
        else if(c=='d') padx+=2;
        else if(c==27){
        	system("cls");
        	printf("You have Exit the game\n");
        	sleep(3);
        	return score;
		}
        c=0;
        }

    gotoxy(padx,20);printf("________\n");
    


    if(j==20){
        decidei=i-padx;
    if((decidei<=7)&&(decidei>=0)){
        count++;
        score+=5;
        ax=decidei;
        }
     decidei=ax-4;
    }
    
    if(j>=25)count++;
    if(j<=0)count=0;
    
    if(count)j--;
    else 
     j++;
     
     if(padx<=10)
          padx=69;
    if(padx>=70)
          padx=10;
     
     if(j==25){
        system("cls");
        printf("\n\n\n\n\n\n\t\t\t\tLIFE LOST\n\n\n\n");sleep(2);j=1;
        life--;
        i=30;
        ax=4;
        decidei=0;

     if(life<=0){
             return score;
     }
     }
    
    if(i>=76||i<=10)
            decidei*=(-1);

    i+=decidei;

    system("color");
    system("color");
    system("color");
}
}

int control1b(){
    // static int padtouch=0;
    int ax=4,decidei=0,counti=0,score=0,life=3,i=40,j=1,count=0,padx=15;
    char ch;

while(1){
    
    system("color");
    system("cls");
printf("          ####################################################################\n");
printf("          #                                                     LIFE : %d     #\n",life);
printf("          #                                                  SCORE : %2d      #\n",score);
printf("          #                                                                  #\n");
printf("          #                                                                  #\n");
printf("          #                                                                  #\n");
printf("          #                                                                  #\n");
printf("          #                                                                  #\n");
printf("          #                                                                  #\n");
printf("          #                                                                  #\n");
printf("          #                                                                  #\n");
printf("          #                                                                  #\n");
printf("          #                                                                  #\n");
printf("          #                                                                  #\n");
printf("          #                                                                  #\n");
printf("          #                                                                  #\n");
printf("          #                                                                  #\n");              
printf("          #                                                                  #\n");              
printf("          #                                                                  #\n");              
printf("          #                                                                  #\n");              
printf("          #                                                                  #\n");              
printf("          #                                                                  #\n");              
printf("          #                                                                  #\n");              
printf("          #                                                                  #\n");              
printf("          #                                                                  #\n");              
printf("          ####################################################################\n");

    gotoxy(i,j);
    printf("*");
    
    char c;
    while(kbhit()&&(c=getch())){
            if(c=='a')padx-=2;
        else if(c=='d') padx+=2;
        else if(c==27){
        	system("cls");
        	printf("You have Exit the game\n");
        	sleep(3);
        	return score;
		}
        c=0;
        }

     if(padx<=10)
          padx=10;
    if(padx>=70)
          padx=70;

    gotoxy(padx,20);printf("_____\n");
    
    if(j==20){
        decidei=i-padx;
    if((decidei<=4)&&(decidei>=0)){
        count++;
        score+=5;
        ax=decidei;
        }
     decidei=ax-2;
    }
    
    if(j>=25)count++;
    if(j<=0)count=0;
    
    if(count)j--;
    else 
     j++;
     
     
     if(j==25){
        system("cls");
        printf("\n\n\n\n\n\n\t\t\t\tLIFE LOST\n\n\n\n");sleep(2);j=1;
        life--;
        i=40;
        ax=2;
        decidei=0;

     if(life<=0){
             return score;
     }
     }
    
    if(i>=76||i<=10)
            decidei*=(-1);

    i+=decidei;

    system("color");

}
}

void controlmtp(char name1[],char name2[]){

int score1=0,score2=0,i=40,j=9,p1x=40,p1y=24,p2x=40,p2y=4,count=0,decidei=0,n=1,check,lev=0,life1=3,life2=3;
char c;
        int **score=(int**)calloc(n,sizeof(int*));
        score[0]=(int*)calloc(2,sizeof(int));

while(1){

system("color");
system("cls");

printf("            ########################################################################\n");
printf("            #                                                                      #\n");
printf("            #                                                                      #\n");
printf("            #----------------------------------------------------------------------#\n");
printf("            #                                                                      #\n");
printf("            #                                                                      #\n");
printf("            #                                                                      #\n");
printf("            #                                                                      #\n");
printf("            #                                                                      #\n");
printf("            #                                                                      #\n");
printf("            #                                                                      #\n");
printf("            #                                                                      #\n");
printf("            #                                                                      #\n");
printf("            #                                                                      #\n");
printf("            #                                                                      #\n");
printf("            #                                                                      #\n");
printf("            #                                                                      #\n");
printf("            #                                                                      #\n");
printf("            #                                                                      #\n");
printf("            #                                                                      #\n");
printf("            #                                                                      #\n");
printf("            #                                                                      #\n");
printf("            #                                                                      #\n");
printf("            #                                                                      #\n");
printf("            #                                                                      #\n");
printf("            #                                                                      #\n");
printf("            #----------------------------------------------------------------------#\n");
printf("            #                                                                      #\n");
printf("            #                                                                      #\n");
printf("            ########################################################################\n");
printf("                    Player 1 :                                Player 2:             \n");
printf("              name : %s                                    name : %s                 \n",name1,name2);
printf("              life : %d                                    life : %d                 \n",life1,life2);

gotoxy(i,j);
printf("*");

while(kbhit()&&(c=getch())){
	if(c==27){
        	system("cls");
        	printf("You have Exit the game\n");
        	sleep(3);
        	return;
		}

 switch(c){
   
    case 'a':p1x-=3;break;
    case 'd':p1x+=3;break;
    case '4':p2x-=3;break;              
    case '6':p2x+=3;break;
    case '0':return;              

   }
}

if(p1x<=13)p1x=13;
else if(p1x>=78)p1x=78;

if(p2x<=13)p2x=13;
else if(p2x>=78)p2x=78;

gotoxy(p1x,p1y);
printf("_____\n");

gotoxy(p2x,p2y);
printf("_____\n");


if(j==p1y){
    check=i-p1x;
    if(check>=0&&check<=4){
        decidei=check-2;
        score1++;
        count=1;
    }
}

if(j==p2y){
    check=i-p2x;
    if((check>=0)&&(check<=4)){
        decidei=check-2;
        score2++;
        count=0;
    }
}

if(count)j--;
else j++;

if(j==29){
    system("cls");

    puts(name1);
    printf("let the ball go !\nScore = %d : %d\nCurrent level : %d\n",score1,score2,lev+1);

        
    sleep(3);
    j=12;
    i = 30;
    count=1;
    decidei=0;
    life1--;
if(score1>=5||score2>=5){

        score=(int **)realloc(score,n*sizeof(int*));
        score[lev]=(int*)realloc(score[lev],2*sizeof(int));

    if(score1>score2){
        score[lev][0]=1;
        score[lev][1]=0;
        n++;
        lev++;
        }

    else if(score2>score1){
        score[lev][0]=1;
        score[lev][1]=0;
        lev++;
        n++;
        }

        system("cls");
        printf("Level %d Started\n",lev+1);
        sleep(2);
        score1=0;
        score2=0;
    
}
}

if(j==1){
    system("cls");
    puts(name2);
    printf("let the ball go !\nScore = %d : %d\nCurrent level : %d\n",score1,score2,lev+1);
    sleep(3);
    j=12;
    i = 40;
    count=0;
    decidei=0;
    life2--;
if(score1>=5||score2>=5){

        score=(int **)realloc(score,n*sizeof(int*));
        score[lev]=(int*)realloc(score[lev],2*sizeof(int));

    if(score1>score2){

        score[lev][0]=1;
        score[lev][1]=0;
        lev++;
        n++;
        }

    else if(score2>score1){
        
        score[lev][0]=1;
        score[lev][1]=0;
        lev++;
        n++;
        }
        system("cls");
        printf("Level %d started\n",lev+1);
        sleep(2);
        score1=0;
        score2=0;
    
	}
}


if(i<=14||i>=82)
   decidei*=-1;

i+=decidei;

system("color");
system("color");
system("color");
system("color");

if(life1<=0){
    printf("Player %s looses the game !\n",name1);
    sleep(3);
    free(score);
    return;
    }

if(life2<=0){
    printf("Player %s looses the game !\n",name2);
    sleep(3);
    free(score);
return;
}

if(lev>2){
 int i,sums1=0,sums2=0;

    for(i=0;i<n;i++){
        sums1+=score[i][0];
        sums2+=score[i][1];
    }

    if(sums1>sums2){
        system("cls");
        printf("Player %s wins !\n",name1);
    }

    else if (sums2<sums1)printf("Player %s wins !\n",name2);

    else printf("Game drawn !\n");
    sleep(3);
    return;
}
}
}


void block_buster(struct log_info *user){

    int i=user->lev;

    for( i;i<=10;i++){

        if(level(i)){
            system("cls");
            printf("\t\t\t\t\tGame ended !\n\t\t\t\tpress any key to exit\n");

            if(i!=user->lev){
            user->lev=i;
            update_record(user);
            }

            getch();
             return;
             }

        else {
            system("cls");
            printf("\t\t\t\tLevel Completed !\n\t\t\t\tPress any key to continue");
            getch();
            getch();

        }

    }

    
    user->lev=i-1;
    update_record(user);

    printf("\t\t\t\t\tCongratulations you have mastered the game !\n\t\t\t\tPress any key to exit\n");
    getch();
    return;
}

int level(int wave){
    
    float ax=4,decidei=0,counti=0,i=40,j=19,count=1,padx=36;
    int x,z,life=5,rel_ball=1;
    char ch;
    int *towhere=(int*) malloc(sizeof(int));
    
float **block = generate_blocks(wave,towhere);
	wave+=4;

while(1){
    
    
    system("cls");
printf("          ####################################################################\n");
printf("LIFE : %d  #                                                                  #\n",life);
printf("          #                                                                  #\n");
printf("          #                                                                  #\n");
printf("          #                                                                  #\n");
printf("          #                                                                  #\n");
printf("          #                                                                  #\n");
printf("          #                                                                  #\n");
printf("          #                                                                  #\n");
printf("          #                                                                  #\n");
printf("          #                                                                  #\n");
printf("          #                                                                  #\n");
printf("          #                                                                  #\n");
printf("          #                                                                  #\n");
printf("          #                                                                  #\n");
printf("          #                                                                  #\n");
printf("          #                                                                  #\n");              
printf("          #                                                                  #\n");              
printf("          #                                                                  #\n");              
printf("          #                                                                  #\n");              
printf("          #                                                                  #\n");              
printf("          #                                                                  #\n");              
printf("          #                                                                  #\n");              
printf("          #                                                                  #\n");              
printf("          #                                                                  #\n");              
printf("          ####################################################################\n");


for(x=0;x < (*towhere);x++){
    if(block[x][0]==0)continue;
    gotoxy(block[x][0],block[x][1]);
    printf("$");
}


    gotoxy(i,j);
    printf("*");
    
    char c;
    while(kbhit()&&(c=getch())){
            if(c=='a')padx--;
        else if(c=='d') padx++;
        else if(c==27)return 1;
        c=0;
        }

     if(padx<=10)
          padx=10;
    if(padx>=72)
          padx=72;

    gotoxy(padx,20);printf("_____\n");
if(rel_ball)
if((c=getch())!=13){i=(padx+2);c=0;continue;}
rel_ball=0;

    if(j==20){
        decidei=i-padx;
    if((decidei<=4)&&(decidei>=0)){

        count++;
        ax=decidei;

        }
     decidei=ax-2;
     decidei*=.125;
    }
    if(j<=5){
  
    for(x=0;x<(*(towhere));x++){

     if(j<=block[x][1]){

        if(i==block[x][0] ){
            count=!count;
            block[x][0]=0;
        }
        else if((i-1)>=block[x][0]&& decidei<=-2){
            block[x][0]=0;
            decidei*=-1;
        }
        else if((i+1)<=block[x][0]&& decidei>=2){
            block[x][0]=0;
            decidei*=-1;
        }

    }

    }
  
  }

    if(j>=25)count++;
    if(j<=0)count=0;
    
    if(count)j-=.25;
    else 
     j+=.25;
     
     
     if(j==25){
        system("cls");
        printf("\n\n\n\n\n\n\t\t\t\tLIFE LOST\n\n\n\n");
        sleep(2);
        j=19;
        life--;
        i=40;
        ax=2;
        decidei=0;
        count=1;
        rel_ball=1;

     if(life<=0){
        free(block);
        free(towhere);
        fflush(stdin);
             return -1;
     }
     }
    
    if(i>=75||i<=9)
            decidei*=(-1);

    i+=decidei;


float win=0;

for(z=0;z<(*towhere);z++){    
        win+=block[z][0];
    
}

    if(win==0)return 0;
}

}



float** generate_blocks(int wave,int *towhere){
	
    int j,n=0,low,high,rep;
    float i,inc;
    rep = wave + 4;
    n = 0;
    low = 11;
    high = 76;
    inc = (11/wave)+1;
    float **block=(float**)malloc(sizeof(float*));
    
    for(j=1;j<=rep;j++){
    for(i=low;i<=high;i+=inc){
    n++;
        block=(float **)realloc(block,n*sizeof(float*));
        block[n-1]=(float*)calloc(2,sizeof(float));
        
       block[n-1][0]=i;
       block[n-1][1]=j;
     }
    }
    *towhere=9+(10*(wave-1));


    return block;

}



void encrypt_pass(char *arr){
	int i,n = strlen(arr);
  int mb=(n)/2;

  for(i=(n+3);i>(mb+3);i--){
     arr[i]=arr[i-4];
  }

  arr[mb]='0';
  arr[mb+1]='t';
  arr[mb+2]='k';
  arr[mb+3]='0';
  
	n = strlen(arr);
    switch(arr[0]){

       case 'a':case 'A':  
       case 'e':case 'E':  
       case 'i':case 'I':  
       case 'o':case 'O':  
       case 'u':case 'U':  
            for(i=(n+2)-1;i>1;i--){
               arr[i]=arr[i-2];
            }
            arr[0]='V';
            arr[1]='w';

        break;

        default : 

            arr[n]='C';
            arr[n+1]='n';
            arr[n+2]='s';
            arr[n+3]=0;

        break;    
    }
}



int login(struct log_info *user){

    struct log_info new;
    char c;
    int cnt=0,pass_cnt=0;

    system("cls");
	printf("\n\n                    WELCOME TO THe PONG GAME\n----------------------------------------------------");
    printf("\n\nSign up or login to enjoy the game \n0- Signup\n1- Login\n2- Play Demo\n3- Quit\n\n");

    scanf("%d",&check);
    
    switch(check){

case 0:
	
        fflush(stdin);
    printf("Give the your name : ");
    gets(a.name);
    
    printf("Give a unique user name with which you will login next time \n");
    gets(a.uname);

    while(check_uname(a.uname,&cnt)){
    	printf("The user name is already present. please choose someother username\n");
    	gets(a.uname);
	}
        do{
        	fflush(stdin);
            printf("give the password you want to create : ");
            gets(checker);
            printf("Renter the password for the sake of confirmation : ");
			gets(a.pass);
			
            if(strcmp(checker,a.pass)==0)break;
            else printf("please Enter the correct password try Again !\n");
        }while(1);

    encrypt_pass(a.pass);
    a.lev=1;

 FILE *fw=fopen("login_info.bin","ab");
 if(fw==NULL){
    puts("Error in opening the file");
    exit(0);
 }

fwrite(&a,sizeof(struct log_info),1,fw);
 fclose(fw);

	strcpy(user->uname,a.uname);
    strcpy(user->name,a.name);
    strcpy(user->pass,a.pass);
    user->lev=a.lev;	
    puts("\n\nYou have been Logged in as : \n");
    puts(user->uname);
    puts(user->name);
    puts(user->pass);
getch();
return 1;
break; 

 	case 1:

 		system("cls");
 		printf("Enter your unique user name: ");
 		fflush(stdin);
 		gets(a.uname);

		cnt=0;
		while(!check_uname(a.uname,&cnt)){

    		printf("The user name is not present. please try again. press esc for main menu\n");
    		cnt=0;

    		if(getch()==27){
    		return 0;
			}

    		gets(a.uname);
		}

 		FILE *fnew = fopen("login_info.bin","rb");
 		if(fnew == NULL){
 			printf("file not opened\n");
 			exit(0);
		}

		int offset = (cnt)*sizeof(struct log_info);

		fseek(fnew,offset,SEEK_SET);
		fread(&a,sizeof(struct log_info),1,fnew);

		fclose(fnew);

   		printf("\nEnter your password : ");
   		fflush(stdin);

        for(int i=0;i<20;i++)new.pass[i]=0;
		gets(new.pass);
		encrypt_pass(new.pass);
		
		while(strcmp(new.pass,a.pass)!=0){

			printf("\nYour password is incorrect. Enter your password again. you have %d tries: ",3-pass_cnt);

        for(int i=0;i<20;i++)new.pass[i]=0;
            
			gets(new.pass);
			encrypt_pass(new.pass);

			pass_cnt++;
			if(pass_cnt==3){
				printf("You have no tries left\n");
				sleep(2);
				return 0;
			}
		}

		printf("\n\nlogin successful !\n");
       
        sleep(2);
    


    if(cnt==0)serve_them_special(user);
	strcpy(user->uname,a.uname);
    strcpy(user->name,a.name);
    strcpy(user->pass,a.pass);
    user->lev=a.lev;	

		return 1;
 	break;
    
case 2:
    
    printf("\t\t\tGame Ended !\n\nYour score is %d \n\n- Come back and signup to rank in the world\n",control1a());
    exit(0);

break;

case 3:
  exit(0);
break;

default: 

    puts("Kindly enter according to the instructions");
    exit(0);

break;

	}

    
}


int check_uname(char *str,int * cnt){

    struct log_info var; 
    FILE *search=fopen("login_info.bin","rb");

    if(search==NULL){
        printf("The File does not exist\n");
        exit(0);
    }

    if(search== NULL) {
        printf("Error Exist\n");
        exit(0);
        }
        rewind(search);
    while(!(feof(search))){
        if(fread(&var,sizeof(struct log_info),1,search) == NULL)continue;
        if(strcmp(var.uname,str)==0){
            fclose(search);
            return 1;
		}
		(*(cnt))++;
    }
    fclose(search);
    return 0;

}

void update_record(struct log_info *user){

    FILE *fchange=fopen("login_info.bin","rb");
    FILE *ftemp=fopen("temp.bin","wb");

    if(fchange==NULL){
        printf("File login_info.bin cannot be opened\n");
        exit(0);
    }

    if(ftemp==NULL){
        printf("The temporary file cannot be opened cannot be opened\n");
        exit(0);
    }
    rewind(fchange);

    while(!feof(fchange)){

      if(fread(&a,sizeof(struct log_info),1,fchange)==NULL)continue;
puts(a.uname);

      if(strcmp(a.uname,user->uname)==0){
      fwrite(user,sizeof(struct log_info),1,ftemp);
      sleep(5);
      getch();
      continue;
      }

      fwrite(&a,sizeof(struct log_info),1,ftemp);
      }

      fclose(fchange);
      fclose(ftemp);

    remove("login_info.bin");
    rename("temp.bin","login_info.bin");
    printf("\n\nThe record has updated\n\n");
	getch();
    exit(0);
}

void delete_rec(struct log_info *user){
    
    FILE *del=fopen("login_info.bin","rb");
    if(del==NULL){
        printf("The file does not exist\n");
        exit(0);
    }

    FILE *tem=fopen("temp.bin","wb");
    if(tem==NULL){
        printf("The file does not exist\n");
        exit(0);
    }
    rewind(del);
    while(!feof(del)){

        if(fread(&a,sizeof(struct log_info),1,del) == NULL) continue;

        if(strcmp(a.uname,user->uname)==0){
        printf("Tou have been tracked .");
        continue;
        }
        fwrite(&a,sizeof(struct log_info),1,tem);
    }
    
    fclose(del);
    fclose(tem);

    remove("login_info.bin");
    rename("temp.bin","login_info.bin");

    printf("\n-> The Record Has been deleted\n");
    sleep(3);

    fflush(stdin);

    exit(0);

}


void serve_them_special(struct log_info *user){

while(1){

     FILE *info_for_admin;
    int index=0,offset,cur=0;
system("cls");
printf("\n\n\t_______ Greetings %s \n",user->name);
printf("\nHow would you like to manage data \n\n#1 view the number of users and their names\n#2 Delete a record of particular user\n#3 To Exit\n#4 to view the information of the user\n\nEnter your choice : ");


switch(getche()){  


case '1': 
system("cls");
printf("\n-------------The Current in servance users are \n\n");

    FILE *f=fopen("login_info.bin","rb");
    if(f==NULL){
        printf("NO such file exist\n");
        exit(0);
    }

    while(!feof(f)){   
        index++;
    if(fread(&b,sizeof(struct log_info),1,f)==NULL)
       continue;
    
    printf("\nUser #%d ; Uname : %s\n",index,b.uname);
}
puts("\n-Press any key to continue");
getch();
    fclose(f);

break;

    case '2':

       printf("\nGive the username of which you want to delete the record\n");
       fflush(stdin);
       gets(b.uname);

       if(!check_uname(b.uname,&index)){

           printf("\nThe user id does not exist\n");
           continue;
}printf("The user rcord id at %d\n",index);

         FILE *fdel=fopen("login_info.bin","rb");
    if(fdel==NULL){
        printf("NO such file exist\n");
        exit(0);
    }
    
    FILE *temp=fopen("temp.bin","wb");
    if(temp==NULL){
        printf("NO such file exist\n");
        exit(0);
    }

    while(!feof(fdel)){

        if(fread(&a,sizeof(struct log_info),1,fdel)==NULL)continue;
        if(cur==index){cur++;continue;}
        cur++;
        

        fwrite(&a,sizeof(struct log_info),1,temp);
        
    }
    fclose(fdel);
    fclose(temp);

    remove("login_info.bin");
    rename("temp.bin","login_info.bin");

    puts("\nOn your command The customer have been removed successfully");

    sleep(3);
    getch();
     break;

    case '3':
    printf("\nThanks for visiting us \n");
    exit(0);
     break;

     case '4':

     info_for_admin = fopen("login_info.bin","rb");

    while(!feof(info_for_admin)){
    if(info_for_admin==NULL){
        printf("NO such file exist\n");
        exit(0);
    }

    if(fread(&a,sizeof(struct log_info),1,info_for_admin)==NULL)continue;
    printf("\n\n%s,%s,%s,%d\n",a.name,a.uname,a.pass,a.lev);

}fclose(info_for_admin);
getch();
     break;

    default: printf("Invalid entry \n");sleep(2);
}
}

}

void upd_rec_userdefined(struct log_info *user){
    int cnt=0,ind=0;
    system("cls");
    printf("\n\nDo you want to change password or username \np- password\nu- username\n");

    switch(getche()){
        case 'p': case 'P':
          printf("\nEnter the new password now\n");
          fflush(stdin);

          do{
        	fflush(stdin);
            printf("give the password you want to create : ");
            gets(checker);
            printf("Renter the password for the sake of confirmation : ");
			gets(to_update.pass);
            if(strcmp(checker,to_update.pass)==0)break;
            else printf("please Enter the correct password try Again !\n");
        }while(1);
        
        encrypt_pass(to_update.pass);
        strcpy(user->pass,to_update.pass);

        break;

        case 'u':case 'U':
             printf("Enter the new and unique user name : ");
             fflush(stdin);
             gets(to_update.uname);

              while(check_uname(to_update.uname,&cnt)){
    	printf("The user name is already present. please choose someother username\n");
    	gets(to_update.uname);cnt=0;
	}

    strcpy(user->uname,to_update.uname);

FILE *username = fopen("login_info.bin","rb");
FILE *temp=fopen("temp.bin","wb");
rewind(username);

while(!feof(username)){
    ind++;

if(fread(&a,sizeof(struct log_info),1,username)==NULL)continue;

if(ind==cnt){
fwrite(user,sizeof(struct log_info),1,temp);
    ind++;
    continue;
}

fwrite(&a,sizeof(struct log_info),1,temp);

}

fclose(temp);
fclose(username);

remove("login_info.bin");
rename("temp.bin","login_info.bin");
puts("The Record has been updated here Thanks\n");getch();

return;
          
          break;
          default :
             printf("Invalid Entry\n");
             exit(0);
          break;
    }

          update_record(user);
          exit(0);
}
