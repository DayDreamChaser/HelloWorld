#include <iostream>
#include <windows.h>
using namespace std;

class  Clock   // define the clock category
{
	private:   // general is data
	    int Hour;     // Сʱ���� 
	    int Minute;   // ��������
		int Second;   // ������
		float Price;   // �۸�����
	public:    // function
	    void Set(int h, int m, int s, float p);
        void Run();
        void Report_Time();
        void Show_Time()
        {
        	cout << Hour << ':' << Minute << ':' << Second; 
        }
	    
};
//  �����޸�4�����ݳ�Ա�ĺ��� 
void Clock::Set(int h, int m, int s, float p)
{
	Hour = h;
	Minute = m;
	Second = s;
	Price = p;	 
} 
// ģ���ӱ����к���
void Clock::Run() 
{
	int i = 0;     // ֻģ������ 10s 
	for ( i=0; i<10; i++) {
		Second ++;
		if (Second == 60) {
			Second == 0;
			Minute ++;
			if (Minute == 60) {
				Minute == 0;
				Hour ++;
				if (Hour == 24) Hour = 0;
			}
		}
		cout << "\r             \r";  // �����У����ص�ǰ�е���λ
		Show_Time();
		Sleep(1000);   // ������ͣ����1000ms 
	}
	
}
void Clock::Report_Time()
{
	Show_Time();
    if ( Minute==0 && Second== 0) {
    	for ( int i=0; i<Hour; i++) {
	    	cout << "\007";
	    	Sleep(1000);
	    }
    }
}
int main(void)
{
	Clock XJTU_Big_Ben;
	XJTU_Big_Ben.Set( 0, 0, 0, 1000); 
	cout << "�ӱ����õ�ʱ�䣺\n";
	XJTU_Big_Ben.Report_Time();
	XJTU_Big_Ben.Run();
	
	system("pause");
	
	XJTU_Big_Ben.Set( 9, 59, 50, 9000);
	cout << "�ӱ����õ�ʱ�䣺\n";
	XJTU_Big_Ben.Run();
	cout << endl;
	XJTU_Big_Ben.Report_Time();
	cout << endl;
	XJTU_Big_Ben.Show_Time(); 
	cout << endl;
	
	Clock Omiga;
	cout << "��ʾOmiga��ʱ�䣺";
	Omiga = XJTU_Big_Ben; 
	Omiga.Show_Time();
	cout << endl;
}
