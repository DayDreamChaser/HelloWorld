#include <stdio.h>
#include <time.h>
#include <math.h>
clock_t  start, stop;
double  duration;
#define MAXN 10  /* ����ʽ���ϵ����������ʽ����+1 */
double f1( int n, double a[], double x);  /* �ۼӷ� */
double f2( int n, double a[], double x); /* �۳˷�  x��x+1��(x+2)(3x+3) */
double f3( int n, double a[], double x); /* ����ݹ�*/

int main()
{
	int i;
	double a[MAXN]; /* �洢����ʽ��ϵ��  nΪ�˷���a[n]Ϊϵ�� ,��a[n]*x^n  */
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
	double p = a[n]; /* ����һ��Ϊ a[n]*x^n  + a[n-1]*x^(n-1) */
	for ( i=n; i>0; i--) {
		p = a[i-1] + x*p;
	}
	return p;
}

double f3( int n, double a[], double x)
{
	 /* ����һ��Ϊ a[n]*x^n  + a[n-1]*x^(n-1) */
    if (n < 0)
    {
    	return 0;
    }
    /*���� a[n] Ϊ��С����*/
    else
    {
   	    return a[n]+ x*f2(n-1, a[], x, n);
    }
}