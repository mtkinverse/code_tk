#include<stdio.h>
struct parts{
    int year,quan;
    char mater[20];
}arr[6][10];

void main(){
    for(int j=0;j<6;j++){
        for(int i=0;i<10;i++){
            printf("Give the year and quantity manufactured : ");
            scanf("%d %d",&arr[j][i].year,&arr[j][i].quan);
            fflush(stdin);
            printf("Givr the material of the part : ");
            gets(arr[j][i].mater);
        }
    }
    fflush(stdin);
    char check[3],end[3];
    printf("Give the series where you want to retrieve the information : ");
    scanf("%s %s",check,end);
    int no=check[2]-'0';
    int class=check[1]-65;
    int endno=end[2]-'0';
    int endclass=end[1]-65;
    printf("%d class\n%d starting no\nend class %d\nrndno %d\n",class,no,endclass,endno);sleep(5);
    for(int j=class;j<5;j++){
        for(int i=no;i<10;i++){
            printf("\n--> Material Code %c%c%d :\n",j+65,j+65,i);
            printf("Material Quantity : %d\nYear manufactured : %d\nType name : %s\n",arr[j][i].quan,arr[j][i].year,arr[j][i].mater);
            if((j==endclass)&&(i==endno))return;
        }
    }




}