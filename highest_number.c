#include<stdio.h>

int main(){
    int count=4;
    float arr[30];
for(int i=0;i<count;i++){scanf("%f",&arr[i]); }
for(int i=0;i<count;i++){if(arr[0]<arr[i]){arr[0]=arr[i]; } }
printf("The highest gpa is %f ",arr[0]);


return 0;
}