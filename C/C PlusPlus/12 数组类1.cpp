#include <iostream>
#include <string.h>
using namespace std;

class Array //数组类
{
 public:
    Array(){
        name = "";
		count = 0;
		data = NULL;	
    }
    Array(string name, const int *data, int count);    //友元函数 
    friend ostream &operator << (ostream &out, const Array &array);
	void Sort();
    Array operator + (const Array &array);   // 重载+运算符 
    ~Array();
    
 private:
    string name;   //数组名称  m_name
    int count;     //数组大小 
    int *data;     //数组变量
};

Array::Array(string name, const int *data, int count)
{
	this->name = name;
	this->count = count;
	this->data = new int[this->count];
	
	for (int i=0; i<this->count; i++)
    {
		this->data[i] = data[i];
	}
}

ostream & operator << (ostream & out, const Array & array)
{
    out << array.name <<": ";
    
	for (int i=0; i<array.count; i++) 
	{
		cout << array.data[i] << " ";
	}
	
	cout << endl;	
	return out;
}

void Array::Sort()   // 排序 
{
	for (int i=0; i<count-1; i++) 
	{
		for (int j=0; j<count-i-1; j++)
	    {
			if (data[j] > data[j + 1])
		    {
				int tmp;
				tmp = data[j];
				data[j] = data[j + 1];
				data[j + 1] = tmp; 
			}
		}
	}
}

Array Array::operator + (const Array & array) 
{   //两个数组相加 
	Array temp;
	int max = (count > array.count ? count : array.count);
	int min = (count < array.count ? count : array.count);
	temp.name = this->name + '+' + array.name;
	temp.count = max;
	temp.data = new int[temp.count];
	int i = 0;
	
	for (i = 0; i < min; i++) 
	{
		temp.data[i] = data[i] + array.data[i];
	}
	for (; i < count; i++) 
	{
		temp.data[i] = data[i];
	}
	for (; i < array.count; i++) 
	{
		temp.data[i] = array.data[i];
	}
	
	return temp;
}

Array::~Array()
{
    if (data != NULL) 
    {
    	delete []data;
	    count = 0;
    }
}

int main()
{
	int data1[] = {9,8,7,6,5,4,3,2,1,0};
	Array array1("data1",data1,10);
	cout << array1;
	int data2[] = {1,3,5,7,3,8,9,11};
	Array array2("data2",data2,8);
	cout << array2;
	
	cout << array1 + array2;
	array1.Sort();
	cout << "sorted, " << array1;
	array2.Sort();
	cout << "sorted, " << array2;
	
	return 0;
}
