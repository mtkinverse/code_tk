#include<stdio.h>
void main(){float n;int  N;
    printf("\t\t\t\n\nThe National Earthquake Information Centre\n\nGive the Ritcher Scale Number (n) :");
    scanf("%f",&n);
    if(n<0)printf("Invalid Entry\n");
    else if(n<5.0)N=0;
    else if(n>=5.0&&n<5.5)N=1;
    else if(n>=5.5&&n<6.5)N=2;
    else if(n>=6.5&&n<7.5)N=3;
    else if(n>=7.5)N=4; 
    switch(N){
        case 0:
        printf("Little or no damage\n");
        break;
        case 1:
        printf("Some Damage\n");
        break;
        case 2:
        printf("Seriuos Damage : Walls may fall or Crack\n");
        break;
        case 3:
        printf("Disaster : Houses and buildings may collapse\n");
        break;
        case 4:
        printf("Catastrophe : most buildings destroyed\n");
        break;
        default:
        printf("Invalid Entry\n");
    }
main();}