#include<stdio.h>
void input(char *[],char *[],float [][5]);
void month_wise(char *[],char *[],float [][5],float []);
void dep_wise(char *[],char *[],float [][5],float []);
void output(char *[],char *[],float [][5],float [],float []);

void main(){
printf("Give the information of the departments\n\n");
char *month[]={"January","Febuary","March","April","May"};
char *dep[]={"Surgury","Emergency","Skin","Covid-19","Density","Total"};
float arr[5][5],tot1[5]={0},tot2[5]={0};
 input(month,dep,arr);
month_wise(month,dep,arr,tot1);
dep_wise(month,dep,arr,tot2);
output(month,dep,arr,tot1,tot2);
}

void input(char *month[],char *dep[],float arr[][5]){

for(int j=0;j<5;j++){
    puts(dep[j]);
for(int i=0;i<5;i++){
    printf("month %s : ",month[i]);
    scanf("%f",&arr[j][i]);
}
}
}

void month_wise(char *month[],char *dep[],float arr[][5],float total[]){
    for(int j=0;j<5;j++){
    for(int i=0;i<5;i++){
      total[j]+=arr[i][j];    
    }
    }
}

void dep_wise(char *month[],char*dep[],float arr[][5],float total[]){
for(int j=0;j<5;j++){
    for(int i=0;i<5;i++){
        total[j]+=arr[j][i];
    }
}
}

void output(char *month[],char*dep[],float arr[][5],float tot1[],float tot2[]){
printf("%-10s ","");for(int i=0;i<5;i++)printf("%-10s ",month[i]);
printf("\n%-10s\n","Department");

for(int j=0;j<5;j++){
        printf("%-10s ",dep[j]);
    for(int i=0;i<5;i++){
        printf("%-10.2f ",arr[j][i]);
    }
    printf("%-10.2f\n",tot2[j]);
}
printf("%-10s ","Total");
for(int i=0;i<5;i++)printf("%-10.2f ",tot1[i]);
puts("");
}