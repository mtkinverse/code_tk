#include<stdio.h>

void main(){
float weight,height,un_wgh=18.5,nor1=18.5,nor2=24.9,over1=25,over2=29.9,obese=30,bmi;
printf("Give your weight in Kilogram\n");
scanf("%f",&weight);
printf("Give your height in Meters\n");
scanf("%f",&height);
height=height*height;
bmi=weight/height;
printf("Your Body Mass Index Calculation(BMI) : %.3f\n",bmi);
printf("BIMI VALUES,\nUnderweight : less than %.2f\nNormal : between %.2f and %.2f\nOverweight : between %.2f and %.2f\nObese : %.2f or greater\n",un_wgh,nor1,nor2,over1,over2,obese);

}