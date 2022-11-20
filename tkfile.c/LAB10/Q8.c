#include<stdio.h>
struct box{
    int width,height,length;
};

int calvol(struct box arr[],int i){
    return arr[i].width*arr[i].height*arr[i].length;
}

void main(){
    int n;
scanf("%d",&n);
struct box arr[n];
 
 for(int i=0;i<n;i++){
    scanf("%d %d %d",&arr[i].length,&arr[i].width,&arr[i].height);
 }

 for(int i=0;i<n;i++){
    if(arr[i].height<41)
    printf("%d\n",calvol(arr,i));
 }



}