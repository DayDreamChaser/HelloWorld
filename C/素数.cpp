#include <stdio.h>
#include <math.h>

int main()
{
    int n,m;
	int s,b,i,j,sum;
    int sushu[200]={2,3,}; 
    
    scanf("%d%d", &n, &m);
    
      //sΪ�趨�������1223,��200������   
    for( i=2,s=4; s<1223; s++) { 
       	b=(int)sqrt(s);
      //���a���ܱ�2~��a����һ����������a�ض�������   
    	for( j=2; j<=b; j++) {
  		   if(s%j==0)
             break;
     	}  	
    	
        if(j>b) {
		  sushu[i]=s;
		  i++;
		} 
	      
    } 

	for( i=n-1,sum=0; i<=m-1; i++) {
     	sum+=sushu[i];	
	}
     
    printf("%d\n",sum); 
      
    return 0;
}
 
 