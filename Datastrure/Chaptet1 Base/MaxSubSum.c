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
    int m = 1000;  //运行次数   
    int A[MAXN];
    
    for (i = 0; i < MAXN; i++)
    {
    	A[i] = 0;
    }
	 
    double start, finish;   // 开始时间,结束时间 
    start = (double)clock(); // 我的time.h内没有CLOCKS_PER_SEC 
    
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

/* alogrithm1 最大子序列和  O(n^3)*/
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

/* alogrithm2 最大子序列和  O(n^2) */
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

/* alogrithm2 最大子序列和  O(nlogn) */
int Max3( int A, int B, int C )
{ /* 返回3个整数中的最大值 */
    return A > B ? A > C ? A : C : B > C ? B : C;
}
 
int DivideAndConquer( int List[], int left, int right )
{ /* 分治法求List[left]到List[right]的最大子列和 */
    int MaxLeftSum, MaxRightSum; /* 存放左右子问题的解 */
    int MaxLeftBorderSum, MaxRightBorderSum; /*存放跨分界线的结果*/
 
    int LeftBorderSum, RightBorderSum;
    int center, i;
 
    if( left == right )  { /* 递归的终止条件，子列只有1个数字 */
        if( List[left] > 0 )  return List[left];
        else return 0;
    }
 
    /* 下面是"分"的过程 */
    center = ( left + right ) / 2; /* 找到中分点 */
    /* 递归求得两边子列的最大和 */
    MaxLeftSum = DivideAndConquer( List, left, center );
    MaxRightSum = DivideAndConquer( List, center+1, right );
 
    /* 下面求跨分界线的最大子列和 */
    MaxLeftBorderSum = 0; LeftBorderSum = 0;
    for( i=center; i>=left; i-- ) { /* 从中线向左扫描 */
        LeftBorderSum += List[i];
        if( LeftBorderSum > MaxLeftBorderSum )
            MaxLeftBorderSum = LeftBorderSum;
    } /* 左边扫描结束 */
 
    MaxRightBorderSum = 0; RightBorderSum = 0;
    for( i=center+1; i<=right; i++ ) { /* 从中线向右扫描 */
        RightBorderSum += List[i];
        if( RightBorderSum > MaxRightBorderSum )
            MaxRightBorderSum = RightBorderSum;
    } /* 右边扫描结束 */
 
    /* 下面返回"治"的结果 */
    return Max3( MaxLeftSum, MaxRightSum, MaxLeftBorderSum + MaxRightBorderSum );
}
 
int MaxSubseqSum3( int List[], int N )
{ /* 保持与前2种算法相同的函数接口 */
    return DivideAndConquer( List, 0, N-1 );
}

/* alogrithm4 最大子序列和  O(n)*/
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


