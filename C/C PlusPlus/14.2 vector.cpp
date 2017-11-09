#include <iostream>
#include <vector>
using namespace std;
int main()
{
    vector <int> v1;
	v1.push_back(1);
	v1.push_back(2);
	
	//迭代器 
	v1.insert(v1.begin(), 0);//头部插入
	v1.insert(v1.end(), 4);  //尾部插入 
	v1.insert(v1.end()-1, 3);//倒数第二位置	 
    v1[4] = 10;  //v1[5] = 6;越界错误
	for (int i=0; i<v1.size(); i++)
	{
		cout << v1[i] << ' ';
	} 
	cout << endl;
	
	v1.pop_back();   //删除尾部 10 
	v1.erase(v1.begin()); //删除头 0 
	v1.erase(v1.begin(), v1.end()); //全删
	cout << "全删后：";  // v1.clear();
	for (int i=0; i<v1.size(); i++)
	{
		cout << v1[i] << ' ';
	}  
	 
	return 0;
}