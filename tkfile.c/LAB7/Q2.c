#include<stdio.h>

void main(){
int i,j,task,dum,a=0,b;
char ch;
for(i=1;i<=3;i++){
    task=0;
        for(ch=65;ch<70;ch++){
        printf("Task %c\nGive the number of days taken by member %d in round 1 : ",ch,i);
        scanf("%d",&dum);
        printf("Give the number of days taken by member %d in round 2 : ",i);
        scanf("%d",&dum);
        printf("Give the number of days taken by member %d in round 3 : ",i);
        scanf("%d",&dum);
        if(dum>a)a=dum;else if(dum<a)b=dum;
        task+=dum;
        }
    printf("The total days for the project are : %d\nBest : %d\nworst : %d\n",task,b,a);
}



}