#include<stdio.h>
void main(){
    float time,btime;
    ////For regular coffe
float water_sugar=15,mix=20,cof=2,milk=4;
      time=water_sugar+water_sugar+mix+cof+mix;
   ////For Black coffe
float bwater_sugar=20,bmix=25,bcof=15;
     btime=bwater_sugar+bwater_sugar+bmix+bcof+bmix;
   
    char ans,type,cup;
    printf("Hi we are making coffee\nDo you want in regular cup or in doubled cup size\nR for regular and D for doubled\n");
    scanf("%c",&cup);
    switch(cup){
        case 'D':case 'd':
        water_sugar=water_sugar+(water_sugar*0.5);
        mix=mix+(mix*0.5);
        cof=cof+(cof*0.5);
        milk=milk+(milk*0.5);
        bwater_sugar=bwater_sugar+(bwater_sugar*0.5);
        bmix=bmix+(bmix*0.5);
        bcof=bcof+(bcof*0.5);
        break;
    }
    printf("You want to make the coffee manually ?\n");
    scanf(" %c",&ans);
    switch(ans){
        case 'Y':
        case 'y':
        printf("Enter B for black coffe and W for white coffe\n");
        scanf(" %c",&type);
        printf("NOTE : press any key when the opearation is completed\n");
        switch(type){
            case 'B':case 'b':
            printf("Put water %.2f mins\n",bwater_sugar);getch();
            printf("Add sugar %.2f mins\n",bwater_sugar);getch();
            printf("Mix well %.2f mins\n",bmix);getch();
            printf("Add coffee %.2f mins\n",bcof);getch();
            printf("Mix well %.2f mins\n",bmix);getch();
            printf("Total time for making coffe : %.2f mins\n__________THANKS____________\n",btime);
            break;
            case 'W':case 'w':
            printf("Put water %.2f mins\n",water_sugar);getch();
            printf("Add sugar %.2f mins\n",water_sugar);getch();
            printf("Mix well %.2f mins\n",mix);getch();
            printf("Add coffee %.2f mins\n",cof);getch();
            printf("Add Milk %.2f mins\n",milk);getch();
            printf("Mix well %.2f mins\n",mix);getch();
            printf("Total time for making coffe : %.2f mins\n__________THANKS____________\n",time);
            break;
            }
            break;
            case 'N':case 'n':
        printf("Enter B for black coffe and W for white coffe\n");
        scanf(" %c",&type);
        switch(type){
            case 'B':case 'b':
            printf("Put water %.2f mins\n",bwater_sugar);
            printf("Add sugar %.2f mins\n",bwater_sugar);
            printf("Mix well %.2f mins\n",bmix);
            printf("Add coffee %.2f mins\n",bcof);
            printf("Mix well %.2f mins\n",bmix);
            printf("Total time for making coffee : %.2f mins\n__________THANKS____________\n",btime);
            break;
            case 'W':case 'w':
            printf("Put water %.2f mins\n",water_sugar);
            printf("Add sugar %.2f mins\n",water_sugar);
            printf("Mix well %.2f mins\n",mix);
            printf("Add coffee %.2f mins\n",cof);
            printf("Add Milk %.2f mins\n",milk);
            printf("Mix well %.2f mins\n",mix);
            printf("Total time for making coffee : %.2f mins\n__________THANKS____________\n",time);
            break;
        }
        break;
        }
}