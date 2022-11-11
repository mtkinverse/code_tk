#include<stdio.h>
#include<math.h>
void main(){
printf("Printing distance between two points\nPlease provide in meters\n");
float x1,x2,y1,y2;
printf("give the initial points\nx-cordinate,y-cordinate\n");
scanf("%f",&x1);
scanf("%f",&y1);
printf("give the final points\nx-cordinate,y-cordinate\n");
scanf("%f",&x2);
scanf("%f",&y2);
float dx1=(x2-x1);
float dx=dx1*dx1;
float dy1=(y2-y1);
float dy=dy1*dy1;
float d=(dx+dy);
printf("The distance between the points is %.2f\nThe midpoint is (%.2f,%.2f)\n",sqrt (d),(x1+x2)/2,(y1+y2)/2);
    
    }