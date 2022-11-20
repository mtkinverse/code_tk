#include<stdio.h>

struct emp{
    char name[20];
    int id;
    float sal;
}e;

struct org{
   char orgname[20];
   char orgno[20];
   struct emp e;
}o;

void main(){
    printf("Give the name of the organization : ");
    gets(o.orgname);
    fflush(stdin);
    printf("Give the number of the organization : ");
    gets(o.orgno);
    printf("Give the details of your employee\nName,id, and salary\n");
    fflush(stdin);
    gets(o.e.name);
    scanf("%d %f",&o.e.id,&o.e.sal);
    printf("\nsize of organozation : %d You have entered\nOrganization name : %s\nOrganization id ; %s\n  Employee detail\nName : %s\nID : %d\nsalary = $%.2f\n",sizeof(o),o.orgname,o.orgno,o.e.name,o.e.id,o.e.sal);


}