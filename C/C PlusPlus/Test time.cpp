#include <iostream>
#include <time.h>
#include <math.h>
using namespace std;
#define MAXK  1e6
clock_t start,end;
double function1(int n, double x);
double function2(int n, double x);
void timer(double (*f)(int n,double x));
double re;
int main()
{
    timer(function1);
    timer(function2);
    return 0;
}
double function1(int n,double x)
{
    re = 1;
    for(int i = 1;i <= n;i++)
    {
        re += pow(x,i)/i;
    }
    return re;
}
double function2(int n, double x)
{
    re = 1.0/n;
    for(int i = n-1; i > 0; i--)
    {
        re = 1.0/i + x*re;
    }
    re = 1 + x*re;
    return re;
}
 
void timer(double (*f)(int n,double x))
{
    double duration;
    start = clock();
    for(int i = 0; i < MAXK; i++)
    {
        f(100,1.1);
    }
    end = clock();
    duration = ((double)(end - start))/CLK_TCK/MAXK;
    cout << re << endl;
    cout << "duration1:"<< duration << endl;
}