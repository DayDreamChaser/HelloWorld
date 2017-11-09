#include <iostream>
#include <fstream>
using namespace std;
class Student
{
    char Name[10];
	char className[10];	
    char thesex;
    int theage;
 public:
    Student(){}
    Student(char *Name, char *theClass, char sex, int age);
    void Showme();
};

Student::Student(char *Name, char *Class, char sex, int age)
{
	strcpy(this->Name, Name);
	strcpy(className, Class);
	thesex = sex;
	theage = age;
}

void Student::Showme()
{
	cout << Name << '\t' << className << '\t' << thesex << '\t' 
	<< theage << endl; 
}

int main()
{
    Student stu;  //build temporary objective
    
    ifstream file("file.dat", ios::binary); // input stream(read into memory) 
    if(!file)
    {
    	cout << "failed to open the file!" << endl;
    	return 1;
    }
    
    file.seekg(0, ios::end);  //��λ�ļ�ָ�뵽�ļ�ĩβ
	int len = file.tellg();   //�õ��ļ�ָ��λ�� or tellp()
	cout << "len=" <<len << " size=" << sizeof(stu) << endl; 
    // ���ļ� 
	for (int k=len/sizeof(stu)-1; k>=0; k--)
	{
		file.seekg(k*sizeof(stu));
		file.read((char*)&stu, sizeof(stu));
		stu.Showme();
	}
	file.close();
    
	return 0;
}
