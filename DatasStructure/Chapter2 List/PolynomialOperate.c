/* Polynomial add and mutilpy arthimatic */
#include <stdio.h>
#include <stdlib.h>

typedef struct PolyNode *PtrToNode;
typedef PtrToNode Polynomial;
struct PolyNode {
	int coef;   /* coeficient */
	int expon;  /* expontential */
	PtrToNode next; 
};


Polynomial ReadPoly();
void PrintPoly( Polynomial Poly );
void Attach( int c, int e, PtrToNode *pRear );
int Compare( int expon, int expon2 ); 
Polynomial Add( Polynomial P1, Polynomial P2 );
Polynomial Mult( Polynomial P1, Polynomial P2 );

int main(void)
{
	Polynomial P1, P2, PP, PS;
	
	P1 = ReadPoly();
	P2 = ReadPoly();
	PP = Mult( P1, P2);
	PrintPoly(PP);
	PS = Add( P1, P2);
	PrintPoly(PS);
	
	return 0;
}

/* read polynomial input, and save as list */
Polynomial ReadPoly()
{
	/* 4  3 4  -5 2  6 1 -2 0 */
	int N;   /* number of polynomial terms */
	int c, e;
	Polynomial P;    
	Polynomial tmp;  /* temporory pointer */
	Polynomial rear; /* rear-insert to create list */
	
	scanf("%d", &N);
	P = (Polynomial)malloc(sizeof(struct PolyNode));
	P->next = NULL;
	rear = P;
	while( N-- )
	{
		scanf("%d %d", &c, &e);
		Attach( c, e, &rear); /* insert current node to rear */
	} 
	
	tmp = P;  /* release head node */  
    P = P->next;
    free(tmp);
    
	return P; /* return no head node polynomial */ 
}

/* output polynomial  */
void PrintPoly(Polynomial Poly)
{
	int flag = 0;
	if(!Poly) {
		printf("0 0\n");
		return;
	}
	
	while( Poly!=NULL )
	{
		if( !flag )
			flag = 1;
	 	else
	 		printf(" ");
	 		
		printf("%d %d", Poly->coef, Poly->expon );
		Poly = Poly->next;
	}
}

void Attach(int c, int e, Polynomial *pRear)
{   /* *pRear need change */
	Polynomial cur;
	
	cur = (Polynomial)malloc(sizeof(struct PolyNode));
    cur->coef = c;   /* new node assign value*/
	cur->expon = e;
	cur->next = NULL;
	 
	(*pRear)->next = cur;
    *pRear = cur;  
}

int Compare( int expon1, int expon2 )
{
    if( expon1 == expon2 )
    {   
        return 0;
    }
    else if( expon1 > expon2 )
    {
        return 1;
    }
    else
    {
        return -1;
    }
}

/* add two polynomial into one  */
Polynomial Add( Polynomial P1, Polynomial P2)
{
	int sum;
    Polynomial T1, T2; /* 遍历链表指针 */
    Polynomial head, rear, tmp;
    
    T1 = P1;  /* use tmp pointer */
    T2 = P2;
    head = (Polynomial)malloc(sizeof(struct PolyNode));
    head->next = NULL;
    rear = head;
    
    while( T1 && T2 )
    {   /* 增序排列链表 */
        switch( Compare( T1->expon, T2->expon) )
        {
            case 1:  /* T1->expon > T2>expon */
                Attach( T1->coef, T1->expon, &rear);
                T1 = T1->next;
                break;
            case -1: /* T1->expon < T2>expon */
                Attach( T2->coef, T2->expon, &rear);
                T2 = T2->next;
                break;
            case 0:  /* T1->expon == T2>expon */
                sum = T1->coef + T2->coef;
                if( sum ) Attach( sum, T1->expon, &rear);
                T1 = T1->next;
                T2 = T2->next;
                break;
            default:
                break;          
        }
    }
    for(; T1; T1=T1->next) {
        Attach( T1->coef, T1->expon, &rear);
    }   
    for(; T2; T2=T2->next) {
        Attach( T2->coef, T2->expon, &rear);
    }  
    
    tmp = head;
    head = head->next;
    free(tmp);
    
    return head;
}

/* multply two polynomial into one  */
Polynomial Mult( Polynomial P1, Polynomial P2)
{
    if( !P1||!P2 ) return NULL;
        
    int c, e;
    Polynomial T1, T2; /* 遍历链表指针 */
    Polynomial head, rear, tmp;
    
    T1 = P1;  /* use tmp pointer */
    T2 = P2;
    head = (Polynomial)malloc(sizeof(struct PolyNode));
    head->next = NULL;
    rear = head;
  
    while( T2 ) /* P1第一项乘以P2所有项 */
    {   /* 增序排列链表 */
        Attach( T1->coef*T2->coef, T1->expon*T2->expon, &rear);
        T2 = T2->next;
    }
    T1 = T1->next;
    
    while( T1 )
    {
        T2 = P2; /* 重新指向头结点 */
        rear = head;
        while( T2 )
        {
            e = T1->expon*T2->expon;
            c = T1->coef*T2->coef;
            /* 有序插入节点  找寻合适位置插入 */
            while( rear->next && rear->next->expon > e){
                /* if rear->next->expon < e then insert after rear*/
                rear = rear->next; 
            }
            if( rear->next && rear->next->expon == e )
            {   /* 指数相同 相加后系数为零则删除 */
                if( rear->next->coef + c )
                    rear->next->coef += c;
                else {
                    tmp = rear->next;    
                    rear->next = rear->next->next;
                    free(tmp);
                }
            }
            else
            {   /* 新建节点插入 在rear后插入 */
                tmp = (Polynomial)malloc(sizeof(struct PolyNode));
                tmp->expon = e;
                tmp->coef = c;
                tmp->next = rear->next;
                rear->next = tmp;
                rear = rear->next;
            }
            T2 = T2->next;
        }
        T1 = T1->next;
    }
    tmp = head;
    head = head->next;
    free(tmp);
    
    return head;
}

