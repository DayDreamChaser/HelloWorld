//学生成绩统计管理系统 

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class Student //学生信息类 
{
 public:
   	int no;
    string name;//char name[20];
	string classname;//char classname[20];	
	float math;
	float english;
	float computer;
	float average;  //平均成绩 
};

float getscore(string filename, int stdno); //读取成绩
ostream & operator << (ostream &out, Student &student);//学生信息写文件 

int main()
{   //打开文件 
	ifstream in("info.txt"); //学生信息文件
	ofstream out("student.txt");//学生完整信息文件
	
	if (!in || !out) //判断文件打开是否正确 
	{
	    cout << "文件打开错误！" << endl;
		return 1;	
	} 
	
	out << "学号\t\t姓名\t班级\t高数\t大英\t计算机\t平均" << endl;
	while (in)
	{
		Student student;
		//读文件
		in >> student.no >> student.name >> student.classname;
		if (!in) //读正确时才写文件 
		{
	        break;	
		}
		student.math = getscore("math.txt", student.no);
		student.english = getscore("english.txt", student.no);
		student.computer = getscore("computer.txt", student.no);
		student.average = (student.math + student.english +student.computer) / 3;
		//写文件
		out << student; 
	} 
	//关闭文件
	out.close();
	in.close();
	
	cout << "student.txt建立成功，请查阅！" << endl;
	 
	return 0;
}

float getscore(string filename, int stdno) //读取成绩
{
	int stdno_temp;
	float score;
	ifstream in(filename.c_str());  //打开成绩文件
	if (!in) //判断文件打开是否正确 
	{
	    cout << "文件打开错误" << endl;
		return 0;	
	} 
	bool flag = false;
	while (in)
	{
		in >> stdno_temp >> score;
		if (in)  //读正确时 
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

ostream & operator << (ostream &out, Student &student)//学生信息写文件
{
	out << student.no << '\t' << student.name << '\t' << student.classname;
	out << '\t' << student.math;
	out << '\t' << student.english;
	out << '\t' << student.computer;
	out << '\t' << student.average;
	out << endl;
}
