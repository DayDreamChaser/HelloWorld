#include <stdio.h>
#include <stdlib.h>

void InsertionSort( int A[], int N );
int main(void)
{
	int N;
	printf("Please input the size of the array!\n");
	scanf("%d", &N);
	
	int A[N];
    int i;
	for( i = 0; i < N; i++)
	{
		A[i] = rand() % 100;
	}
	
	InsertionSort( A, N);
	
	for( i = 0; i < N; i++)
	{
		printf("%d ", A[i]);
	}
	
	return 0;
} 

void InsertionSort( int A[], int N )
{
    int j, P;
    
    int temp;
    // 1 to N -1 in right order
	for( P = 1; P < N; P++)
	{
		temp = A[P];
		// j as antiorder,when A[] is sorted, it just cost O(N)
		for( j = P; j > 0 && A[j-1] > temp; j--)
		{
		    A[j] = A[j-1];	
		} 
		A[j] = temp;
	}
}
