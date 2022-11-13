#include<stdio.h>
#include<string.h>
int frequency(char checkarr[]){
	int n=strlen(checkarr);
	char send[n+1];
strcpy(send,checkarr);
	int i,j,ind;
	int freq[58]={0};
	for(j=0;j<n;j++){
		++freq[send[j]-65];
		}
	
for(i=1,ind=-1;i<58;i++){
    if(freq[0]==freq[i])ind=-1;
    else
	if(freq[0]<freq[i]){
		freq[0]=freq[i];
	    ind=i;
	}
}

return ind;
}

void checkfrequency(char arr[]){
int ind=frequency(arr);
if(ind==-1)
printf("Tie between some characters\n");

else printf("The character occur most is %c\n",ind+65);

}

void main(){
    int no;
    printf("Give the number of students : ");
    scanf("%d",&no);
while((no--)>0){

	char s[20];
	printf("Give your name : ");
    scanf("\n");
	gets(s);
    checkfrequency(s);

	int n,i;
	printf("How many courses are you studying : ");
	scanf("%d",&n);
	char send[50];

	for( i=0;i<n;i++){

		printf("Give the name of course %d :",i+1);scanf("\n");
		gets(send);
		checkfrequency(send);

	}
    }
}