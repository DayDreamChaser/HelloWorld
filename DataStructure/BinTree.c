/* Application about traversal for BinTree */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MaxSize 1000
typedef int ElementType;
typedef struct TreeNode *BinTree;
struct TreeNode {
	ElementType Element;
	BinTree Left;
	BinTree Right;
};

BinTree FindMin( BinTree BST )
{
	if( BST ) {
		while( BST->Left )
			BST = BST->Left;
	}
	return BST;
}

BinTree Insert( BinTree BST, ElementType X )
{
    if( !BST ){ /* 若原树为空，生成并返回一个结点的二叉搜索树 */
        BST = (BinTree)malloc(sizeof(struct TreeNode));
        BST->Element = X;
        BST->Left = BST->Right = NULL;
    }
    else { /* 开始找要插入元素的位置 */
        if( X < BST->Element )
            BST->Left = Insert( BST->Left, X );   /*递归插入左子树*/
        else  if( X > BST->Element )
            BST->Right = Insert( BST->Right, X ); /*递归插入右子树*/
        /* else X已经存在，什么都不做 */
    }
    return BST;
}

BinTree Delete( BinTree BST, int N )
{
	BinTree tmp;
	if( !BST ) {
		printf("Empty Tree!");
	} 
	else {
		if( N < BST->Element )
			BST->Left = Delete( BST->Left, N );
		if( N > BST->Element )
			BST->Right = Delete( BST->Right, N );
		else {    /* already found node to delete */
			if( BST->Left && BST->Right ) {
				/* BST contain two nodes */
				tmp = FindMin( BST->Right ); /* find minimun in right branch */
				BST->Element = tmp->Element;
				BST->Right = Delete( BST->Right, BST->Element);
			}
			else { /* single node or no node */
				tmp = BST;
				if( !BST->Left )
					BST = BST->Right; /* only have right child or no child */
				else
					BST = BST->Left;
				free( tmp ); 
			}
		}
	}
	return BST;
}

int TwoBranch( BinTree BT )
{
	if( BT==NULL )
		return 0;
	else if( BT->Left && BT->Right )
		return ( TwoBranch(BT->Left)+TwoBranch(BT->Left)+1 );
	else
		return ( TwoBranch(BT->Left)+TwoBranch(BT->Left) );
}

void PreOrder( BinTree BT )
{
	if( BT ) {
		printf("%d ", BT->Element);
        PreOrder( BT->Left );
		PreOrder( BT->Right );
	}
} 

void PreOrderTraversal( BinTree BT )
{
	BinTree T = BT;
	BinTree S[MaxSize];
 	int Top = -1;

	while( T || Top!=-1 ) {
		if( T!=NULL ) {
			printf("%d ", T->Element);
  			S[++Top] = T; // Push
			T = T->Left;
		}
		else {
			T = S[Top--]; // Pop
			T = T->Right; 
		} 
	}
} 

void PreOrderLeaves( BinTree BT )
{	/*  OutPut leaf node */
	if( BT ) {
		if( BT->Left==NULL && BT->Right==NULL ) 
		{   /* left and right leaf are void */
			printf("%d ", BT->Element);		
		}
  		PreOrderLeaves( BT->Left );
	 	PreOrderLeaves( BT->Right );
	}
} 
 
void InOrder( BinTree BT )
{	/* 中序遍历  */
	if( BT) {
        InOrder( BT->Left );
        printf("%d ", BT->Element);
		InOrder( BT->Right );
	}
}

void PostOrder( BinTree BT )
{	/* 后序遍历 */
	if( BT ) {
        PostOrder( BT->Left );   
		PostOrder( BT->Right );
		printf("%d ", BT->Element);
	}	
}

void PostOrderAncestor( BinTree BST , int X)
{
	BinTree T = BST;
	BinTree rec = NULL;
	BinTree S[MaxSize];
 	int Top = -1;

	while( T || Top!=-1 ) {
		if( T!=NULL ) {
  			S[++Top] = T; // Push
			T = T->Left;
		}
		else {
			T = S[Top];    //  GetTop(S);
			if( T->Right && T->Right!= rec ) {//if right node exist, turn left 
				T = T->Right;
				S[++Top] = T; // Push( S, T );
				T = T->Left;
			}
			else {
				T = S[Top--]; // Pop
				if( T->Element == X ) {
					int i;
					printf(" ancestor node of the X: ");
					for( i=1; i<=Top; i++ )
						printf("%d ", S[i]->Element);
					break;	
				}//printf("%d ", T->Element);
				rec = T;  
				T = NULL; 
			}  
		}
	}
}

