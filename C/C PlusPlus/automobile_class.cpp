#include <iostream>
#include <windows.h>
#include <mmsystem.h>  // ý����ƺ���ͷ�ļ� 
using namespace std;

class automobile
{
	private: 
        char type[20];                // �����ͺ� 
        char color[20];               // ������ɫ 
        float price;                  // �۸� 
        int carry_weight;             // ������ 
        int carry_customer;           // �ؿ��� 
    public:
         // ��ʼ�����޸����ݳ�Ա
        void set_data(char *t, char *c, float pri, int cw, int cc);
        void movecar(int L, int k);   // ����ˮƽ�˶�K�� 
        void horming(int num);        // ��������
		void downcar(int L);          // ����
		void play_mp3(char *ps);      // ���Ÿ��� 
        char *show_type(){ return type; } // ȡ�������ͺ� 
};
void automobile::set_data(char *t, char *c, float pri, int cw, int cc)
{
	strcpy(type, t);
	strcpy(color, c);
	price = pri;
	carry_weight = cw;
	carry_customer = cc;
} 
void automobile::movecar(int L, int k)
{
	cout << "\n" << type << "ˮƽֱ���˶�" << endl;
	for (int i=0; i<L; i++) {
		cout << ' ' << "o_o";
		Sleep(1000/k);
		cout << "\b\b\b";
	} 
}
void automobile::downcar(int L)
{
	// ��ֱ�½��˶�
	cout << "\n" << type << "��ֱ�½��˶�:" << endl;
	for (int i=0; i<L; i++) {
		cout << "o_o";
		Sleep(500);
		cout << "\b\b\b" << " " << endl;
	} 
}
void automobile::horming(int num)
{
	for (int i=0; i<num; i++) {
		cout << type;
		cout << "\007" << " di..." << endl;
		Sleep(1000);
	} 
}
void automobile::play_mp3(char *ps)
{
	char str[100] = "play "; 
	strcat(str, ps);
	cout << str;
	mciSendString(str, NULL, 0, NULL);
	char a;
	cin >> a;        // �����κ��ַ��������� 
}

int main()
{
	automobile nison;
	char tp[] = "yyida";
	char ys[] = "white";
	nison.set_data(tp, ys, 300000, 5, 4);   // �������ó�ʼֵ����
	nison.horming(5);                       // �������Ѻ���
    nison.movecar(10, 4);                   // ����ˮƽ�ƶ�
	nison.downcar(9);                       // ���Դ�ֱ�ƶ�
	char mp[] = "c:\\Olivia Ong - Fly Me to the Moon.mp3";
	// �������ļ�"Fly..���ŵ�C�̸�Ŀ¼
	nison.play_mp3(mp);                     // ���Բ���mp3����
	
	return 0; 
} 








