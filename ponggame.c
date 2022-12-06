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
// void multiballs(int,int,int,int);
void block_buster();  
int level(int );
float** generate_blocks(int,int*);


void main(){

    system("cls");
    
    int st,lev,hscores;
    printf("\n\n                          WELCOME TO THe PONG GAME");
    printf("\n\n1) Start\n2) View High scores\n3) Reset\n4) Quite\n5)To rate our game\n6) switch Block Buster\n\nEnter your choice (1,2,3,4,5) : ");
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
        exit(1);
        break;
        
        case 5:
        rategame();
        break;
        
        case 6:
        block_buster();
        break;
        default:printf("Invalid Entry\n");return;
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
    
    int hscores,i=0;
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
for(int x=0;x<5;x++)
    printf("%d-> %s score on %s :%d\n",x+1,_score[x].name,_score[x].date,_score[x].score);
    free(_score);
            printf("\n\nPress any key to return to main menu\n");
            getch();
            main();

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
main();

}

void hardlevel(){

instruct(1,1);
getch();

int score=control1b();

printf("\t\t\t\tThe game is over\n\t\t\t\tYour score : %d\n",score); 

setscore_hard(score);
printf("Press any key exit\n");

getch();
main();

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
main();

}

void resetgame(){

    FILE *easy;
    FILE *hard;
    FILE *ratin;
    
    hard=fopen("highscores_hard.txt","w");
    for(int x=0;x<5;x++)
    fprintf(hard,"noname nodate 0\n");

    fclose(hard);

    easy=fopen("highscores_easy.txt","w");

    for(int x=0;x<5;x++)
    fprintf(easy,"noname nodate 0\n");
    fclose(easy);

    ratin=fopen("rating.txt","w");
    for(int i=1;i<5;i++)fprintf(ratin,"0\n");
    
    printf("The game have been reset\nPress any key to return to main menu\n");
    getch();
    main();

}


