#include <stdio.h>
#include <time.h>
 
void PrintN_Loop(int N);        // ѭ��ʵ��
void PrintN_Recursion(int N);   // �ݹ�ʵ��
 
int main(int argc, const char * argv[]) 
{
    // insert code here...
    //printf("Hello, World!\n");
    clock_t start, stop;
    double duration_loop = 0.0;
    double duration_recursion = 0.0;
    int num = 0;
    printf("������N��ֵ��");
    scanf("%d", &num);
    // ѭ��ʵ��
    start = clock();
    PrintN_Loop(num);
    stop = clock();
    duration_loop = (double)(stop - start)/CLOCKS_PER_SEC;
    // �ݹ�ʵ��
    start = clock();
    PrintN_Recursion(num);
    stop = clock();
    duration_recursion = (double)(stop - start)/CLOCKS_PER_SEC;
    // ���ʱ��
    printf("ѭ��ʵ��ʱ�䣺%f\n", duration_loop);
    printf("�ݹ�ʵ��ʱ�䣺%f\n", duration_recursion);
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