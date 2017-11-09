#include <stdio.h>
int signal( int x );

int main(void)
{
    int n, m, i;
    int count=0;
    scanf("%d%d", &n, &m);
    
    if( n>=1 && n<m && m<=1000 ) {
        for( i=n; i<=m; i++ ) {
            if( signal(i) ) {
                if( count==0 ) {
                    printf("%d", i);
                } else {
                    printf(" %d", i);
                }
                count++;
            }
        }
    }
    return 0;
}

int signal( int x )
{
    int i;
	int sum = 0, flag = 1;
    
    for( i=1; i<x; i++ ) {
        if( x%i==0 ) {
            sum += i;
        }
    }
    if( sum!=x ) {
        flag = 0;
    }
    return flag;
}
