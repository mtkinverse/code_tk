/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>
//y math wala pow ki waja se add hoa hai 
#include <math.h>

int main() {
    printf("Calculating radius of sphere \n");
    float V;
    printf("proivde the volume of sphere \n");
scanf("%f", &V);
float X = 0.2387 * V ;
float C =0.3333;
printf("radius of the sphere is : %f \n", pow ( X , C ) );
int answer;
printf("number of correct answers: \n");
scanf("%d",&answer);
answer >= 5 ? printf("congatulations you are pass \n"): printf("you are fail \n");
char sec:
printf("what is your section \n");
scanf("%s",&sec);
switch(sec){
    case 'A': printf("your result will be available on monday\n");
    break;
    case 'B' : printf("your result will be available on tuesday \n");
    break;
    case 'C': printf("your result will be at wednesday \n");
    break;
    default: printf("you should contact to administration \n");
}
int RN;
printf("provide your roll number \n");
scanf("%d", &RN);
RN <= 20 ? printf("you will recieve in 1st shift \n"):printf("you will recieve in 2nd shift");
printf( "------------       THANKS          -------");
       return 0;
}

