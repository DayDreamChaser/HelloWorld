#include "stdio.h"
int main(void)
{
 int year;
 printf("Eeter year:\n");
 scanf("%d",&year);
 if((year%4==0 && year%400!=0)||(year%400==0))
  printf("%d������\n",year);
 else
  printf("%��������\n",year);
 return 0;//wode
}
