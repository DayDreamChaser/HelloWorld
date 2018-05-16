#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define M 1000     /* ִ�д��� */
#define N 500      /* �����С */

void SelectSort(int *a,int l,int r) {
    int i,j,v;
    for (i=0;i<r;i++) {
        for (j=i+1;j<=r;j++) {
            if (*(a+i)>*(a+j))
                v=*(a+i),*(a+i)=*(a+j),*(a+j)=v;
        }
    }
}
void main() {
    int a[N],i,j;
    double start,finish; /* ��ʼʱ��,����ʱ�� */
    start=(double)clock(); /* �ҵ�time.h��û��CLOCKS_PER_SEC */
    for (j=0;j<M;j++) {    /* ִ��M�� */
        for (i=0;i<N;*(a+i++)=rand()%10); /* ÿ�����¸�ֵ */
        SelectSort(a,0,N-1);
    }
    finish=(double)clock();
    printf("%.4fms",(finish-start)/M);
    getchar();
}