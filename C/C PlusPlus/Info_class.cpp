#include <iostream>
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
    const int COUNT = 5;
	int i = 0, j = 0;
	int id;        // 存储信息的中间变量 
	char name[20];
	int programming;
	int network;
	int database;
	Info student[COUNT], tmp;
	
	cout << "请输入学生成绩的信息" << endl;
	cout << "学号 姓名 程序设计 计算机网络 数据库" << endl;
	for ( i = 0; i < COUNT; i++) {
		cin >> id >> name >> programming >> network >> database;
		student[i].Set_info(id, name, programming, network, database);
	}	
	cout << "学号 姓名 程序设计 计算机网络 数据库 总分" << endl;
	for( i = 0; i < COUNT; i++) {
		student[i].Show();
	} 
	
	return 0; 
}
