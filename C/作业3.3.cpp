#include <stdio.h>
#define N 6

int main(void)
{
  int v,a[N],i=0,n=N;
  scanf("%d",&v);
  while(n>=1)
  {
   a[i]=v%10;
   v=v/10;
 	
   printf("%d ",a[i]);
   i++;  
   n--;
  }
}