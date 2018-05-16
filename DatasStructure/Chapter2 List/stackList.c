/* Stack 链表实现 */
/* 在限定位置插入删除的结构 --> 链表头 */ 

/* --堆栈应用-- */

/* #1 编译器平衡符号检查 */
/* 读入文本，将（[{ 开方符号压入栈中，遇到封闭符号]})检查Stack是否IsEmpty() */
/* 再将栈顶元素出栈,进行比对。 符号末尾，堆栈应为空 */

/* #2 运算处理: 后缀运算 and 中缀运算 */
/* 后缀运算，遇到数字push入栈，遇到运算符出栈栈顶2个元素进行运算，结果Push */
/* 中缀-->后缀  a+b*(c-k*2)-i*j+k -> abck2*-*+ij*-k+ 操作数直接输出，遇到操作符，与栈顶符号比较优先级 */
/*  将优先级更高的或相等的元素出栈， （遇到）后出栈里面的元素， 符号串尾，出栈所有符号 */ 

typedef struct SNode *PtrToSNode;
struct SNode {
    ElementType Data;
    PtrToSNode Next;
};
typedef PtrToSNode Stack;
 
Stack CreateStack( ) 
{ /* 构建一个堆栈的头结点，返回该结点指针 */
    Stack S;
 
    S = (Stack)malloc(sizeof(struct SNode));
    S->Next = NULL;
    return S;
}
 
bool IsEmpty ( Stack S )
{ /* 判断堆栈S是否为空，若是返回true；否则返回false */
    return ( S->Next == NULL );
}
 
bool Push( Stack S, ElementType X )
{ /* 将元素X压入堆栈S */
    PtrToSNode TmpCell;
 
    TmpCell = (PtrToSNode)malloc(sizeof(struct SNode));
    TmpCell->Data = X;
    TmpCell->Next = S->Next;
    S->Next = TmpCell;
    return true;
}
 
ElementType Pop( Stack S )  
{ /* 删除并返回堆栈S的栈顶元素 */
    PtrToSNode FirstCell;
    ElementType TopElem;
 
    if( IsEmpty(S) ) {
        printf("堆栈空"); 
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