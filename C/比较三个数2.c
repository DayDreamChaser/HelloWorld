#include "stdio.h"

int main()
{
    const int number = 10;      /* 数组大小 */ 
    int count[number];          /* 定义数组 */
    
	int i;
	int x;
    
    for ( i=0; i<number; i++) { /* 初始化数组 */ 
    	count[i] = 0;	
    }
    
    scanf("%d",&x);
    while( x!= -1 ) {
        if ( x>=0 && x<=9) {
   	        count[x]++;        /* 数组参与运算 */
        }	
        scanf("%d", &x);
    }
    
    for ( i=0; i<number; i++) {/* 数组的遍历 */
    	printf("%d:%d\n", i, count[i]);    	
    }
 
 return 0;
}
