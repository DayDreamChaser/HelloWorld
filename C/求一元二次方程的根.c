#include "stdio.h"
#include "math.h"
int main(void)
{
 float a,b,c;
 printf("Enter the a b c:\n");
 scanf("%f%f%f",&a,&b,&c);
 if(b*b-4*a*c>0)
   {double x1,x2;
	x1=(-b+sqrt(b*b-4*a*c))/(2*a);
	x2=(-b-sqrt(b*b-4*a*c))/(2*a);
	printf("���̵ĸ���%.2lf��%.2lf\n",x1,x2);
   }
 if(b*b-4*a*c==0)
   {double x;
	x=(-b)/(2*a);
	printf("���̵ĸ�Ϊ%.2lf\n",x);
   }
  if(b*b-4*a*c<0)
	printf("������ʵ����\n");
 return 0;
} 