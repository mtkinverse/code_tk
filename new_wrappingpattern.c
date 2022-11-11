#include<stdio.h>
void main(){
    int n=12;
    for(int j=0;j<7;j++){printf("\t\t\t");
    for(int i=0,c=0;i<=n;i++){////incomplete
           if(j){
            if(i>((n/2)-j)){
                while(i<((n/2)+j)){
                    printf("  ");i++;
                    if(i>6)c--;
                    else c++;
                }
            }
           }
   if(i>=6){printf("%c ",c+65);c--;}
   else {printf("%c ",c+65);c++;}
    }printf("\n");

    }
}