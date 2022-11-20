#include<stdio.h>
#include<string.h>
struct stud{
    int rollno;
    char name[20];
    char department[20];
    char course[20];
    int year;
};

void ini_struct(struct stud arr[]){
    char dum;
    for(int i=0;i<450;i++){
    printf("Give the roll number of the student %d : ",i+1);
    scanf("%d",&arr[i].rollno);
    scanf("%c",&dum);
    printf("Give the name of the student %d : ",i+1);
    gets(arr[i].name);
    printf("Give the department of the student %d : ",i+1);
    scanf("%s",&arr[i].department);
    printf("Give the course of the student %d : ",i+1);
    scanf("%c",&dum);
    gets(arr[i].course);
    printf("Give the year of joining : ");
    scanf("%d",&arr[i].year);
printf("\n\n");
    }
}

void main(){
    char new[20],dum;
    int yr;
struct stud arr[450];
ini_struct(arr);
printf("Give the year : ");
scanf("%d",&yr);
for(int i=0;i<5;i++){
if(arr[i].year==yr){
    printf("\n%s",arr[i].name);
}
}
scanf("%c",&dum);
printf("\n\nGive the name of the student : ");
gets(new);
for(int i=0;i<450;i++){
if(strcmp(arr[i].name,new)==0){
    printf("\nName : %s",arr[i].name);
    printf("\nRoll number : %d",arr[i].rollno);
    printf("\nDepartment : %s",arr[i].department);
    printf("\nCourse %s",arr[i].course);
    printf("\nYear of joining : %d",arr[i].year);
    printf("\n");
}
}



}