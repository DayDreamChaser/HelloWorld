typedef int ElementType; 
typedef struct LNode *PtrToLNode;
typedef PtrToLNode Position;
typedef PtrToLNode List;
struct LNode {
    ElementType Data;
    PtrToLNode Next;
};

List L;

/* LΪ��ͷ������� reverseͷ������ʵ�� */
List Reverse1(List L)
{  /* ͷ���ָ��NULL, �ٽ������ڵ�ͷ���β��� */
	Position p;      /* ���Ӻ����ڵ�ָ�� */
	Position cur;    /* ��ǰ����ָ�� */
	p = L->Next;     /* ָ��������� */
	cur = p;
	L->Next = NULL;
	
	while( p!=NULL ) /* ���������ƶ���ֱ��ΪNULL */ 
	{
		p = p->Next; /* ָ����һ�ڵ� */
		/* ����ǰ�ڵ����L */
		cur->Next = L->Next;
		L->Next = cur; 
		cur = p; /* �ƶ����¸��ڵ� */ 
	} 
	
	return L;
}

/* ����ת�����ڵ����η�ת  */ 
List Reverse2(List L)
{   /* ʹ��3��ָ��ָ��ǰ���С��������ڵ� */
	Position pre;
	Position p;        /* �����ڵ� */
	Position rear; 
	p = L->Next;
	rear = p->Next;
	
	p->Next = NULL;       /* ����һ���ڵ��Ϊβ�ڵ� */
	/* rearָ���ڵ㣬��rear==NULL��p��Ϊ���ڵ� */
	while( rear!= NULL ) 
	{   /* �������� */ 
		pre = p;       /* ָ�����κ��� */
		p = rear;
		rear = rear->Next;
	    /*  */	
	    p->Next = pre; /* ����ڵ㷭ת */ 
	} 
	L->Next = p;
	
	return L;
}