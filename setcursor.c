#include<conio.h>
#include<stdio.h>
#include<windows.h>
#include<stdlib.h>

void gotoxy(int x,int y){
    COORD CRD;
    CRD.X=x;
    CRD.Y=y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),CRD);
}
int control(){
    
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