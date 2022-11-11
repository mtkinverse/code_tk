#include<stdio.h>

void main(){
    int tslices,cslices,jumbo,small;
printf("Give the number of tomato slices : ");
scanf("%d",&tslices);
printf("Give the number of cheese slices : ");
scanf("%d",&cslices);
jumbo=(tslices-(2*cslices))/2;
small=cslices-jumbo;
if((tslices==(jumbo*4+small*2))&&(cslices==small+jumbo)&&(jumbo>=0&&small>=0)){
    printf("NO ingredients lost.\nJumbo burgers : %d\nsmall burgers : %d\n",jumbo,small);
}else printf("Not possible\n");

}