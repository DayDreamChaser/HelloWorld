#include <iostream>
using namespace std;
template <class T>  // ģ��
 
T min(T a[], int n)
{
	int i;
	T minv = a[0];
	for (i = 1; i < n; i++)  // n-1�� 
    {   
	    // nΪ���鳤 
    	if (minv > a[i])
    	{
	        minv = a[i];    	
	    }   
    }
	
	return minv;
}

int main()
{
    int a[] = {8, 10, 0, 1, 7, 4, 9, 6, 11};
	double b[] = {1.2, -3.4, 6.9, 7.2, 8.9};	
   	
   	cout << "a�������СֵΪ:" << min(a, 9) << endl;
   	cout << "b�������СֵΪ:" << min(b, 5) << endl;
   	
	return 0;
}