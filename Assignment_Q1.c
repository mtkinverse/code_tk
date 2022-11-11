#include<stdio.h>
#include<math.h>
void main(){
int x1=1,y1=3,N,x2,y2,lsd=8;
float dist1,dist2,dist;
if(lsd>0&&lsd<4)N=(pow(2,lsd))*2;
else if(lsd==0)N=(pow(2,lsd))*4+3;
else N=lsd;
printf("\n\nWlecome to the smart city\n\n");
for(int i=1;i<=N;i++){
    printf("Give the position of the robot %d\nGive the X-cordinate : ",i);
    scanf("%d",&x2);
    printf("Give the Y-cordinate : ");
    scanf("%d",&y2);
    dist1=x2-x1; dist1=dist1*dist1;
    dist2=y2-y1; dist2=dist2*dist2;
    dist=dist1+dist2;
    dist=sqrt(dist);
    printf("The distance between the UAV and robot is %.2f meters\n",dist);
}printf("\n\nTHANKS\n\n");
}