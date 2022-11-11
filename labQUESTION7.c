#include<stdio.h>
#include<math.h>
int main(){
int a,b,c,disc;
float rut;
printf("Enter the first constant (of x^2)\n");
scanf("%d",&a);if(a==0){printf("Invalid Entry\n");return 0; }
printf("Enter the second constant (of x)\n");
scanf("%d",&b);
printf("Enter the last constant \n");
scanf("%d",&c);
disc=b*b-4*a*c;if(disc<0){printf("The roots are imaginary\n");return 0; }
rut=sqrt(disc);
printf("The roots are x=%f or x=%f\n",(-b+rut)/(2*a),(-b-rut)/(2*a));

return 0;
}