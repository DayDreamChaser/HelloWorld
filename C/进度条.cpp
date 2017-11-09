#include "windows.h"
#include "stdio.h"
#include "unistd.h"

int
main(void)
{
 for (int i=0;i<=100;i++)
 {  
     printf("交过的女朋友有%d%%个\r",i);
	 fflush(stdout);
	 Sleep(150);
 }
 printf("\n吾阅女无数\n");
 return 0;
}