/*  student management system by list  */
#ifndef _StudentSys_H
#define _StudentSys_H

#define MAX 25
#define GRADE_NUM 6
#define LARGE 200
typedef struct _Grade Grade;;
typedef struct StdNode Std;;
typedef struct ListNode *List;

/*  1->Add  2->Find  3->Del 4->Brows */
/*  5->Store 6->Read 7->Quit  */
int AddStd( List L, int Id, char *name, Grade grades );
/* flag:0 by id, 1 by name */
int FindStd(List L, int flag, int Id ,char *name); 
int DeleteStd( List L, int Id );
void PrintInfo( List L );
void PrintAll( List L );
int StoreInfo( List L );
List ReadInfo( );
void DestoryInfo( List L ); 
int IsRepeat( List L, int Id );
void selectInfo();

/* 6 courses */
struct _Grade{
	int Chinese;
	int Math;
	int English;
	int Programming;
	int Physic;
	int Geology; 
};

/*  student info */	
struct StdNode {
	int Id;        /* student id */
	char name[MAX];/* student name */
	Grade grades;  /* student grades */
};

struct ListNode {
	Std info;
	List next;
};

#endif
