#include<stdio.h>
#include<math.h>
int main(){
int arr[2][2];
printf("give the initial points\n");
for(int i=0;i<2;i++){scanf("%d",&arr[0][i]); } 
printf("give the final points\n");
for(int i=0;i<2;i++){scanf("%d",&arr[1][i]); }
int dx1=(arr[1][0] - arr[0][0]);//(x2-x1)
int dx=dx1*dx1;//(x2-x1)^2
int dy1=(arr[1][1] - arr[0][1]);//(y2-y1)
int dy=dy1*dy1;//(y2-y1)^2
int d=(dx+dy);float r=(0.5);
printf("The distance btween the points is %f\n\n__Thanks__\n\n",pow(d,r));//[(del x)+(del y)]^(1/2)
return 0;
}