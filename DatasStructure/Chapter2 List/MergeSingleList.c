#include <stdio.h>
#include <stdlib.h>

typedef int ElementType;
typedef struct Node *PtrToNode;
struct Node {
    ElementType Data;
    PtrToNode   Next;
};
typedef PtrToNode List;

List Read(); /* 细节在此不表 */
void Print( List L ); /* 细节在此不表；空链表将输出NULL */
void Attach(int num, List *pRear);
List Merge( List L1, List L2 );

int main()
{
    List L1, L2, L;
    L1 = Read();
    L2 = Read();
    //printf("one!");
    L = Merge(L1, L2);
    Print(L);
    Print(L1);
    Print(L2);
    return 0;
}

List Merge( List L1, List L2 )
{  
    List L, T1, T2;
    PtrToNode rear;
    
    T1 = L1->Next;  /* 指向节点 */
    T2 = L2->Next;
    L = (List)malloc(sizeof(struct Node));
    L->Next = NULL;
    rear = L;
    
    while( T1!=NULL && T2!=NULL )
    {
        if( T1->Data < T2->Data )
        {   /* L1节点更小则插入 */           
            rear->Next = T1;
            T1 = T1->Next;
            rear = rear->Next;
        }
        else 
        {
            rear->Next = T2;
            T2 = T2->Next;
            rear = rear->Next;
        }
    }
    while( T1!=NULL )
    {
        rear->Next = T1;
        T1 = T1->Next;
        rear = rear->Next;
    }
    while( T2!=NULL )
    {
        
        rear->Next = T2;
        T2 = T2->Next;
        rear = rear->Next;
    }
    rear->Next = NULL;
    
    L1->Next=NULL;  
    L2->Next=NULL;  
    
    return L;
}

List Read()
{
    int N;   /* number of polynomial terms */
	int num;
	
    List P;    
	List rear; /* rear-insert to create list */
	
	scanf("%d\n", &N);
	P = (List)malloc(sizeof(struct Node));
	P->Next = NULL;
	rear = P;    
    while( N-- )
	{
		scanf( "%d ", &num );
        Attach( num, &rear );
	} 
    return P;   
}

void Attach( int num, List *pRear )
{   /* *pRear need change */
	List tmp;
	
	tmp = (List)malloc(sizeof(struct Node));
    tmp->Data = num;   /* new node assign value*/
	tmp->Next = NULL;
	 
	(*pRear)->Next = tmp;
    *pRear = tmp;  
}

void Print( List L )
{   
    int flag = 0;
    L = L->Next;
	if(!L) {
		printf("NULL\n");
		return;
	}
	
	while( L!=NULL )
	{
		if( flag == 0 )
			flag = 1;
	 	else
	 		printf(" ");
	 		
		printf("%d", L->Data);
		L = L->Next;
	}
	printf("\n");
}
