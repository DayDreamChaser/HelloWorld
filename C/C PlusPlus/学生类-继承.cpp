#include <iostream>
#include <string.h>
using namespace std;
class Student
{
 private:
    int stdnum;   // 学号
	char name[20];
	int age; 
	char  classname[20];    // 班级 
 	char schoolname[20];  
 public:
    Student(int stdnum, char *na, int age, char *cn, char *sc) // 构造函数
    {
    	this->stdnum = stdnum;
    	strcpy(name,na);
    	this->age = age;
    	strcpy(classname,cn);
    	strcpy(schoolname,sc);
    }
	void show()   // 显示信息 
	{
		cout << stdnum << "\t";
		cout << name << "\t";
		cout << age << "\t";
		cout << classname << "\t";
		cout << schoolname << endl;
	} 
}; 
class CollegeStudent : public Student  //派生类 大学生 
{
 private:
    char classteacher[20];
 public:
    CollegeStudent( int stdnum, char *na, int age, char *cn, char *sc,
    char *ct):Student(stdnum, na, age, cn, sc)
    {
    	strcpy(classteacher,ct);
    }
    void show()                     //显示信息 
    {
    	Student::show();
    	cout << classteacher << endl;
    }
};
class GraduateStudent : public CollegeStudent  // 硕士 
{
 private:
    char tutor[20];         //导师  
    char projectname[50];   //课题 
 public:
    GraduateStudent(int stdnum, char *na, int age, char *cn, char *sc,
    char *ct, char *tu, char *pn):CollegeStudent(stdnum, na, age, cn, sc, ct)
    {
    	strcpy(tutor,tu);
    	strcpy(projectname,pn); 
    }
    void show()
    {
    	CollegeStudent::show();
    	cout << tutor << "\t";
    	cout << projectname << endl;
    }
};
class DoctorStudent : public GraduatedStudent  // 博士类 
{
 private:
    char researchname[50];    //研究项目
 public:
    DoctorStudent(int stdnum, char *na, int age, char *cn, char *sc, char *ct, char *tu,
    char *pn, char *rn):GraduateStudent(stdnum, na, age, cn, sc, ct, tu, pn)
    {
 	    strcpy(researchname,rn);	
 	}
 	void show()
    {
    	GraduateStudent::show();
    	cout << researchname << endl;
    }
};
int main()
{
	int stdnum;   // 学号
	char name[20];
	int age; 
	char  classname[20];    // 班级 
 	char schoolname[20];  
 	cout << "Please input the student data:" << endl;
 	cin >> stdnum >> name >> age >> classname >> schoolname;
	Student student1() 
	return 0;
}