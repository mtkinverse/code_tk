#include<stdio.h>
void main(){int a,b,lcm;
  printf("Give the numbers\nNumber 1: ");
  scanf("%d",&a);
  printf("Number 2 : ");
  scanf("%d",&b);
  if(a%2==0&&b%2==0){a=a/2;( a==b ? lcm=a: (lcm = a*b));}
  else if(a%3==0&&b%3==0){a=a/3;( a==b ? lcm=a: (lcm = a*b));}
  else if(a%5==0&&b%5==0){a=a/5;( a==b ? lcm=a: (lcm = a*b));}
  else if(a%5==0&&b%7==0){a=a/7;( a==b ? lcm=a: (lcm = a*b));}
  else if(a%2==0&&b%2!=0||a%3==0&&b%3!=0||a%5==0&&b%5!=0||a%7==0&&b%7!=0)a>b?(a%b==0?lcm=a:(lcm=a*b)):(b%a==0?lcm=b:(lcm=a*b));
  else lcm=a*b;
printf("The LCM of the given numbers is : %d\n",lcm);
}