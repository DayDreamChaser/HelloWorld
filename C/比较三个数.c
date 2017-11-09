#include "stdio.h"
int main()
{
 int a,b,c,max;
 printf("Please input three number:");
 scanf("%d %d %d",&a,&b,&c);
 printf("a=%d,b=%d,c=%d\n",a,b,c);
 if (a>b)  max=a;
 else  max=b;
 if (c>max)   max=c; 
 printf("max=%d\n",max);
 }
