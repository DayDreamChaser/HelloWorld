/* MaxSubsequenceSum  */

#include <stdio.h>
#include <time.h>
#define MAXN 100000

int MaxSubSum1(const int A[], int n);
int MaxSubSum2(const int A[], int n);
static int MaxSubSum3(const int A[], int left, int right);
int MaxSubSum4(const int A[], int n);

int main()
{
    printf("This is the MaxsubsequenceSum TEST:\n");
    
    int max , i, j;
    int m = 1000;  //���д���   
    int A[MAXN];
    
    for (i = 0; i < MAXN; i++)
    {
    	A[i] = 0;
    }
	 
    double start, finish;   // ��ʼʱ��,����ʱ�� 
    start = (double)clock(); // �ҵ�time.h��û��CLOCKS_PER_SEC 
    
    for (i=0; i<m; i++)
    {
    	for (j=0; j<MAXN; *(A+j++)=rand()%100); 
    	
  		max = MaxSubSum4(A, MAXN);  
    }
    
    finish = (double)clock();
    printf("MaxSubsequenceSum is : %d\n", max);
    printf("Time required is %.4f s", (finish-start) / m);
    
	return 0;
}

/* alogrithm1 ��������к�  O(n^3)*/
int MaxSubSum1(const int A[], int n)
{
	int thisSum, maxSum;
	int i, j ,k;
	
	maxSum = 0;
	for ( i = 0; i < n; i++)
	{
		for ( j = i; j < n; j++)
		{
			thisSum = 0;		
			for ( k = j; k <= j; k++)
			{
				thisSum += A[j];				
				if ( thisSum > maxSum)
				{
					maxSum = thisSum;
				}	
			}
		}
	}
	return maxSum;
}

/* alogrithm2 ��������к�  O(n^2) */
int MaxSubSum2(const int A[], int n)
{
	 int ThisSum, MaxSum;
	 int i, j;
	 MaxSum = 0;
	 
	 for (i = 0; i < n; i++)
	 {
 	     ThisSum = 0;
		 for (j = i; j < n; j++)
		 {
	         ThisSum += A[j];
			 if (ThisSum > MaxSum)
			 {
                  MaxSum = ThisSum;
 			 }	
 		 }	
 	 } 	 
 	 
 	 return MaxSum;
}

/* alogrithm2 ��������к�  O(nlogn) */
int Max3( int A, int B, int C )
{ /* ����3�������е����ֵ */
    return A > B ? A > C ? A : C : B > C ? B : C;
}
 
int DivideAndConquer( int List[], int left, int right )
{ /* ���η���List[left]��List[right]��������к� */
    int MaxLeftSum, MaxRightSum; /* �������������Ľ� */
    int MaxLeftBorderSum, MaxRightBorderSum; /*��ſ�ֽ��ߵĽ��*/
 
    int LeftBorderSum, RightBorderSum;
    int center, i;
 
    if( left == right )  { /* �ݹ����ֹ����������ֻ��1������ */
        if( List[left] > 0 )  return List[left];
        else return 0;
    }
 
    /* ������"��"�Ĺ��� */
    center = ( left + right ) / 2; /* �ҵ��зֵ� */
    /* �ݹ�����������е����� */
    MaxLeftSum = DivideAndConquer( List, left, center );
    MaxRightSum = DivideAndConquer( List, center+1, right );
 
    /* �������ֽ��ߵ�������к� */
    MaxLeftBorderSum = 0; LeftBorderSum = 0;
    for( i=center; i>=left; i-- ) { /* ����������ɨ�� */
        LeftBorderSum += List[i];
        if( LeftBorderSum > MaxLeftBorderSum )
            MaxLeftBorderSum = LeftBorderSum;
    } /* ���ɨ����� */
 
    MaxRightBorderSum = 0; RightBorderSum = 0;
    for( i=center+1; i<=right; i++ ) { /* ����������ɨ�� */
        RightBorderSum += List[i];
        if( RightBorderSum > MaxRightBorderSum )
            MaxRightBorderSum = RightBorderSum;
    } /* �ұ�ɨ����� */
 
    /* ���淵��"��"�Ľ�� */
    return Max3( MaxLeftSum, MaxRightSum, MaxLeftBorderSum + MaxRightBorderSum );
}
 
int MaxSubseqSum3( int List[], int N )
{ /* ������ǰ2���㷨��ͬ�ĺ����ӿ� */
    return DivideAndConquer( List, 0, N-1 );
}

/* alogrithm4 ��������к�  O(n)*/
int MaxSubSum4(const int A[], int n)
{
	int ThisSum, MaxSum, j;
    ThisSum = MaxSum = 0;
	
	for (j = 0; j < n; j++)
	{
	    ThisSum += A[j];
	    
	    // once the array was read, there isn't need to story it
		if (ThisSum > MaxSum) {
			MaxSum = ThisSum;
		} 
		else 
		if (ThisSum < 0)
		{
			ThisSum = 0;
		}
	}
	
	return MaxSum;
}


