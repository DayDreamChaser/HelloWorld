#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
int main()
{
   vector <string> v;
   v.push_back("food");
   v.push_back("candy");
   v.push_back("apple");
   
   sort(v.begin(), v.end());
   vector <string>::iterator it; //迭代器 
   for (it = v.begin(); it!=v.end(); it++)
   {
        cout << *it << " ";	
   }
   
   return 0;
    /*vector <int> v1;
    for (int i=0; i<10; i++)
	{
		v1.push_back(i);
	}
    
    vector  <int>::iterator it;
	for (it=v1.begin(); it<v1.end(); it++)
	{
		if (*it % 2 == 0)
		{
		    cout << *it << ' ';
		}
	}
	
	return 0;*/
}

 
void Algorithm()
{
	int A[] = {5, 35, 15, 20, 25};
	int B[] = {50, 40, 30, 20, 19};
	vector <int> v(10);//容器 
	vector <int>::iterator it;
	sort(A, A + 5);
	sort(B, B +5); //先排序，再合并
	merge(A, A + 5, B, B + 5, v.begin());
 //算法   //迭代器 
	for (it = v.begin(); it!=v.end(); it++)
   {
        cout << *it << " ";	
   } 
}