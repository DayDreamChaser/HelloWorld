#include <iostream>
#inclide <windows.h>
#include <mmsystem.h> 
using namespace std;
class UDISK
{
private:
    char *crow[100];
	int nrow;
public:
    UDISK(void)
	{
		nrow = 0;
	}
	void read(void);
	void write(char *pstr);    // д���ַ��� 
	~UDISK()
	{
		cout << "����U�̶���" << endl; 
	}	
};
void UDISk::read(void)         // ����Ϣ 
{
    int i = 0;
    for (i = 0; i < nrow; i++) 
    {
    	cout << crow[i] << endl;
    }
}
void UDISK::write(char *pstr) //д��Ϣ���ַ�����ַ����crow 
{
    crow[nrow] = pstr;
	nrow++;	
}
class MP3:public UDISK
{
public:
    MP3():UDISK(){};
    void play(char *pstr);    //����
	~MP3()
	{
		cout << "����MP3����" << endl; 
	} 
};
void MP3::play(char *pstr)
{
    char str[100] = "play ";
    strcat(str,pstr);
    cout << str;
    mciSendString(str,NULL,0,NULL);  // ���ź���ʹ�� 
}
int main()
{
	UDISK U1;
	cout << "--ģ��U��д--" << endl;
	U1.write("Ȱѧ ");
	U1.write("�����ƻ������ "); 
	U1.write("�����ж�����ʱ "); 
	U1.write("�ڷ���֪��ѧ�� "); 
	U1.write("���׷��ڶ���ʱ ");
	cout << "--ģ��U�̶�--" << endl;
	U1.read();
	MP3 M1;
	cout << "--ģ��MP3����--" << endl;
	M1.play("����� - ϼ��.mp3");
	char a;
	cin >> a; 
	return 0;
}

