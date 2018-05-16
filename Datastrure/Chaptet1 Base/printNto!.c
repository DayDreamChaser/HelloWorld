#include <stdio.h>
#include <time.h>
 
void PrintN_Loop(int N);        // 循环实现
void PrintN_Recursion(int N);   // 递归实现
 
int main(int argc, const char * argv[]) 
{
    // insert code here...
    //printf("Hello, World!\n");
    clock_t start, stop;
    double duration_loop = 0.0;
    double duration_recursion = 0.0;
    int num = 0;
    printf("请输入N的值：");
    scanf("%d", &num);
    // 循环实现
    start = clock();
    PrintN_Loop(num);
    stop = clock();
    duration_loop = (double)(stop - start)/CLOCKS_PER_SEC;
    // 递归实现
    start = clock();
    PrintN_Recursion(num);
    stop = clock();
    duration_recursion = (double)(stop - start)/CLOCKS_PER_SEC;
    // 输出时间
    printf("循环实现时间：%f\n", duration_loop);
    printf("递归实现时间：%f\n", duration_recursion);
    return 0;
}
 
void PrintN_Loop(int N)
{
    int i;
    for (i=1; i<=N; i++)
    {
        printf("%d\n", i);
    }
    return;
}
 
void PrintN_Recursion(int N)
{
    if (N)
    {
        PrintN_Recursion(N - 1);
        printf("%d\n", N);
    }
    return;
}