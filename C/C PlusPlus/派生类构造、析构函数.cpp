#include <iostream>
#include <string.h>
using namespace std;
class Person
{
	char Name[10];   // name
	int Age;
public:
    Person(char *name, int age)
    {
    	strcpy(Name,name);
    	Age = age;
    	cout << "constructor of Person" << endl;
    }
    void Show_Person();
    ~Person() {  cout << "deconstrutor of Person"; }
};
void Person::Show_Person()
{
	cout << Name << "\t" << Age << endl;
}
class Employee:public Person
{
    char Dept[20];
	Person Leader;
public:
    // ���캯��  �����಻�ܼ̳л��๹�������                        // ���๹�캯�� 
    Employee(char *name, int age, char *dept, char *name1, int age1):Person(name,age),Leader(name1, age1) 
	{
		strcpy(Dept,dept);
		cout << "constructor of Employee" << endl;
	}	
	void Show_Employee();
	~Employee(){ cout << "deconstructor of Employee" << endl;}
}; 
void Employee::Show_Employee()
{
	Show_Person();
	cout << Dept << endl;
	Leader.Show_Person();
}
int main()
{
	Employee emp("�Ź���", 40, "���´�", "��ľ��", 35);
	emp.Show_Employee();
	cout << endl;
	return 0;
}