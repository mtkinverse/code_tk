#include<stdio.h>

int main(){
int amount,outcome;
printf("Welcome to the change distributer\nGive your amount\n");
scanf("%d",&amount);
outcome=amount/5000;
printf("There are,\n%d notes of 5000\n",outcome);
amount=amount-(outcome*5000);
outcome=amount/1000;
printf("%d notes of 1000\n",outcome);
amount=amount-(outcome*1000);
outcome=amount/500;
printf("%d notes of 500\n",outcome);//key step int will return a value before decimal
amount=amount-(outcome*500);
outcome=amount/100;
printf("%d notes of 100\n",outcome);
amount=amount-(outcome*100);
outcome=amount / 50;
printf("%d notes of 50\n",outcome);
amount=amount-(outcome*50);
printf("\n_NOTE_\nyour remaining balance is %d\n",amount);

return 0;}