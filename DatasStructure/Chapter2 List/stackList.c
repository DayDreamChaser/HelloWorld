/* Stack ����ʵ�� */
/* ���޶�λ�ò���ɾ���Ľṹ --> ����ͷ */ 

/* --��ջӦ��-- */

/* #1 ������ƽ����ż�� */
/* �����ı�������[{ ��������ѹ��ջ�У�������շ���]})���Stack�Ƿ�IsEmpty() */
/* �ٽ�ջ��Ԫ�س�ջ,���бȶԡ� ����ĩβ����ջӦΪ�� */

/* #2 ���㴦��: ��׺���� and ��׺���� */
/* ��׺���㣬��������push��ջ�������������ջջ��2��Ԫ�ؽ������㣬���Push */
/* ��׺-->��׺  a+b*(c-k*2)-i*j+k -> abck2*-*+ij*-k+ ������ֱ���������������������ջ�����űȽ����ȼ� */
/*  �����ȼ����ߵĻ���ȵ�Ԫ�س�ջ�� �����������ջ�����Ԫ�أ� ���Ŵ�β����ջ���з��� */ 

typedef struct SNode *PtrToSNode;
struct SNode {
    ElementType Data;
    PtrToSNode Next;
};
typedef PtrToSNode Stack;
 
Stack CreateStack( ) 
{ /* ����һ����ջ��ͷ��㣬���ظý��ָ�� */
    Stack S;
 
    S = (Stack)malloc(sizeof(struct SNode));
    S->Next = NULL;
    return S;
}
 
bool IsEmpty ( Stack S )
{ /* �ж϶�ջS�Ƿ�Ϊ�գ����Ƿ���true�����򷵻�false */
    return ( S->Next == NULL );
}
 
bool Push( Stack S, ElementType X )
{ /* ��Ԫ��Xѹ���ջS */
    PtrToSNode TmpCell;
 
    TmpCell = (PtrToSNode)malloc(sizeof(struct SNode));
    TmpCell->Data = X;
    TmpCell->Next = S->Next;
    S->Next = TmpCell;
    return true;
}
 
ElementType Pop( Stack S )  
{ /* ɾ�������ض�ջS��ջ��Ԫ�� */
    PtrToSNode FirstCell;
    ElementType TopElem;
 
    if( IsEmpty(S) ) {
        printf("��ջ��"); 
        return ERROR;
    }
    else {
        FirstCell = S->Next; 
        TopElem = FirstCell->Data;
        S->Next = FirstCell->Next;
        free(FirstCell);
        return TopElem;
    }
}