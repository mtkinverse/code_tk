#include<stdio.h>
void main(){
    int i=1,mark,pass=0,fail=0,avg=0,b_avg=0,exc=0;
    for(i;i<=25;i++){
        printf("Give the marks of the student %d : ",i);
        scanf("%d",&mark);
        if(mark<0||mark>100){printf("Invalid marks\n");i--;}
        else{
            if(mark<50)fail++;
            else pass++;
            switch(mark){
                case 50 ... 69:b_avg++;break;
                case 70 ... 85:avg++;break;
                case 86 ... 100:exc++;break;
            }
        }
    }printf("Students passed : %d\nStudents Failed : %d\nStudents below average : %d\nStudents above average : %d\nExcellent Students : %d\n",pass,fail,b_avg,avg,exc);
}