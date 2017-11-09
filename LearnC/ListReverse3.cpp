#include <iostream>

using namespace std;
typedef struct ActList* List;

struct ActList
{
    char ActName[20];
	char Director[20];
	int Mtime;
	List Next;	
};

List CreateList(void)
{
	//Initilize of CreateList
	List p = NULL;
	List q = NULL;
	List head = NULL:
	
	int time;
	cout << "Please input the  length of the movie:" << endl;
	cin >> time;
	
	while (time != 0)
	{
		// such as TreeNode* node = new Treenode 
		p = new ActList;
		p->Mtime = time;
		cout << "Please input the title of the movie:" << endl;
		cin >> p->ActName;
		cout << "Please input the director or executive producer name:" << endl;
		cin >> p->Director;
		
		if (head == NULL)
		{
			head = p;
		}
		else
		{
			q->Next = p;
		}
		q = p;
		cout<<"Please input the length of the movie."<<endl;  
        cin>>Time;  
      
        if (head!=NULL)
		{
			 q->next=NULL;  
             return head;
	    }	
    }
}

void DisplayList(List head)
{
	cout << "show up of the list programs!" << endl;
	while (head!=NULL)
	{ 
        cout << head->Mtime << "\t";
		cout << head->ActName << "\t";
		cout << head->Director << "\t" << endl;
	    head = head->Next;
    }	  	
}

List ReverseList1(List head)  
{     
    if ( head==NULL || head->Next==NULL)
	{
		return head;
	}      
    List p;  
    List q;  
    List r;  
    p = head;    
    q = head->Next;  
    head->Next = NULL;  
    while (q)
	{  
        r = q->Next; //  
        q->Next = p;      
        p = q; //  
        q = r; //  
    }  
    head = p;  
   
    return head;      
}  

List ReverseList2(List head)  
{  
    List p;  
    List q;  
    p = head->Next;  
    
    while (p->Next!=NULL)
	{  
        q = p->Next;
		p->Next = q->Next;
		q->Next = p;
		head->Next = q; 
    }  
  
    p->Next = head;//相当于成环  
    head = p->Next->Next;//新head变为原head的next  
    p->Next->Next = NULL;//断掉环  
    
    return head;    
}  

int main(int argc, char* argv[])  
{  
//  DisplayList(Create());  
//  DisplayList(ReverseList2(Create()));  
    DisplayList( ReverseList2( CreateList() ) ); 
	 
    return 0;  
}  