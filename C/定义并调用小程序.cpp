#include <stdio.h>
#include <math.h>

int main()
{
    int a,b,i;
	scanf("%d",&a);
	if( a <= 1 )
	    printf("Enter error!\n");     
    else{
    	b = (int)sqrt(a);       //���a���ܱ�2~��a����һ����������a�ض�������
    	
    	for(i = 2 ;i<=b ;i++ ){
    		if(a%i==0)
    		   break;
    	}  	
    	if(i>b){
    	   printf("%d is sushu\n",a);
	    } else{
	       printf("%d isn't sushu\n",a);
    	}	         	
    }
}



