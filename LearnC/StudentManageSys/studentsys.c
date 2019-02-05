/* Student Manage system, ver:0.101 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "studentsys.h"

/*  1->Add  2->Find   3->Del 4->Brows  5->Store*/
/*  6->Read 7->DelAll 8->Cls 9->Quit  */

int main(void)
{
	List L; /* Head Node */
	L = (List)malloc(sizeof( struct ListNode ));
	L->next = NULL;
	
    int i, flag;
	int option; /* init info */
	int Id = 0; 
	char name[MAX]= "   ";
	Grade grades;
	printf("                       Starting                       \n");
	printf("          Student Management system, ver:0.101 \n");
 	printf("******************************************************\n");
  	printf("                    学生管理系统\n");
 	printf("$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$\n");
	selectInfo();
	while ( 1 ) {
	    scanf("%d",&option);
	    switch ( option ) {
		    case 1: printf("Please in put id, name, six grades:\n");
					scanf("%d %s", &Id, name);
					scanf("%d %d %d %d %d %d", &grades.Chinese, &grades.Math,
                         &grades.English, &grades.Programming,&grades.Physic, 
					     &grades.Geology );
					if ( AddStd( L, Id, name, grades ) == 1 ) {
						printf("Added student.\n");
					} else {
						printf("Sorry, can't add student\n");
					}
			        break;
			        
		    case 2:	printf("select method: 0 by Id, 1 by name\n");
		    	    scanf("%d", &flag);
		    	    printf("Please in put id, name\n");
		    	    scanf("%d %s", &Id, name); /* notice & */
					if ( FindStd( L, flag, Id, name ) == 1 ) {
						printf("found student\n");
					} else {
						printf("sorry, can't found student\n");
					}
			        break;
			        
		    case 3: printf("Which id you want ot del: ");
		    		scanf("%d", &Id);
					if ( DeleteStd( L, Id ) ) {
						printf("Successfully Delete!\n");
					} else {
						printf(" Not found!\n");
					}
					break;		
								
		    case 4: PrintAll( L ); 
					break;	
					
		    case 5: if ( StoreInfo( L ) ) {
	   	 				printf("Write successfulluy!\n");
    		        } else {
        		    	printf("Failed to read!\n");
        		    } 
					break;	
					
		    case 6: L = ReadInfo( ); 
					break;				
		    case 7: DestoryInfo( L ); 
					break;
			case 8: system("cls");
					selectInfo();
					break;
			case 9: exit(0); 
					break;
		    default:printf("error!请重新输入!\n");
	    }
    }
	return 0;	
}

int AddStd( List L, int Id, char *name, Grade grades )
{
	List Head = L;
	List Cur;
	if( IsRepeat( L, Id)==1 ) {
		printf(" Id repeat!!!\n");
		return 0;
	}
	Cur = (List)malloc(sizeof( struct ListNode ));
	if ( Cur != NULL ) {
		Cur->info.Id = Id;
		strcpy( Cur->info.name, name);
		Cur->info.grades.Chinese = grades.Chinese;
		Cur->info.grades.Math = grades.Math;
		Cur->info.grades.English = grades.English;
		Cur->info.grades.Programming = grades.Programming;
		Cur->info.grades.Physic = grades.Physic;
		Cur->info.grades.Geology = grades.Geology;					
		
		Cur->next = Head->next;
		Head->next = Cur;
		
		return 1;
	} else {
		printf("Failed to malloc!\n");	
		return 0;
	}
}

int FindStd( List L, int flag, int Id , char *name )
{ 
	List Cur = L->next;
	while ( Cur != NULL ) {
		if( flag == 1 ) {
			if ( strcmp( name, Cur->info.name ) == 0 ) {
				PrintInfo(Cur);
				break;
			}
		} else if ( flag == 0 ) {
			if ( Cur->info.Id == Id ) {
				PrintInfo(Cur);
				break;
			}
		}
		Cur = Cur->next;	
	}
	if ( Cur == NULL ){
		return 0;
	} else {
		return 1;
	} 
}

