#include<stdio.h>
void main(){
	char che;
	int i=4,j=1;
	printf("Communicating with SD or Mobile ?\ns-SD\nm-mobile\n");
	scanf("%c",&che);
	switch(che){
	case 's': case 'S':
	for(j;j<=4;j++){
		for(i;i<=6;i++){
			if(i==1){
				printf("***Move straight\n");
			}else{
			
		printf("Move straight\n");}
			}i=1;printf("***\n");
}
    break;
    case 'm': case 'M':
    for(j;j<=4;j++){
		for(i;i<=6;i++){
			if(i==1){
				printf("**Mobile is in city zone\n");
			}else{
			
		printf("Mobile is in city zone\n");}
			}i=1;printf("**\n");
}	
	break;  
	default:printf("Invalid Entry\n");
}
}
