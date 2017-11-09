#include <iostream>
#include <string.h>
using namespace std;

class Array //������
{
 public:
    Array(){
        name = "";
		count = 0;
		data = NULL;	
    }
    Array(string name, const int *data, int count);    //��Ԫ���� 
    friend ostream &operator << (ostream &out, const Array &array);
	void Sort();
    Array operator + (const Array &array);   // ����+����� 
    ~Array();
    
 private:
    string name;   //��������  m_name
    int count;     //�����С 
    int *data;     //�������
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

void Array::Sort()   // ���� 
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
{   //����������� 
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
