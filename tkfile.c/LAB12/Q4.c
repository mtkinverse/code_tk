#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct info{
	int record;
	char name[20];
	float cost;
	int quan;
};


void display_rec(){
    char s[20];
    struct info a;
    int no,cn=0;
    printf("Give the Record number of the material : ");
    scanf("%d",&no);
    FILE *f=fopen("material.txt","r");
	if(f==NULL)exit(0);
    while(!(feof(f))){
    fscanf(f,"%d %s %d %f",&a.record,a.name,&a.quan,&a.cost);
    if(a.record==no){
    fclose(f);
	cn++;
    break;
    }
}
if (cn)
    printf("record number : %d \nMaterial name : %s \nQuantity : %d\nPrice : %f\n\n",a.record,a.name,a.quan,a.cost);
	else 
printf("The record number you provided does not exist\n");
}

void display_all(){
    struct info a;
    FILE *f=fopen("material.txt","r");
	if(f==NULL){printf("\nFile does not exist\n");return;}
	printf(" Record NO | Material name | Quantity | Price |\n" );
	while(fscanf(f,"%d %s %d %f",&a.record,a.name,&a.quan,&a.cost)!=NULL&&(!(feof(f)))){
    printf("\t%d\t %s\t %d\t %.2f\n",a.record,a.name,a.quan,a.cost);
    }
    fclose(f);
}

void display(){
    int ch;
    printf("Do you want to view the information of\n1- All materials\n2- material on a particular record\n");
    scanf("%d",&ch);
    switch(ch){
        case 1:display_all(); break;
        case 2:display_rec(); break;
    }
}


int get_record_no(){
	struct info a;
	int n=0; 
    FILE *f=fopen("material.txt","r");
    if(f==NULL){printf("---Error\nMay be file does not exist first add some data to file than retry\n");exit(0);}
	while(fscanf(f,"%d %s %d %f",&a.record,a.name,&a.quan,&a.cost)!=NULL&&(!(feof(f)))){
		if(a.record>n)n=a.record;
		printf("%d ",a.record);
	}
    fclose(f);
	printf("The value of last record %d\n",n);
	return n;
}



void addit(){
	int n=0,last_rec;
	char c;
	struct info *rec=(struct info*)malloc(sizeof(struct info));
	last_rec=get_record_no();
	
	do{
		
		n++;
		int i=n-1;
		rec=(struct info*)realloc(rec,n*(sizeof(struct info)));
		rec[i].record=last_rec+n;
		fflush(stdin);
		printf("give the name of the tool : ");
		char checker[20];
		gets(checker);
		strcpy(rec[i].name,checker);
		fflush(stdin);
		printf("Give the quantity of the tool : ");
		scanf("%d",&rec[i].quan);
		printf("Give the cost of the tool : ");
		scanf("%f",&rec[i].cost);
		fflush(stdin);
		printf("press 0 to exit or press any key to add another NEW material\n");
		
	}while((c=getch())!='0');
	
	FILE *write=fopen("material.txt","a");
	for(int x=0;x<n;x++){
		fprintf(write,"%d %s %d %.2f\n",rec[x].record,rec[x].name,rec[x].quan,rec[x].cost);
}
fclose(write);
//free(write);


}

void delit(){
	FILE *fp;
	fp=fopen("material.txt","r");
	if(fp==NULL){printf("The file cannot be opened\n");exit(0);}
struct info *arr=(struct info*)malloc(sizeof(struct info));
struct info a;
int index=0;

   while( !(feof(fp))){
	index++;
	arr=(struct info*)realloc(arr,index*sizeof(struct info));
	fscanf(fp,"%d %s %d %f",&arr[index-1].record,arr[index-1].name,&arr[index-1].quan,&arr[index-1].cost);

   }fclose(fp);
   
   printf("%d\nGive the record number of the material you wnat to DELETE\n",index);
   int n;
   scanf("%d",&n);
   for(int i=0;i<index;i++){
	if(n==arr[i].record){
		for(i;i<index-1;i++){
			arr[i].record=arr[i+1].record;
			arr[i].quan=arr[i+1].quan;
			arr[i].cost=arr[i+1].cost;
			strcpy(arr[i].name,arr[i+1].name);
	        FILE *fw=fopen("material.txt","w");
			for(int x=0;x<(index-1);x++){
            fprintf(fw,"%d %s %d %f\n",arr[x].record,arr[x].name,arr[x].quan,arr[x].cost);
            }
			fclose(fw);
			printf("The information has been deleted\n");
			free(arr);
			return;
		}
	}
   }printf("something went wrong\n");
   free(arr);
}


void update(){
   struct info *arr=malloc(sizeof(struct info));
   int ind=0;
   FILE *fp=fopen("material.txt","r");
   while(!(feof(fp))){
	ind++;
	arr=(struct info*)realloc(arr,ind*sizeof(struct info));
	fscanf(fp,"%d %s %d %f",&arr[ind-1].record,arr[ind-1].name,&arr[ind-1].quan,&arr[ind-1].cost);
   }fclose(fp);
	printf("Give the record number you want to update : ");
	int no;
	scanf("%d",&no);
    for(int i=0;i<ind;i++){
		if(arr[i].record==no){
			fflush(stdin);
			printf("Give the name of the record : ");
			gets(arr[i].name);
			printf("Give the quantity of teh record : ");
			fflush(stdin);
			scanf("%d",&arr[i].quan);
			printf("Give the cost of the record : ");
			scanf("%f",&arr[i].cost);
			FILE *fpw=fopen("material.txt","w");
			for(int i=0;i<(ind-1) ;i++){
				fprintf(fpw,"%d %s %d %f\n",arr[i].record,arr[i].name,arr[i].quan,arr[i].cost);
			}fclose(fpw);
			printf("The information have been updated successfully\n");
		}
	}



}






void main(){
	int check;
	printf("Welcome to the system\nPress the following keys according to your desired actions\n1- Add a new Data\n2- Delete a data\n3- To view the information of the elements\n4- Update any information\n0- To exit the program\n\n");
	scanf("%d",&check);
    switch(check){
    	case 1:
		  addit();
		break;
    	case 2:
		  delit();
		break;
    	case 3:
		  display();
		break;
    	case 4:
		  update();
		break;
    	case 0: exit(1); break;
    	default: printf("invalid Entry\n");
	}
		main();
	
}