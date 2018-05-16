#include <stdio.h>
#include <time.h>
#include <math.h>

#define MAXN 10
#define MAXK 1e6      //被测函数最大重复次数 
clock_t start, stop;  //clock_t是clock()函数返回的变量类型 
double duration;      //记录被测函数运行时间，以秒为单位 

double f1( int n, double a[], double x );
double f2( int n, double a[], double x );
void PrintTime();

int main()
{   /* 不在测试范围内的准备工作，写在clock()调用之前 */
    int i;
    double a[MAXN];   //存储多项式的系数
	for ( i = 0; i < MAXN; i++)	{
	    a[i] = (double)i;
	}
	
    start = clock();  //开始计时 
    for (i = 0; i < MAXK; i++)
	    f1(MAXN - 1, a, 1.1);     
    stop = clock();   // 停止计时 
    PrintTime();
	
    start = clock();  //开始计时 
    f2(MAXN - 1, a, 1.1);     
    stop = clock();   // 停止计时 
    PrintTime();

    return 0;
}

void PrintTime()
{
    duration = ((double)(stop - start))/CLK_TCK / MAXK;
    printf("ticks2 = %f\n", (double)(stop - start));
    printf("duration2 = %6.2e\n", duration);
}

double f1( int n, double a[], double x )
{
	int i;
	double p = a[0];
	for (i = 1; i <= n; i++) {
	    p += (a[i] * pow(x, i));
	}
	return p;
}

double f2( int n, double a[], double x )
{
	int i;
	double p = a[n];
	for (i = n; i > 0; i--) {
		p = a[i-1] + x * p;
	}
	return p;
}

