#include<stdio.h>
#include<windows.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>

void instruct(int ,int);
void  highscores();
void printhardscreen();
void printeasyscreen();
void easylevel();
void hardlevel();
void resetgame();
void rategame();
void setscore_easy(int);
void setscore_hard(int);
void setscore_mtp(int);
int control1a(); 
int control1b();  
int controlmtp(char name1,char name2);  


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

void main(){

    system("cls");
    
    int st,lev,hscores;
    printf("\n\n                          WELCOME TO THe PONG GAME");
    printf("\n\n1) Start\n2) View High scores\n3) Reset\n4) Quite\n5)To rate our game\n\nEnter your choice (1,2,3,4,5) : ");
    scanf("%d",&st);

    switch(st){
        case 1:

        printf("Single player or multiplayer ?\n0-single player\n1-Multiplayer\nEnter your choice (0,1) : ");
        scanf("%d",&lev);
        
        switch(lev){
        
        case 0:
        printf("select level\n1- Easy\n2- Hard\n");
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
        return;
        break;
        
        case 5:
        rategame();
        break;
        
        default:printf("Invalid Entry\n");return;
    }
}

void instruct(int players,int level){
    switch(player){
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
        printf("--> Note that :\n-It will be 2 players game\n-Player 1 can handle the pad with ""w"" and ""s"" while player 2 can handle the pad with ""8"" and ""2""\n-Each touch of pad scores for 5\n");
        break;
    }
    printf("______press any key to begin______\n");
}

void  highscores(){
    
    int hscores,i=0;
    info _score[5];

    FILE *hard;
    FILE *easy;

     printf("You want to view the scores of\n1-Easy level\n2-Hard level\n");
        scanf("%d",&hscores);

        switch(hscores){
            case 2:

    hard=fopen("highscores_hard.txt","r");
    while(!(feof(hard))){
        // fgets(_score[i].name,50,hard);
        // fgets(_score[i].date,12,hard);
        // fscanf(hard,"%s ",_score[i].name);
        // fscanf(hard,"%s ",_score[i].date);
        // fscanf(hard,"%d",&_score[i].score);
        fscanf(hard,"%s %s %d",_score[i].name,_score[i].date,&_score[i].score);
        i++;
    }
    fclose(hard);

    
  break;

            case 1:

            easy=fopen("highscores_easy.txt","r");
            
        while(!(feof(easy))){    
        //   fgets(_score[i].name,50,hard);
        //   fgets(_score[i].date,12,hard);
          fscanf(easy,"%s\n%s\n%d\n",_score[i].name,_score[i].date,&_score[i].score);
          i++;
            }
            fclose(easy);
            
  break;
}

            system("cls");
for(int x=0;x<5;x++)printf("%s score on %s :%d\n",_score[x].name,_score[x].date,_score[x].score);
            printf("\n\nPress any key to return to main menu\n");
            getch();
            main();

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

char name1[20],char name2[20];

instruct(2,1);
getch();

system("cls");
printf("Give the name of the player 1 : ");
gets(name1);
printf("Give the name of the player 2 : ");
gets(name2);

int score=controlmtp(name1,name2);

printf("\t\t\t\tThe game is over\n\t\t\t\tYour score : %d\n",score); 

setscore_mtp(score);
printf("Press any key exit\n");

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
    printf("How much stars do you want to give us\n1(awful)-----5(Excellent) : ");
    int ind;
    scanf("%d",&ind);
    ++rate[ind];
    for(int i=0;i<=5;i++)printf("%d ",rate[i]);

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
    
    info arr[5];
    int scor[5],i=0;

    FILE *easy;
   easy=fopen("highscores_easy.txt","r");
   
   while(!(feof(easy))){
    fscanf(easy,"%s %s %d",arr[i].name,arr[i].date,&arr[i].score);
    i++;
   }
   fclose(easy); 
   
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
    
    info arr[5];
    int scor[5],i=0;

    FILE *hard;
   hard=fopen("highscores_hard.txt","r");
   
   while(!(feof(hard))){
    fscanf(hard,"%s %s %d",arr[i].name,arr[i].date,&arr[i].score);
    i++;
   }
   fclose(hard); 
   
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
   
//    for(int i=0;i<5;i++)printf("%d ",arr[i].name);
   
   FILE *rhard;
   rhard=fopen("highscores_hard.txt","w");
   
for(i=0;i<5;i++)
    fprintf(rhard,"%s %s %d\n",arr[i].name,arr[i].date,arr[i].score);
   
   fclose(rhard);

}


int control1a(){
    
    int ax=4,decidei=0,counti=0,score=0,life=5,i=40,j=1,f=1,count=0,s=1,padx=15;
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
    static int padtouch=0;
    int ax=4,decidei=0,counti=0,score=0,life=5,i=40,j=1,f=1,count=0,s=1,padx=15;
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

    gotoxy(padx,20);printf("_____\n");
    
    if(j==20){
        decidei=i-padx;
    if((decidei<=4)&&(decidei>=0)){
        count++;
        score+=5;
        ax=decidei;
        padtouch++;
        }
     decidei=ax-2;
    }
    
    if(j>=25)count++;
    if(j<=0)count=0;
    
    if(count)j--;
    else 
     j++;
     
     if(padx<=10)
          padx=10;
    if(padx>=70)
          padx=70;
     
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

int controlmtp(char name1[],char name2[]){

int score1=0,score2=0,i=30,j=9,p1x=15,p1y=9,p2x,50,p2y=9;
system("color");
system("cls");

printf("     #############################################################\n");
printf("     #                                                          #\n");
printf("     #                                                          #\n");
printf("     #                                                          #\n");
printf("     #                                                          #\n");
printf("     #                                                          #\n");
printf("     #                                                          #\n");
printf("     #                                                          #\n");
printf("     #                                                          #\n");
printf("     #                                                          #\n");
printf("     #                                                          #\n");
printf("     #                                                          #\n");
printf("     #                                                          #\n");
printf("     #                                                          #\n");
printf("     #                                                          #\n");
printf("     #                                                          #\n");
printf("     #                                                          #\n");
printf("     #############################################################\n");
printf("      Player 1 :                     Player 2:                        ");
printf("      %s                             %s                ",name1,name2);
printf("      %d                             %d                ",score1,score2);

gotoxy(i,j);
printf("*");

gotoxy(p1x,p1y);
printf("|\n");
printf("|\n");//will continue this function

}
