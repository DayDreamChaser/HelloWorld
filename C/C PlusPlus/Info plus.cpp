#include <iostream>
#include <cstring>
using namespace std;

class Info   // 定义信息类 
{
	  int Id;
	  char Name[20];
	  int Programming;
	  int Network;
	  int Datebase;
  	  int Total;
  public:
      void Set_info(int id,char *name,int pro,int net,int data);
      int Get_Pro(){ return Programming; }
      int Get_net(){ return Network; }
      int Get_Dat(){ return Datebase; }
      int Get_Tol(){ return Total; }
      void Show();
}; 
void Info::Set_info(int id,char *name,int pro,int net,int data)
{
	Id = id;
	strcpy(Name,name);
	Programming = pro;
	Network = net;
	Datebase = data;
	Total = pro + net + data;
}
void Info::Show()
{
	cout << Id << "\t";
	cout << Name << "\t";
	cout << Programming << "\t";
    cout << Network << "\t";
    cout << Datebase << "\t";
    cout << Total << endl;
}
int main()
{
    const int MAX_COUNT = 100;
    int count;
	int i = 0, j = 0;
	int id;        // 存储信息的中间变量 
	char name[20];
	int programming;
	int network;
	int database;
	Info student[MAX_COUNT], tmp;
	
	cout << "请输入学生人数：";
	cin >> count;
	while (count > MAX_COUNT) {
		cout << "学生人数不能超过" << MAX_COUNT << "人，请重新输入：";
		cin >> count; 
	} 
	
	cout << "请输入学生成绩的信息" << endl;
	cout << "学号 姓名 程序设计 计算机网络 数据库" << endl;
	for ( i = 0; i < count; i++) {
		cin >> id >> name >> programming >> network >> database;
		student[i].Set_info(id, name, programming, network, database);
	}	
	
	cout << "按总分高低排名如下：" << endl;
	for (i = 0; count > i; i = i + 1) {
	    for (j = count - 1; j > i; j = j -1) {
    		if (student[j].Get_Tol() > student[j-1].Get_Tol()) {
		    	tmp = student[j];
		    	student[j] = student[j-1];
		    	student[j-1] = tmp;
		    }
    	}	
	} 
	
	cout << "学号 姓名 程序设计 计算机网络 数据库 总分" << endl;
	for( i = 0; i < count; i++) {
		student[i].Show();
	} 
	cout << "每门课程成绩都大于85分的学生名单：" << endl;
	cout << "学号 姓名 程序设计 计算机网络 数据库 总分" << endl;
	for( i = 0; i < count; i++) {
		if (student[i].Get_Pro() > 85 && student[i].Get_net() > 85 && student[i].Get_Dat() > 85)
		       student[i].Show();
	}
	
	return 0; 
}
