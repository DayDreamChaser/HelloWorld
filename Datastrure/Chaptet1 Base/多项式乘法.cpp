#include <stdio.h>
#include <time.h>
#include <math.h>

clock_t start, stop;
/* clock_t是clock()函数返回的变量类型 */
double duration;
/* 记录被测函数运行时间，以秒为单位 */
#define MAXN 10   /* 多项式最大项数， 即多项式阶数+1 */
#define MAXK 1e5
double f1( int n, double a[], double x );
double f2( int n, double a[], double x );

int main () 
{
    int i;
    double a[MAXN];
    for ( i=0; i<MAXN; i++) a[i] = (double)i;
   
    start = clock(); /* Start count time */ 
    for ( i=0; i<MAXK; i++) {
   		f1( MAXN-1, a, 1.1);
    }
    //printf("p = %f\n", p);
    stop = clock();  /* End count time */
    double ticks1 = (double)(stop - start);
    duration = (ticks1 / CLK_TCK) /MAXK;  
    printf("ticks1 = %f\n", ticks1);
    printf("duration = %6.2e\n", duration);
	printf("\n"); 
   
    start = clock(); /* Start count time */ 
    for ( i=0; i<MAXK; i++) {
        f2( MAXN-1, a, 1.1);
    }
    stop = clock();  /* End count time */
    double ticks2 = (double)(stop - start);
    duration = (ticks2 / CLK_TCK) /MAXK;  
    printf("ticks2 = %f\n", ticks2);
    printf("duration = %6.2e\n", duration);
	printf("\n"); 
   
    return 0;
}

double f1( int n, double a[], double x )
{
	int i;
	double p = a[0];
	for ( i=1; i<=n; i++ )
	{
		p += ( pow(x, i) / a[i] ); // x^i / i -->  p += (a[i] * pow(x, i) );
	}
	return p;
}

double f2( int n, double a[], double x)
{
	int i;
	double p = a[n];
	for ( i=n; i>0; i-- )
	{
		p = 1/a[i-1] + x*p; // p = a[i-1] + x*p;
	}
	return p;
}


 