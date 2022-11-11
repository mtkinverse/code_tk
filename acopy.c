#include <stdio.h>
////////This is a copy code found at drive////////
int main() {
	int i,j,n;
	printf("Enter the number of repititions: ");
	scanf("%d",&n);
	//print za rows
	for (i =1;i<=n;i++) {
		//print za columns  since colums are odd use sequence formulae
		for(j=1;j<=2*n-1;j++) {
			//to print the stars  according to their matrices
			if(j>=n-(i-1) && j<=n+(i-1)){
				printf("*");
			} else {
				printf(" ");
			}
		}
		printf("\n");
	}}