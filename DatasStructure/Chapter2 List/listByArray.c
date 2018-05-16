/* ����ʵ�����Ա� */

#include <stdlib.h>
#define MAXSIZE 1000

typedef int ElementType;
typedef struct LNode *List;
struct LNode {
	ElementType Data[MAXSIZE];
	int Length;  /* ���� */
};
struct LNode L; /* L.data[i] or PtrL->data[i] */
List PtrL;

/* #1 Initialize: make empty list */
List MakeEmpty()
{
	List PtrL;
	Ptrl = (List)malloc(sizeof(struct LNode));
	PtrL->Length = 0;
	return PtrL;
}

/* #2 Find: return pos of X */
int Find( ElementType X, List PtrL )
{
	int i = 0;
	/* i range 0 to length-1 */ 
	while( i < PtrL->Length && PtrL->Data[i] != X )
		i++;
		
	if( i >= PtrL->Length ) /* û�ҵ�������ѭ�� */
		return -1;
	else:                /* �ҵ�X */
		return i;
}

/* #3 Insert: insert in ith pos, in data[i-1] */
void Insert( ElementType X, int i, List PtrL )
{
	int j;
	if( i < 1 || i > PtrL->Length+1 ) 
	{
		printf("Out of index!\n");
		return;
	}
	if( PtrL->Length >= MAXSIZE )
	{
		printf("No empty space!\n");
		return;	
	}
	/* ai~anԪ������ƶ�һ��λ�ã���an��ʼ�ƶ� */
	for( j = PtrL->Length; j >= i; i-- ) 
		PtrL->Data[j] = PtrL->Data[j-1];
	
	PtrL->Data[i-1] = X;  /* �����i��λ�� */
	PtrL->Length++; 
	return;
} 

/* #4 Delete ith pos element */
ElementType Delete( int i, List PtrL)
{
	int j;
	if( i < 1 || i > PtrL->Length) 
	{   /* check the empty list*/
		printf("%d Ԫ�ز�����", i);
		return;
	}
	
	ElementType value = PtrL->Data[i-1];
	for( j = i; j < PtrL->Length; j++ )
		PtrL->Data[j-1] = PtrL->Data[j];
    PtrL->Length--;
    return value;
} 

/* #5 Reverse all element */
void Reverse(List PtrL)
{
	if( PtrL->Length <= 0 ) {
		printf("List is empty!");
		return;
	}
	
	int j;  
	ElementType temp;
	for( j = 0; j < PtrL->Length/2; j++ )
	{   /* ��β���� */
 		temp = PtrL->Data[j];
 		PtrL->Data[j] = PtrL->Data[PtrL->Length-1-j];
 		PtrL->Data[PtrL->Length-1-j] = temp;
	}
}

/* #6 Sort*/

/* #7 Binary Search */ 

