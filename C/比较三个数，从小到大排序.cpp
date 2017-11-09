#include "stdio.h"
int main(void)
{
 int a,b,c,x;
 printf("Enter the a b c:\n");
 scanf("%d %d %d",&a,&b,&c);
 if(a>b)
  {x=a;
   a=b;
   b=x;
  }
 if(a>c)
	{x=a;
     a=c;
	 c=x;
    }
 if(b>c)
    {x=b;
     b=c;
	 c=x;
    }
 printf("%d,%d,%d\n",a,b,c);    
 return 0;
}
