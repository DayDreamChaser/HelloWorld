#include <iostream>
using namespace std;

void Selection_sort(int array[], int n);
void Swap(int *a, int *b);

int main()
{ 
    cout << "Selection sort:";
	const int Num = 10;
	int array[]= {2, 29, 3, 90, 0, 11, 23, -1, 17, 9}; 
	for (int i=0; i<Num; i++)
    {
    	 cout << array[i] << '\t';
    }    
    cout << endl;
    
	Selection_sort(array, Num);

	return 0;
}

void Selection_sort(int array[], int n)
{   
    // 外层循环，实际上对数组进行n-1次找最小数 
    for (int i=0; i<n; i++)
	{
	     int min_index = i;//最小数编号,设从0开始 
		 //未排序中找到最小
		 for (int j=i+1; j<n; j++)
		 {    //每找一次，缩小一个数的范围
		      if (array[j] < array[min_index])
			  {
  			       	min_index = j;//获得更小数的编号 
  			  } 			
 		 }		 
		 //把第i小的数，放到第i位
		 Swap(&array[i], &array[min_index]); 
	}
	
	cout << "Sorted:";	
    for (int i=0; i<n; i++)
    {
    	 cout << array[i] << '\t';
    }     
}

void Swap(int *a, int *b)  // 注意函数声明！！ 
{
	int temp = *a;
	*a = *b;
	*b = temp;
}