/* Sloving Height of Tree */
int PostOrderHeight( BinTree BT )
{   /* Height = max(HL, HR) + 1 */
	int HL, HR, MaxH;
	if( BT )	{
        HL = PostOrderHeight( BT->Left );  /* height of left-child tree*/ 
		HR = PostOrderHeight( BT->Right ); /* height of right-child tree*/ 
		MaxH = (HL > HR) ? HL : HR;
		return ( MaxH + 1); /* return height of tree */
	}	
	else {
		return 0;  /* empty tree height is 0 */
	}
}

int LevelOrderHigh( BinTree BST )
{
	if( !BST ) return;
	int rear = -1, front = -1;
	int last = 0, level = 0; // record level info
	int count = 0, MaxNum = 1;  // mark node num
	BinTree Q[MaxSize];
	
	BinTree p;
	Q[++rear] = BST;    // EnQueue
	while( front < rear ) {
		p = Q[++front]; // DeQueue
		printf("%d ", p->Element);
		
		if( p->Left ) {
			Q[++rear] = p->Left;
			count++;			
		}
		if( p->Right) {
			Q[++rear] = p->Right;
			count++;				
		}
		if( front == last ) {   // reach edge of previous level 
			level++;
			last = rear;
			if( MaxNum < count ) {
				MaxNum = count; // every level count largest num
				count = 0;
			}
		}
	} 
	printf("\n Width of tree：%d", MaxNum);
	return level;
}

void InverseLevel( BinTree BST )
{
	if( !BST ) return;
	BinTree p;
	BinTree S[MaxSize];
	BinTree Q[MaxSize];
	int top = -1;
	int rear = -1, front = -1;

	Q[++rear] = BST;    // EnQueue
	while( front < rear ) {
		p = Q[++front]; // DeQueue
		S[++top] = p;   // push
		if( p->Left )
			Q[++rear] = p->Left; //  EnQueue
		if( p->Right)
			Q[++rear] = p->Right;
	} 
	while( top!=-1 ) {  // inverse output
		p = S[top--];
		printf("%d ", p->Element);
	} 
}

int WplByLevel( BinTree BST )
{	// weight path length
	if( !BST ) return;
	BinTree p;
	BinTree Q[MaxSize];
	int wpl = 0;
	int last = 0, depth = 0;
	int rear = -1, front = -1;

	Q[++rear] = BST;    // EnQueue
	while( front < rear ) {
		p = Q[++front]; // DeQueue
		if( p->Left==NULL && p->Right==NULL ) { 
			wpl += depth * p->Element;// count wpl if leaf node
		}
		if( p->Left )
			Q[++rear] = p->Left; //  EnQueue
		if( p->Right)
			Q[++rear] = p->Right;
		if( front == last ) {
			depth++;
			last = rear;
		}
	} 
	return wpl;
}
 
int main(void) 
{
	int N, i, X;
	int high, num, wpl;
	BinTree T = NULL;
	
	printf(" How many nodes you want: ");
	scanf("%d", &N);
	srand((unsigned)time(NULL)); // pesudo-random number
	for( i=0; i<N; i++ ) 
		T = Insert( T, rand()%250 + 1); // generate 1 - 250
		
	printf("\n PreOrder: ");
	PreOrder( T );	
	printf("\n\n InOrder: ");
	InOrder( T );
	printf("\n\n PostOrder: ");
	PostOrder( T );	
	printf("\n Ancestor of X is: ");
	scanf("%d", &X);
	PostOrderAncestor( T, X );
	
	num = TwoBranch(T);
	printf("\n\n TwoBranch number is: %d\n", num);
	
	printf("\n Inverse level: ");
	InverseLevel( T );
	printf("\n LevelOrder: "); //PostOrderHeight( T );
	high = LevelOrderHigh( T );
	printf("   High of tree is: %d\n", high);
	wpl = WplByLevel( T );
	printf(" WPL of Tree: %d\n", wpl);

	printf("\n Leaves of tree: ");
	PreOrderLeaves( T );
	printf("\n");
	
	return 0;
}

