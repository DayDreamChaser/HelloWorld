#include <iostream>
#include <string.h>
using namespace std;
class Person
{
 protected:
    char Name[10];
    int Age;
    char Sex;
 public:
    void Register(char *name, int age, char sex)
    {
        strcpy(Name,name);
        Age = age;
        Sex = (sex == 'm' ? 'm' : 'f');	
    }	
    void ShowMe()
    {
  	    cout << Name << "\t" << Age << "\n" << Sex << endl;
    }
};
class Employee:public Person    // 雇员类定义 
{
    char Dept[20];    
    float Salary;
 public:
    Employee()   // 构造函数 
    {
        EmployeeRegister("XXX", 0, 'm', "XXX", 0);	
    }
    void EmployeeRegister(char *name, int age, char sex, char *dept, float salary);
    void ShowEmp();
};
void Employee::EmployeeRegister(char *name, int age, char sex, char *dept, float salary)
{
	Register(name, age, sex);
	strcpy(Dept,dept);
	Salary = salary;
}
void Employee::ShowEmp()
{
	cout << Name << "\t" << Age << "\t" << Sex << endl;
	cout << Dept << "\t" << Salary << endl;
}
int main()
{
	Employee emp;
	emp.EmployeeRegister("我接待", 21, 'm', "asd", 12343.5);
	emp.ShowEmp();
	cout << endl;
	emp.ShowMe();
	cout << endl;
	return 0;
}