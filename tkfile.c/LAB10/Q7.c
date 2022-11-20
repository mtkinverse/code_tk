#include<stdio.h>
#include<string.h>
#include<windows.h>

struct book{
    char accno[15],authname[20],title[20],flag[12];
};

void displayall(struct book arr[]){
    for(int i=0;i<5;i++){
        printf("Book %d :\nAccession number : %s\nAuthor name : %s\nTitle : %s\nFlag : %s\n",i+1,arr[i].accno,arr[i].authname,arr[i].title,arr[i].flag);
    }
}

void displayauth(struct book arr[]){
    char check[20];
    printf("Give the name of the author : ");
    fflush(stdin);
    gets(check);
    for(int i=0;i<5;i++){
        if(strcmp(arr[i].authname,check)==0){
            printf("\nTitle : %s\nAccession number : %s\nflag : %s\n",arr[i].title,arr[i].accno,arr[i].flag);
        }
    }
}

void displaytitle(struct book arr[]){
    fflush(stdin);
    char check[20];
    printf("Give the title you want to search book with : ");
    gets(check);
    for(int i=0;i<5;i++){
        if(strcmp(arr[i].title,check)==0){
            printf("\nAuthor number : %s\nAccession number : %s\nFlag : %s\n",arr[i].authname,arr[i].accno,arr[i].flag);
        }
    }
}

void displayno(struct book arr[]){
    int count=0;
    for(int i=0;i<5;i++){
        if(strcmp(arr[i].flag,"notissued")==0)count++;
    }
    printf("Total number of books are %d\n",count);
}

void addbook(struct book arr[]){
    int count=0;
    for (int i=0,count;i<5;i++){
        if(strcmp(arr[i].flag,"notissued")==0)count++;
    }
    if(count>=5)printf("All the capacity are occupied no book can be add\n");
    else if(count<5){
        printf("Give the accession number of the book you want to unissue : ");
        fflush(stdin);
        char dum[20];
        gets(dum);
        for(int i=0;i<5;i++){
            if(strcmp(arr[i].accno,dum)==0){
                if(strcmp(arr[i].flag,"issued")==0){
                    strcpy(arr[i].flag,"notissued");
                    printf("The book has been added\n");
                    return;
                }else {
                    printf("Unable to add since it is not issued\n");
                    return;
                      }
            }
        }
            printf("The book not found\n");return;
    }
}

void issuebook(struct book arr[]){
    displayall(arr);
    printf("Give the accession number of the book you want to issue : ");
    fflush(stdin);
    char dum[20];
    gets(dum);
    for(int i=0;i<5;i++){
        if(strcmp(arr[i].accno,dum)==0){
            strcpy(arr[i].flag,"issued");
            return;
        }
              
    }
            printf("Book not found please entre the correct accession number\n");
            issuebook(arr);
}

void performit(struct book arr[]){
    while(1){
printf("press any key to perform the desired information\n1-display information stored\n2-Add a book\n3-display books named by a particular author\n4-Display books of same title\n5-Current number of books in the library\n6-issue a book\nOr enter 0 to exit\nEnter your choice (0---6) : ");
int call;
scanf("%d",&call);
    switch (call){
        case 1:
         displayall(arr);
        break;
        case 2:
         addbook(arr);
        break;
        case 3:
         displayauth(arr);
        break;
        case 4:
         displaytitle(arr);
        break;
        case 5:
         displayno(arr);
        break;
        case 6:
         issuebook(arr);
        break;
        case 0:return;
    }
    }
}

void main(){
    system("cls");
printf("Give the information of the books\n");
struct book arr[5];
for(int i=0;i<5;i++){
    fflush(stdin);
printf("Book %d\nEnter the Accession number : ",i+1);
gets(arr[i].accno);
printf("Enter the author name : ");
gets(arr[i].authname);
printf("Enter the title of the book : ");
gets(arr[i].title);
printf("flag : ");
gets(arr[i].flag);
}
char check[3];
printf("enter END to end the program or enter any key to continue");

performit(arr);
}