void rategame(){

    char r,check[10];
    int rate[6]={0};
    
    FILE *ratin;
    ratin=fopen("rating.txt","r");
    int l=1;

    while(!(feof(ratin))){
      fscanf(ratin,"%d",&rate[l++]);  
    }

fclose(ratin);

    system("cls");
    printf("Current rating :\n");
    for(int j=1;j<=5;j++){
            printf("%d star reading : ",j);
        for(int i=1;i<=rate[j];i++){
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


for(int i=1;i<=5;i++){
    fprintf(nratin,"%d\n",rate[i]);
}
fclose(nratin);

    rategame();
}
main();

}

void setscore_easy(int score){
    
    int scor[5],i=0;
struct info *arr;
arr=Readfile(0);
   
   for(i=0;i<5;i++){
    if(score>arr[i].score){

        for(int j=4;j>i;j--){
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
    int scor[5],i=0;

arr=Readfile(1);
   
   for(i=0;i<5;i++){
    if(score>arr[i].score){

        for(int j=4;j>i;j--){
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
            if(c=='a')--padx;
        else if(c=='d') ++padx;
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
            if(c=='a')--padx;
        else if(c=='d') ++padx;
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
        // padtouch++;
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

int score1=0,score2=0,i=30,j=9,p1x=12,p1y=17,p2x=83,p2y=4,count=0,decidei=0,n=1,check,lev=0,life1=3,life2=3;
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

 switch(c){
   
    case 'a':p1x--;break;
    case 'd':p1x++;break;
    case '4':p2x--;break;              
    case '6':p2x++;break;
    case '0':return;              

   }
}

if(p1x<=13)p1x=13;
else if(p1x>=83)p1x=83;

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

// if(j>=17)count=1;
// else if (j<=1)count=0;
if(count)j--;
else j++;

if(j==22){
    system("cls");

    puts(name1);
    printf("let the ball go !\nScore = %d : %d\nCurrent level : %d\n",score1,score2,lev+1);

        
    sleep(3);
    j=12;
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
 int sums1=0,sums2=0;

    for(int i=0;i<n;i++){
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


void block_buster(){

    int i;
            FILE *last_lev=fopen("level.txt","r");
            fscanf(last_lev,"%d",&i);
            printf("%d\n",i);sleep(1);

    for( i;i<=3;i++){

        if(level(i)){
            system("cls");
            printf("\t\t\t\t\tGame ended !\n\t\t\t\tpress any key to exit\n");
            fclose(last_lev);
            free(last_lev);
        last_lev=fopen("level.txt","w");
            fprintf(last_lev,"%d",i);
            fclose(last_lev);
            free(last_lev);
            getch();
             main();
             }

        else {
            system("cls");
            printf("\t\t\t\tLevel Completed !\n\t\t\t\tPress any key to continue");
            getch();
            getch();

        }

    }

            fclose(last_lev);
            free(last_lev);
        last_lev=fopen("level.txt","w");
            fprintf(last_lev,"%d",i-1);
            fclose(last_lev);
            free(last_lev);
    printf("\t\t\t\t\tCongratulations you have mastered the game !\n\t\t\t\tPress any key to exit\n");
    getch();
    main();
}

int level(int wave){
    wave+=4;

    float ax=4,decidei=0,counti=0,i=40,j=19,count=1,padx=36;
    int life=5,rel_ball=1;
    char ch;
    int *towhere=(int*) malloc(sizeof(int));
    
float **block = generate_blocks(wave,towhere);


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


for(int x=0;x < (*towhere);x++){
    if(block[x][0]==0)continue;
    gotoxy(block[x][0],block[x][1]);
    printf("#");
}


    gotoxy(i,j);
    printf("*");
    
    char c;
    while(kbhit()&&(c=getch())){
            if(c=='a')--padx;
        else if(c=='d') ++padx;
        else if(c=='0')return 1;
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
     decidei*=0.125;
    }
    if(j<=5){
  
    for(int x=0;x<(*towhere);x++){

     if(j<=block[x][1]){

        if(i==block[x][0] ){
            count=!count;
            block[x][0]=0;
        }
        else if((i-1)==block[x][0]&& decidei<=-2){
            block[x][0]=0;
            decidei*=-1;
        }
        else if((i+1)==block[x][0]&& decidei>=2){
            block[x][0]=0;
            decidei*=-1;
        }

    }

    }
  
  }

    if(j>=25)count++;
    if(j<=0)count=0;
    
    if(count)j-=0.125;
    else 
     j+=0.125;
     
     
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
        free(block);
        fflush(stdin);
             return -1;
     }
     }
    
    if(i>=75||i<=9)
            decidei*=(-1);

    i+=decidei;


float win=0;

for(int z=0;z<(*towhere);z++){    
        win+=block[z][0];
    
}

    if(win==0)return 0;
}

}



float** generate_blocks(int wave,int *towhere){

    int n=0;
    float **block=(float**)malloc(sizeof(float*));

 switch(wave-4){

  case 1:

    for(int j=3;j<=wave;j++){
    for(int i=20;i<=66;i+=4){
    n++;
        block=(float **)realloc(block,n*sizeof(float*));
        block[n-1]=(float*)calloc(2,sizeof(float));
        
       block[n-1][0]=i;
       block[n-1][1]=j;
     }
    }
    *towhere=(((66-20)/4)*(wave-3));

break;
//---------------------------------------------------------
case 2:

    for(int j=3;j<=wave;j++){
        for(int i=10;i<=76;i+=4){
        n++;

            block=(float **)realloc(block,n*sizeof(float*));
            block[n-1]=(float*)calloc(2,sizeof(float));
         
           block[n-1][0]=i;
           block[n-1][1]=j;
        }
}
    *towhere=(((76-10)/4)*(wave-3));

break;
//_________________________________________________________________
case 3:

    for(int j=3;j<=wave;j++){
        for(int i=10;i<=76;i+=2){
        n++;

            block=(float **)realloc(block,n*sizeof(float*));
            block[n-1]=(float*)calloc(2,sizeof(float));
            
           block[n-1][0]=i;
           block[n-1][1]=j;
        }
}
    *towhere=(((76-10)/2)*(wave-3));

break;
//--------------------------------------------------------------------
}
    return block;

}
