#include <iostream>
#include <vector>
using namespace std;
int main()
{
    vector <int> v1;
	v1.push_back(1);
	v1.push_back(2);
	
	//������ 
	v1.insert(v1.begin(), 0);//ͷ������
	v1.insert(v1.end(), 4);  //β������ 
	v1.insert(v1.end()-1, 3);//�����ڶ�λ��	 
    v1[4] = 10;  //v1[5] = 6;Խ�����
	for (int i=0; i<v1.size(); i++)
	{
		cout << v1[i] << ' ';
	} 
	cout << endl;
	
	v1.pop_back();   //ɾ��β�� 10 
	v1.erase(v1.begin()); //ɾ��ͷ 0 
	v1.erase(v1.begin(), v1.end()); //ȫɾ
	cout << "ȫɾ��";  // v1.clear();
	for (int i=0; i<v1.size(); i++)
	{
		cout << v1[i] << ' ';
	}  
	 
	return 0;
}