#include <iostream>
using namespace std;

class Info   // ������Ϣ�� 
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
	int id;        // �洢��Ϣ���м���� 
	char name[20];
	int programming;
	int network;
	int database;
	Info student[COUNT], tmp;
	
	cout << "������ѧ���ɼ�����Ϣ" << endl;
	cout << "ѧ�� ���� ������� ��������� ���ݿ�" << endl;
	for ( i = 0; i < COUNT; i++) {
		cin >> id >> name >> programming >> network >> database;
		student[i].Set_info(id, name, programming, network, database);
	}	
	cout << "ѧ�� ���� ������� ��������� ���ݿ� �ܷ�" << endl;
	for( i = 0; i < COUNT; i++) {
		student[i].Show();
	} 
	
	return 0; 
}
