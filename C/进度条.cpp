#include "windows.h"
#include "stdio.h"
#include "unistd.h"

int
main(void)
{
 for (int i=0;i<=100;i++)
 {  
     printf("������Ů������%d%%��\r",i);
	 fflush(stdout);
	 Sleep(150);
 }
 printf("\n����Ů����\n");
 return 0;
}