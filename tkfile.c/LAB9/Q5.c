#include<stdio.h>

void countfrequency(int arr[],int len){
   int freq[10]={0};
   for(int i=0;i<len;i++)++freq[arr[i]];
   for(int i=0;i<10;i++){
    printf("%d occurs %d times\n",i,freq[i]);
   }
}

void main(){
    int sixe;
    char dum;
printf("Give the size of the array : ");
scanf("%d",&sixe);
int arr[sixe];
printf("Give the elements of the array\narr[%d] : ",sixe);
for(int i=0;i<sixe;i++){
    scanf("%d%c",&arr[i],&dum);
}
countfrequency(arr,sixe);


}