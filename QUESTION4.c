#include<stdio.h>
void main(){float nts,fsc;
	printf("Give the percentage you secure in NTS and FSc.\nNTS : ");
	scanf("%f",&nts);
	printf("FSc : ");
	scanf("%f",&fsc);
	printf("You can avail :\n");
	if(fsc>70&&nts>70)printf("IT field in Oxford university\n");
	else if(fsc>70&&nts>60)printf("Electronics field in Oxford university\n");
	else if(fsc>70&&nts>50)printf("Telecommunication field in Oxford university\n");
    else if(fsc<=70&&fsc>=60&&nts>=50)printf("IT field in MIT university\n");
	else if(fsc>=50&&fsc<60&&nts>=50)printf("Chemical field in Oxford university\n");
	else if(fsc>40&&fsc<50&&nts>=50)printf("Electronics field in Oxford university\n");
    else printf("Not any partcular field avilable try again later\n");
}
