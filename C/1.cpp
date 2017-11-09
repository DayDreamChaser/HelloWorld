/* Program 5.6 Know your hat size - if you dare...*/
#include <stdio.h>
#include <stdbool.h>
int main(void)
{
  /* The size array stores hat zizes from 6 1/2 to 7 7/8 */
  /* Each row defines one character of size value so*/
  /* a size is selected by using the same index for each */
  /* the three rows. e.g. Index 2 selects 6 3/4 .*/
  char size[3] [12] ={     /* Hat sizes as characters */
    {'6', '6', '6', '6', '7', '7', '7', '7', '7', '7', '7', '7'},
    {'1', '5', '3', '7', ' ', '1', '1', '3', '1', '5', '3', '7'},
    {'2', '8', '4', '8', ' ', '8', '4', '8', '2', '8', '4', '8'}
    };  
  int headsize[12] =       /* Values in 1/8 inches */
    {164,166,169,172,175,178,181,184,188,191,194,197};
    
  float cranium = 0.0;     /* Head circumference in decimal inches */
  int your_head = 0;        /* Headsize in whole eighths */
  int i = 0;               /* Loop counter */
  bool hat_found = false;  /* Indicates when a hat is found to fit */
  
  /* Get the circumference of the head*/
  printf("\nEnter the circumference of your head above you eyebrows "
  "in inches as a decimal value: ");
  scanf(" %f",&cranium);
  
  /* Convert to whole eighths of an inch */
  your_head = (int)(8.0*cranium);
  
  /* Search for a hat size */
  /* A fit is when your_head is qreater that one headsize element */
  /* and less tham or equal to the next. The size is the second */
  /* headsize value*/
  for (i = 1 ;i < 12 ; i++)
    /* Find head size in the headsize array */
    if(your_head > headsize[i-1] && your_head <= headsize[i])
    {
   	  hat_found = true;
   	  break;
    }

    if(your_head == headsize[0]) /* Check for min size fit */
    {
      i = 0;
	  hat_found = true; 	
    }
    
    if(hat_found) 
      printf("\nYour hat size is %c %c%c%c\n",
	     size[0][i], size[1][i],(size[1][i]==' ') ? ' ': '/',size[2][i]);
   /* If no hat was found, the head is too small or to large */
    else
    {
      if(your_head < headsize[0])  /* check for too small */	
        printf("\nYou are the proverbial pinhead. No hat for"
		     " you I'm afraid.\n");
      else
        printf("\nYou, in technical parlance, are a fathhead."
             " No hat for you,I'm afraid.\n");
    }
  return 0;  
} 
/*#include <stdio.h>
int f(int x);
int g(int x);

int main(void)
{
	int r,n;
	printf("please input the number(n):\n");
	scanf("%d",&n);
	r = f(n);
	printf("the result of f(%d) is %d \n", n, r);
	
	return 0;
}            

int f(int x)
{
	int y;
	if(x!=1){
		y = g(x)*g(x-1);
	} else {
		y =1;
	}
	
	return y;
}            

int g(int x)
{
	int z;
	if(x>2) {
		z = f(x-2);
	} else {
		z = 2;
	}
        
     return z;   
} 
*/                                                                                                                                                                                                             ,                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                        