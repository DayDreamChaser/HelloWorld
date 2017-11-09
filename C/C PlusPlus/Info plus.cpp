#include <iostream>
#include <cstring>
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
    const int MAX_COUNT = 100;
    int count;
	int i = 0, j = 0;
	int id;        // �洢��Ϣ���м���� 
	char name[20];
	int programming;
	int network;
	int database;
	Info student[MAX_COUNT], tmp;
	
	cout << "������ѧ��������";
	cin >> count;
	while (count > MAX_COUNT) {
		cout << "ѧ���������ܳ���" << MAX_COUNT << "�ˣ����������룺";
		cin >> count; 
	} 
	
	cout << "������ѧ���ɼ�����Ϣ" << endl;
	cout << "ѧ�� ���� ������� ��������� ���ݿ�" << endl;
	for ( i = 0; i < count; i++) {
		cin >> id >> name >> programming >> network >> database;
		student[i].Set_info(id, name, programming, network, database);
	}	
	
	cout << "���ָܷߵ��������£�" << endl;
	for (i = 0; count > i; i = i + 1) {
	    for (j = count - 1; j > i; j = j -1) {
    		if (student[j].Get_Tol() > student[j-1].Get_Tol()) {
		    	tmp = student[j];
		    	student[j] = student[j-1];
		    	student[j-1] = tmp;
		    }
    	}	
	} 
	
	cout << "ѧ�� ���� ������� ��������� ���ݿ� �ܷ�" << endl;
	for( i = 0; i < count; i++) {
		student[i].Show();
	} 
	cout << "ÿ�ſγ̳ɼ�������85�ֵ�ѧ��������" << endl;
	cout << "ѧ�� ���� ������� ��������� ���ݿ� �ܷ�" << endl;
	for( i = 0; i < count; i++) {
		if (student[i].Get_Pro() > 85 && student[i].Get_net() > 85 && student[i].Get_Dat() > 85)
		       student[i].Show();
	}
	
	return 0; 
}
