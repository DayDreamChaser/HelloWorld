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
    // ���ѭ����ʵ���϶��������n-1������С�� 
    for (int i=0; i<n; i++)
	{
	     int min_index = i;//��С�����,���0��ʼ 
		 //δ�������ҵ���С
		 for (int j=i+1; j<n; j++)
		 {    //ÿ��һ�Σ���Сһ�����ķ�Χ
		      if (array[j] < array[min_index])
			  {
  			       	min_index = j;//��ø�С���ı�� 
  			  } 			
 		 }		 
		 //�ѵ�iС�������ŵ���iλ
		 Swap(&array[i], &array[min_index]); 
	}
	
	cout << "Sorted:";	
    for (int i=0; i<n; i++)
    {
    	 cout << array[i] << '\t';
    }     
}

void Swap(int *a, int *b)  // ע�⺯���������� 
{
	int temp = *a;
	*a = *b;
	*b = temp;
}