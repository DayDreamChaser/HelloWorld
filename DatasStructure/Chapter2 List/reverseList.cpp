typedef int ElementType; 
typedef struct LNode *PtrToLNode;
typedef PtrToLNode Position;
typedef PtrToLNode List;
struct LNode {
    ElementType Data;
    PtrToLNode Next;
};

List L;

/* L为带头结点链表， reverse头结点插入实现 */
List Reverse1(List L)
{  /* 头结点指向NULL, 再将后续节点头依次插入 */
	Position p;      /* 连接后续节点指针 */
	Position cur;    /* 当前工作指针 */
	p = L->Next;     /* 指向后续链表 */
	cur = p;
	L->Next = NULL;
	
	while( p!=NULL ) /* 依次向下移动，直到为NULL */ 
	{
		p = p->Next; /* 指向下一节点 */
		/* 将当前节点插入L */
		cur->Next = L->Next;
		L->Next = cur; 
		cur = p; /* 移动到下个节点 */ 
	} 
	
	return L;
}

/* 链表翻转，各节点依次反转  */ 
List Reverse2(List L)
{   /* 使用3个指针指向前、中、后三个节点 */
	Position pre;
	Position p;        /* 工作节点 */
	Position rear; 
	p = L->Next;
	rear = p->Next;
	
	p->Next = NULL;       /* 将第一个节点变为尾节点 */
	/* rear指向后节点，当rear==NULL，p则为最后节点 */
	while( rear!= NULL ) 
	{   /* 遍历处理 */ 
		pre = p;       /* 指针依次后移 */
		p = rear;
		rear = rear->Next;
	    /*  */	
	    p->Next = pre; /* 链表节点翻转 */ 
	} 
	L->Next = p;
	
	return L;
}