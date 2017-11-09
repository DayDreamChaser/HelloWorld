#include <stdio.h>
#include <stdbool.h>
#include <sys/types.h>
#include <windows.h>

void EntrySpace(int num);  
void EnterLines(int num1);

int main()
{ 
    int i = 0;
    EntrySpace(28);
  	printf("Press any key to start");
  	getchar();
  	system("cls");
  	
  	int levels = 0;
    int score = 0;
    int lines = 0;
    int number = 0;
    int rol = 0;    
    loop:while (true)
  	{	
	    system("cls"); 
  	    EntrySpace(28);
     	printf("level:%d", levels);

  	    EntrySpace(10);
     	printf(" scores:%d\n", score);
    
        EntrySpace(28);
        printf("1----Pause");
        EntrySpace(8);
        printf("0----Exit\n");
        for (i=0; i<80; i++)
        {
        	printf("-");
        }  
        EnterLines(1);
        
         
		number = rand() % 26;  //随机数 
		rol = rand() % 80;
		
	    while (true)
		{
			lines++;
			
			EntrySpace(rol);
            if (lines > 20)   
            {
             	lines = 0;
             	score -= 10;
             	
             	if (score < -50)   // 惩罚措施
             	{
             		system("cls");
	                EnterLines(10);
					EntrySpace(28);
					printf("Sorry,you failed!\n"); 
					printf("If you want play again,please input 6\n ");
					printf("or you want exit ,you just need input 0\n");
					
					char choice = getchar();  //选择继续或退出 
					if (choice == '6')	{
						score = 0;
						goto loop;
					} 
					if (choice	== '0') {
							exit(0);  // 当前退出	
					}		
                }
                
             	break;
            }
            printf("%c", 'a' + number);
            
	    	Sleep(60);
            printf("\b \n");
			
			if (kbhit())
			{
				char c = getch();
				if (c == '1')
				{
				     Sleep(50);
                     system("pause");
					 goto loop;
				}  
				if (c == '0')
				{
					 exit(0);
				}	            
                if (c == 'a' + number)
                {
                	 score += 10;
					 break;
                }           
			}		
		}
    }
 	     
	return 0;
}

void EntrySpace(int num)
{
	int i = 0;
	for (i = 0; i < num; i++)
    {
    	printf(" ");
    }
}

void EnterLines(int num1)
{
	int j;
	for (j = 0; j < num1; j++)
    {
       	printf("\r\n");
    }
}