#include <stdio.h>
#include <time.h>
#include <math.h>
clock_t  start, stop;
double  duration;
#define MAXN 10  /* 多项式最大系数，即多项式阶数+1 */
double f1( int n, double a[], double x);  /* 累加法 */
double f2( int n, double a[], double x); /* 累乘法  x（x+1）(x+2)(3x+3) */
double f3( int n, double a[], double x); /* 逆序递归*/

int main()
{
	int i;
	double a[MAXN]; /* 存储多项式的系数  n为乘方，a[n]为系数 ,如a[n]*x^n  */
	for ( i=0; i<MAXN; i++ ) a[i] = (double)i;
	
	start = clock();
	f1(MAXN-1, a, 1.1); 
	stop = clock();
	duration = ((double)(stop - start))/CLK_TCK;
	printf("ticks1 = %f\n", (double)(stop -start));
	printf("duration1 = %6.2e\n", duration);
	
	start = clock();
	f2(MAXN-1, a, 1.1); 
	stop = clock();
	duration = ((double)(stop - start))/CLK_TCK;
	printf("ticks2 = %f\n", (double)(stop -start));
	printf("duration2 = %6.2e\n", duration);
	
	return 0;
}

double f1( int n, double a[], double x)
{
	int i;
	double p = a[0];
	for ( i=1; i<=n; i++) {
		p += (a[i] * pow(x, i));
	}
	return p;
}

double f2( int n, double a[], double x)
{
	int i;
	double p = a[n]; /* 最内一层为 a[n]*x^n  + a[n-1]*x^(n-1) */
	for ( i=n; i>0; i--) {
		p = a[i-1] + x*p;
	}
	return p;
}

double f3( int n, double a[], double x)
{
	 /* 最内一层为 a[n]*x^n  + a[n-1]*x^(n-1) */
    if (n < 0)
    {
    	return 0;
    }
    /*逆序 a[n] 为最小常数*/
    else
    {
   	    return a[n]+ x*f2(n-1, a[], x, n);
    }
}