int DeleteStd( List L, int Id )
{
	List Pre = L;
	List Cur = Pre->next;
	
	if( L->next	== NULL ) {
		printf("Empty Node!\n");
		return 0;
	} else {
		while ( Cur != NULL ) {
			if ( Cur->info.Id == Id ) {  
				 /* 找到对应编号 */
				Pre->next = Cur->next;
				free(Cur);
				break;
			} 
			Pre = Cur;
			Cur = Cur->next; 
		}
		if ( Cur == NULL ) {
			return 0; 
		} else {
			return 1;
		}
	} /* 1 else */	
}

void PrintInfo( List L )
{
	List Cur = L;
	if ( Cur != NULL ) {
		printf("ID: %d  ", Cur->info.Id);
		printf("Name: %s\n", Cur->info.name);
		printf("Chinese    :%d   ", Cur->info.grades.Chinese);
		printf("Math       :%d   ", Cur->info.grades.Math);
		printf("English    :%d\n", Cur->info.grades.English);
		printf("Programming:%d   ", Cur->info.grades.Programming);
		printf("Physic     :%d   ", Cur->info.grades.Physic);
		printf("Geology    :%d\n", Cur->info.grades.Geology);
	} 
}

void PrintAll( List L )
{
	List Cur = L->next;
	int i = 0;
	while ( Cur != NULL ) {
		i++;
		printf("%d-->Student ", i);
		PrintInfo( Cur );	
		Cur = Cur->next;
	}
}

int StoreInfo( List L )
{
	FILE *fp = fopen("student.data", "w");
	List H = L->next;
	const int size = 1;
	int ret = -1; /* default */
	
	if ( fp == NULL ) {
		printf("Failed to open file!\n");
	} else if( H == NULL ) {
		printf("Empty student info!\n");
	} else {		
		/* write list into fp */
		while ( H != NULL ) {
			ret = fwrite( H, sizeof(H->info), size, fp );
			H = H->next;	
		}
		ret = 1;
	}
	fclose( fp );
	return ret;
}

List ReadInfo( )
{
	int i = 0; /* count */
	List L, P, tmp;
	P = L = (List)malloc( sizeof(struct ListNode) );
	FILE *fp = fopen("student.data", "r");
	
	if ( fp == NULL ) {
		printf("Failed to read file!\n");
		return NULL;
	} 
    /* 假如文件为空,检查文件结束符 feof在到达文件流尾返回非零值 */
 	if ( feof(fp) != 0 ) {
        tmp = (List)malloc( sizeof(struct ListNode) );
        fread( tmp, sizeof(tmp->info), 1, fp);
        if( feof(fp) ) {
            printf("读取失败!文件为空!\n");
            free(tmp);
        }
		return(NULL);
    }

	while ( feof(fp) == 0 ) {
        tmp = (List)malloc( sizeof(struct ListNode) ); 
        fread( tmp, sizeof(tmp->info), 1, fp);
        printf("正在读取第%d个数据\n", ++i);
		if ( feof(fp) != 0 ) {
			/* reach end */
            free(tmp); break;
        }
        P->next = tmp;
        P = tmp;
		P->next = NULL;
    }
    fclose(fp);
    printf("Read successfulluy!\n");
    return L;
}

void DestoryInfo( List L )
{
	List Cur, Tmp;
	Cur = L->next;
	while ( Cur	!= NULL ) {
		Tmp = Cur->next;
		free( Cur );
		Cur = Tmp;
	}
	L->next = NULL;
 	printf("删除所有学生信息成功!\n");
}

int IsRepeat( List L, int Id )
{
	List Cur = L->next;
	int flag = 0;
	while ( Cur != NULL ) {
		if ( Cur->info.Id == Id )
			flag = 1;
		Cur = Cur->next;
	}
	return flag;
}

void selectInfo()
{
	printf("Stumansys 请选择：\n");
	printf("(1)---增加学生 (2)---查询学生 (3)---删除学生 \n");
	printf("(4)---查看全部 (5)---记录存盘 (6)---读取信息\n");
	printf("(7)---删除所有 (8)---清除屏幕 (9)---退出系统\n");	
}
