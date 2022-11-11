#include<stdio.h>

void main(){
    char user[50],b,i=0,c;
    int count=0,cap=0,small=0,spe=0,nume=0;
printf("\nHI welcome to the login platform\nEnter your username (DO NOT provide space) : ");
scanf("%s",user);
printf("Give the password\n\nNOTE THAT password should contain atleast 6 characters\nATLEAST 1 numeric, 1 capital and 1 samll charachter,and also 1 special character\nAGAIN note that you can only omit one charachter at a time after writing so write it carefully\n");
while(b!=13){
  b=getche();
  if(b!=32&&b!=13&&b!=8){
    count++;i++;
    c=b;
    switch(c){
        case 65 ... 90:cap++;break;
        case 97 ... 122:small++;break;
        case 33 ... 47:case 58 ... 64:case 91 ... 96:case 126:spe++;break;
        case 48 ... 57:nume++;break;
    }
  }if(b==8){printf(" \b");
    switch(c){
        case 65 ... 90:cap--;break;
        case 97 ... 122:small--;break;
        case 33 ... 47:case 58 ... 64:case 91 ... 96:case 126:spe--;break;
        case 48 ... 57:nume--;break;
    }c=0;
  }
}
if(count<6){printf("Password should contain atleast 6 characters\n");return;}

    if(cap<1||small<1||spe<1||nume<1)printf("Password does not meet the criteria\n\n");
else printf("\n\nWelcome %s you are now logged in\n",user);
}