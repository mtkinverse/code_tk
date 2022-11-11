#include<stdio.h>
#include<stdlib.h>
#include<string.h>
 struct sub{
    char name[100];
    char fname[100];
    int rollno;
    int marks;
};
void printinfo(struct sub arr);
int main(){
struct sub arr[5] ;
printf("give the information of student name,father name ,section, roll number ,marks \n");
fgets(arr[0].name,10,stdin);
fgets(arr[0].fname,10,stdin);
scanf("%d",&arr[0].rollno);
scanf("%d",&arr[0].marks);

printf("enter the information of second student\n");
fgets(arr[1].name,10,stdin);
fgets(arr[1].fname,10,stdin);
scanf("%d",&arr[1].rollno);
scanf("%d",&arr[1].marks);

printf("enter the information of third student\n");
fgets(arr[2].name,10,stdin);
fgets(arr[2].fname,10,stdin);
scanf("%d",&arr[2].rollno);
scanf("%d",&arr[2].marks);

printf("enter the information of fourth student\n");
fgets(arr[3].name,10,stdin);
fgets(arr[3].fname,10,stdin);
scanf("%d",&arr[3].rollno);
scanf("%d",&arr[3].marks);

// printf("enter the information of fifth student\n");
// fgets(arr[4].name,10,stdin);
// fgets(arr[4].fname,10,stdin);
// fgets(arr[4].class,10,stdin);
// scanf("%d",arr[4].rollno);
// scanf("%d",arr[4].marks);
scanf("\n");
printf("enter the name of student you entered\n");
char checker[10];
fgets(checker,10,stdin);
if(strcmp(arr[0].name , checker) == 0){printinfo(arr[0]);}
else if(strcmp(arr[1].name , checker) == 0){printinfo(arr[1]);}
else if(strcmp(arr[2].name , checker) == 0){printinfo(arr[2]);}
else if(strcmp(arr[3].name , checker) == 0){printinfo(arr[3]);}
else if(strcmp(arr[4].name , checker) == 0){printinfo(arr[4]);}else{printf("invalid entry\n");}
char n;
printf("press enter to exit the program OR press any key to restart the program\n");
scanf("%c",&n);
 if( n =='\n'){printf("Thanks you have ENDED the program\n");return 0;}else{free(arr); main();}
    return 0;
}
void printinfo(struct sub arr){
    printf("name :%sfather name :%sroll number :%d\nmarks :%d\nsectio n is:B\n",arr.name,arr.fname,arr.rollno,arr.marks);
}