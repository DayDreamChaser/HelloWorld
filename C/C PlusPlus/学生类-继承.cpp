#include <iostream>
#include <string.h>
using namespace std;
class Student
{
 private:
    int stdnum;   // ѧ��
	char name[20];
	int age; 
	char  classname[20];    // �༶ 
 	char schoolname[20];  
 public:
    Student(int stdnum, char *na, int age, char *cn, char *sc) // ���캯��
    {
    	this->stdnum = stdnum;
    	strcpy(name,na);
    	this->age = age;
    	strcpy(classname,cn);
    	strcpy(schoolname,sc);
    }
	void show()   // ��ʾ��Ϣ 
	{
		cout << stdnum << "\t";
		cout << name << "\t";
		cout << age << "\t";
		cout << classname << "\t";
		cout << schoolname << endl;
	} 
}; 
class CollegeStudent : public Student  //������ ��ѧ�� 
{
 private:
    char classteacher[20];
 public:
    CollegeStudent( int stdnum, char *na, int age, char *cn, char *sc,
    char *ct):Student(stdnum, na, age, cn, sc)
    {
    	strcpy(classteacher,ct);
    }
    void show()                     //��ʾ��Ϣ 
    {
    	Student::show();
    	cout << classteacher << endl;
    }
};
class GraduateStudent : public CollegeStudent  // ˶ʿ 
{
 private:
    char tutor[20];         //��ʦ  
    char projectname[50];   //���� 
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
class DoctorStudent : public GraduatedStudent  // ��ʿ�� 
{
 private:
    char researchname[50];    //�о���Ŀ
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
	int stdnum;   // ѧ��
	char name[20];
	int age; 
	char  classname[20];    // �༶ 
 	char schoolname[20];  
 	cout << "Please input the student data:" << endl;
 	cin >> stdnum >> name >> age >> classname >> schoolname;
	Student student1() 
	return 0;
}