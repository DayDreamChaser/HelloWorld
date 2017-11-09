#include <stdio.h>
#define data 202 
//幂的处理上限 

int main(void)
{
    int power[data], coefficient[data];
	// power 幂次数，coefficient 系数
	int i, n，b;
    
    //输入 
    for( i=0, n=1; n<2; n++) {  
    	while( i<data ) {
           scanf("%d %d", &power[i], &coefficient[i]);
           if(power[i]==0) {
   	          if( n==1) b = i;
              break;	
           } 
		   i++;
	    }
    }
    
    for( n=0; n<data; n++) {
       if
        printf("%d",power[n])
   	} 		
}
