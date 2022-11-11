#include<stdio.h>


int sum=0;
int find_nth_term(int n, int a, int b, int c) {
    sum=a+b+c;
  if(!(n<=4))
  find_nth_term(--n,b,c,sum);
  return sum;
}
 
 int main(){
    int n, a, b, c,ans;
  
    scanf("%d %d %d %d", &n, &a, &b, &c);
    ans = find_nth_term(n, a, b, c);
 
    printf("%d", ans); 
    return 0;
}