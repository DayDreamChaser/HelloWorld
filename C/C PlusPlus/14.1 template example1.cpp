#include <iostream>
using namespace std;
template <class T>  // 模板
 
T min(T a[], int n)
{
	int i;
	T minv = a[0];
	for (i = 1; i < n; i++)  // n-1次 
    {   
	    // n为数组长 
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
   	
   	cout << "a数组的最小值为:" << min(a, 9) << endl;
   	cout << "b数组的最小值为:" << min(b, 5) << endl;
   	
	return 0;
}