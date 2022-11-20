#include<stdio.h>

struct reg{
    char coname[15],cid[7];
}r;

struct stud{
    char stuid[10],fname[10],lname[10],email[20],cellno[12];
    struct reg r;
}arr[5];

void main(){
printf("Give the information of the students\n");
for(int i=0;i<5;i++){
    fflush(stdin);
    printf("\nStudent %d :\nID : ",i+1);
    gets(arr[i].stuid);
    printf("First name : ");
    gets(arr[i].fname);
    printf("Last name : ");
    gets(arr[i].lname);
    printf("Email : ");
    gets(arr[i].email);
    printf("Enter phone number : ");
    gets(arr[i].cellno);
    printf("Enter the registration information\nCourse name : ");
    gets(arr[i].r.coname);
    printf("Enter the course id : ");
    gets(arr[i].r.cid);
}

printf("The Information you stored is\n");
for(int i=0;i<5;i++){
    printf("Student %d\nID : %s\nFirst name : %s\nLast name : %s\nEmail : %s\nphone number : %d\nCourse id : %s\nCourse name : %s\n",i+1,arr[i].stuid,arr[i].fname,arr[i].lname,arr[i].email,arr[i].cellno,arr[i].r.cid,arr[i].r.coname);
}

}