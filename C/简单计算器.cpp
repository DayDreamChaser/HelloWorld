#include<stdio.h>
int main(void)
{
 float a,b;
 char d;
 printf("\nEnter the calculation:\n");
 scanf("%f %c %f",&a,&d,&b);
 switch(d)
 { 
  case '+': printf("= %.3f\n",a+b);break;
  case '-':	printf("= %.3f\n",a-b);break;
  case '*': printf("= %.3f\n",a*b);break;
  case '/':
	{if((long)b==0)
	  printf("\n\n\aDivision by zero error!\n");
	 else
	  printf("= %.3f\n",a/b);
	} break;
  case '%':             /* Cheak second operand for zero */
	{if((long)b==0)
	  printf("\n\n\aDivision by zero error!\n");
	 else
	  printf("= %d\n",(long)a%(long)b);
	} break;
  default: printf("input error\n");
 }
 return 0;
}