//ѧ���ɼ�ͳ�ƹ���ϵͳ 

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class Student //ѧ����Ϣ�� 
{
 public:
   	int no;
    string name;//char name[20];
	string classname;//char classname[20];	
	float math;
	float english;
	float computer;
	float average;  //ƽ���ɼ� 
};

float getscore(string filename, int stdno); //��ȡ�ɼ�
ostream & operator << (ostream &out, Student &student);//ѧ����Ϣд�ļ� 

int main()
{   //���ļ� 
	ifstream in("info.txt"); //ѧ����Ϣ�ļ�
	ofstream out("student.txt");//ѧ��������Ϣ�ļ�
	
	if (!in || !out) //�ж��ļ����Ƿ���ȷ 
	{
	    cout << "�ļ��򿪴���" << endl;
		return 1;	
	} 
	
	out << "ѧ��\t\t����\t�༶\t����\t��Ӣ\t�����\tƽ��" << endl;
	while (in)
	{
		Student student;
		//���ļ�
		in >> student.no >> student.name >> student.classname;
		if (!in) //����ȷʱ��д�ļ� 
		{
	        break;	
		}
		student.math = getscore("math.txt", student.no);
		student.english = getscore("english.txt", student.no);
		student.computer = getscore("computer.txt", student.no);
		student.average = (student.math + student.english +student.computer) / 3;
		//д�ļ�
		out << student; 
	} 
	//�ر��ļ�
	out.close();
	in.close();
	
	cout << "student.txt�����ɹ�������ģ�" << endl;
	 
	return 0;
}

float getscore(string filename, int stdno) //��ȡ�ɼ�
{
	int stdno_temp;
	float score;
	ifstream in(filename.c_str());  //�򿪳ɼ��ļ�
	if (!in) //�ж��ļ����Ƿ���ȷ 
	{
	    cout << "�ļ��򿪴���" << endl;
		return 0;	
	} 
	bool flag = false;
	while (in)
	{
		in >> stdno_temp >> score;
		if (in)  //����ȷʱ 
		{
		    if (stdno_temp == stdno)
			{
				flag = true;
				break;
			}	
		}
	}
	if (!flag)
	{
		score = 0;
	}
	in.close();
	return score;
} 

ostream & operator << (ostream &out, Student &student)//ѧ����Ϣд�ļ�
{
	out << student.no << '\t' << student.name << '\t' << student.classname;
	out << '\t' << student.math;
	out << '\t' << student.english;
	out << '\t' << student.computer;
	out << '\t' << student.average;
	out << endl;
}
