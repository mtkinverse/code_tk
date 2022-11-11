#include<stdio.h>

void main(){
int alr[5],bobr[5],awin=0,bwin=0;
char x,als[5],bobs[5];
while(x!='x'){
    counta=0;countb=0;higha=0;highb=0;
    printf("------------Alice !\nGive the rank and suits of the cards you have :\n");
    for(int i=0;i<5;i++){
        printf("Give the rank of card %d : ",i+1);
        scanf("%d",&alr[i]);
        printf("Give the suit of the card %d :",i+1);
        scanf(" %c",&als[i]);
    }
    printf("------------Bob !\nGive the rank and suits of the cards you have :\n");
    for(int i=0;i<5;i++){
        printf("Give the rank of card %d : ",i+1);
        scanf("%d",&bobr[i]);
        printf("Give the suit of the card %d :",i+1);
        scanf(" %c",&bobs[i]);
    }
    for(int j=0;j<5;j++){
        for(int i=0;i<5;i++){
            if(alr[j]==alr[i])counta++;
            if(bobr[j]==bobr[i])countb++;
        }
    }
    if(counta==0)higha++;if(countb==0)highb++;
    if(counta==countb)printf("------------Match Drawed\n");
    else {
if((counta>=12&&countb<12)||(counta>=2&&countb<2)){
    printf("-----------Alice Wins----------\n");
    awin++;
    }
else {printf("---------Bob Wins----------\n");
    bwin++;
}}
   printf("Press X to exit or press any key to restart the game\n");
    x=getch();
}
printf("Number of games win by\nAlice : %d\nBob : %d",awin,bwin);


}