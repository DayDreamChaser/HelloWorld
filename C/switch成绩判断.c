#include "stdio.h"
int main(void)
{
    int length, i;
    char string[]="wocghao", *a;
	a = string; 
	
	printf("Press a string:");

	
	for( length = 0; *a++ != '\0'; ) {
		length += 1;
	}    
    
    printf("length=%d\n", length);
}