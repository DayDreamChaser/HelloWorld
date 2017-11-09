#include <stdio.h>
#include <stdlib.h>

typedef struct Node *PtrtoNode; 
typedef PtrtoNode List;
typedef PtrtoNode Position;

struct Node
{
	int Element;
    Position Next;	
};

List ReverseList1(List L)
{
    // node of list less than 2
	if (L == NULL || L->Next == NULL)
	{
        return List;
	}
	Position head = L->Next;
	Position p;
	Position q;
	Position r;
	p = head;
	q = head->Next;
	// head->Next to end of the list
	head->Next = NULL;
	//if next node of p is exist
	while (q)
	{
		//reverse the list by three node turn by turn
		r = q->Next;// r reserve the next node 
		q->Next = p;
		p = q;
		q = r;
	}
	// q must point to the NULL at the end
	head = p;

    return head;	    
} 