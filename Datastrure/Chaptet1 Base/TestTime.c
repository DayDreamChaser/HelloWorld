#include <stdio.h>
#include <time.h>
#include <math.h>

#define MAXN 10
#define MAXK 1e6      //���⺯������ظ����� 
clock_t start, stop;  //clock_t��clock()�������صı������� 
double duration;      //��¼���⺯������ʱ�䣬����Ϊ��λ 

double f1( int n, double a[], double x );
double f2( int n, double a[], double x );
void PrintTime();

int main()
{   /* ���ڲ��Է�Χ�ڵ�׼��������д��clock()����֮ǰ */
    int i;
    double a[MAXN];   //�洢����ʽ��ϵ��
	for ( i = 0; i < MAXN; i++)	{
	    a[i] = (double)i;
	}
	
    start = clock();  //��ʼ��ʱ 
    for (i = 0; i < MAXK; i++)
	    f1(MAXN - 1, a, 1.1);     
    stop = clock();   // ֹͣ��ʱ 
    PrintTime();
	
    start = clock();  //��ʼ��ʱ 
    f2(MAXN - 1, a, 1.1);     
    stop = clock();   // ֹͣ��ʱ 
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

