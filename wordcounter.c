#include<stdio.h>
void main(){int checker,count=0;char ch,arr[100];
   char namefile[1000];
    printf("HI we are counting words here\nPlease let me know in what format you want to count the words\n1.For if you want to enter the words\n2.For if you want to count words form a file\n");
scanf("%d",&checker);
switch(checker){
    case 1:scanf("%s",namefile);
    fgets(namefile,1000,stdin);
    for(int i=0;namefile[i]!='\0';i++){
        ////////////WRONG////////
    count++; 
        printf("%d\n", count);
    }
    break;
    case 2:
    scanf("%s",namefile);
    printf("Enter the name of file\n");
    FILE *countfile;
    countfile=fopen("atest.txt","r");
    if(countfile==NULL)printf("File does not exist\n");
    else {
        int i=0;
        while(!feof(countfile)){
     fscanf(countfile,"c",arr[i]);
      //if(arr[i]==32)continue;
         count++;i++;
        }
    printf("IT contain %d words\n%s\n%d",count,arr,i);}fclose (countfile);
    break;
    default: printf("Invalid Entry\n");
}
}