#include<stdio.h>
#include<string.h>

struct stu{
    char id[20],name[20],sex[20];
    float quiz[2],mid[2],final,total;
}a;

int check_id(char *s){
    FILE *r=fopen("student.txt","r");
    int n;
    while(!(n=feof(r))){
        fscanf(r,"%s",a.name);
        if(strcmp(s,a.name)==0)return 1;
    }
    printf("%d\n",n);
    return 0;
}

void main(){

printf("Hi give the information of the students\n\n");
FILE *f=fopen("student.txt","a");
for(int i=0;i<3;i++){
    printf("\n\n-> Student %d\n\n",i+1);
struct stu a;
    printf("Give the id of the student : ");
    char checker[20];
    gets(checker);
    while(check_id(checker)){
        printf("Given student ID exist kindly provide another ID : ");
        gets(checker);
    }
    strcpy(a.id,checker);
    printf("Give the name of the student : ");
    gets(a.name);
    printf("Give the sex of the student : ");
    gets(a.sex);
    for(int x=0;x<2;x++){
        fflush(stdin);
        printf("Give the score of quiz %d : ",x+1);
        scanf("%f",&a.quiz[x]);
        printf("Give the score of mid %d : ",x+1);
        scanf("%f",&a.mid[x]);
    }
    printf("Give the score of final : ");
    scanf("%f",&a.final);
    a.total=a.mid[0]+a.mid[1]+a.quiz[0]+a.quiz[1]+a.final;
    fprintf(f,"%s ",a.id);
    fprintf(f,"%s ",a.name);
    fprintf(f,"%s ",a.sex);
    fprintf(f,"%f %f ",a.mid[0],a.mid[1]);
    fprintf(f,"%f %f ",a.quiz[0],a.quiz[1]);
    fprintf(f,"%f %f\n",a.final,a.total);
    fflush(stdin);
}


}