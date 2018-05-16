/* ˫��ջ ���� */

#define MaxSize 1000
typedef DStack *PtrDs;
typedef int ElementType; 
struct DStack {
	ElementType Array[MaxSize];
	int Top1;
	int Top2;
};

PtrDs S;
/* Create Double Stack */
PtrDs createStack()
{
	PtrDs S;
	
	S = malloc( sizeof( struct DStack ) );
	S->Top1 = -1;
    S->Top2 = MaxSize;
    return S;
}

/* Push */
void Push( PtrDs S, ElementType item, int Tag )
{   /* Tag ��Ϊ�ж�����ջ�ı�� 1��2 */
	if( S->Top2 - S->Top1 == 1 ) {
		printf("Stack out of sapce!");
		return;
	}
	if( Tag == 1 ) /* ��ջ1���� */
		S->Array[++(S->Top1)] = item;
	else
		S->Array[--(S->Top2)] = item; 
}

/* Pop */
ElementType Pop( PtrDs S, int Tag )
{   /* Tag ��Ϊ�ж�����ջ�ı�� 1��2 */
	if( Tag == 1 ) {/* ��ջ1���� */
		if( S->Top1 == -1 ) {
			printf("ջ1��"); 
			return;
		} else {
			return S->Array[(S->Top1)--];
		}		
	} 
	else            /* ��ջ2���� */
	{
		if( S->Top2 == MaxSize ) {
			printf("��ջ�գ�");
			return;	
		}
        else {
        	return S->Array[(S->Top2)++];
        }			
	}
}

