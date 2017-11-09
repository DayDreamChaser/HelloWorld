#include <stdio.h>
int main(void)
{
  int numbers[10];
  int count=10,i;
  long sum=0l;
  float average=0.0f;

  printf("\nEnter the 10 numbers:\n");
  for(int i=0;i<count;i++)
  {
    printf("%-2d> ",i+1);
	scanf("%d",&numbers[i]);
	sum+=numbers[i];
  }
  average=(float)sum/count;
  for(i=0;i<count;i++)
    printf("\nGrade is %d to %d",i+1,numbers[i]);
  printf("\nAverager of the ten numbers enters is %.5f\n",average);
  return 0;
}