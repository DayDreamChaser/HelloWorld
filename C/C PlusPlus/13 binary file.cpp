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
	Student stu[3] = {
	   Student("��С��", "����13", 'm', 27),
	   Student("�����", "רӢ15", 'f', 21),
	   Student("��˼��", "�ƾ�12", 'f', 19),  };
    
	//open the file by objective
    ofstream file1("file.dat", ios::binary);  
    if (!file1)
    {
    	cout << "failed to open this file!" << endl;
    	return 1;
    }    
	//wirte the file   (char*) force to transform the type
    for (int i = 0; i < 3; i++)
    {
    	file1.write((char*)&stu[i], sizeof(stu[i]));
    }
    file1.close();
    
	//  read the file and show it 
    Student stu2;  //build temporary objective
    
    ifstream file2("file.dat", ios::binary);
    if(!file2)
    {
    	cout << "failed to open the file!" << endl;
    	return 1;
    }
    
    while(file2)
    {
    	file2.read((char*)&stu2, sizeof(stu2));
    	if(file2)
    	{
	    	stu2.Showme();
	    }
    }
    file2.close();
    
	return 0;
}