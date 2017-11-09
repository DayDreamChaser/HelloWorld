#include <iostream>
#include <windows.h>
using namespace std;

class  Clock   // define the clock category
{
	private:   // general is data
	    int Hour;     // 小时属性 
	    int Minute;   // 分钟属性
		int Second;   // 秒属性
		float Price;   // 价格属性
	public:    // function
	    void Set(int h, int m, int s, float p);
        void Run();
        void Report_Time();
        void Show_Time()
        {
        	cout << Hour << ':' << Minute << ':' << Second; 
        }
	    
};
//  设置修改4个数据成员的函数 
void Clock::Set(int h, int m, int s, float p)
{
	Hour = h;
	Minute = m;
	Second = s;
	Price = p;	 
} 
// 模拟钟表运行函数
void Clock::Run() 
{
	int i = 0;     // 只模拟运行 10s 
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
		cout << "\r             \r";  // 不换行，返回当前行的首位
		Show_Time();
		Sleep(1000);   // 程序暂停运行1000ms 
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
	cout << "钟表设置的时间：\n";
	XJTU_Big_Ben.Report_Time();
	XJTU_Big_Ben.Run();
	
	system("pause");
	
	XJTU_Big_Ben.Set( 9, 59, 50, 9000);
	cout << "钟表设置的时间：\n";
	XJTU_Big_Ben.Run();
	cout << endl;
	XJTU_Big_Ben.Report_Time();
	cout << endl;
	XJTU_Big_Ben.Show_Time(); 
	cout << endl;
	
	Clock Omiga;
	cout << "显示Omiga的时间：";
	Omiga = XJTU_Big_Ben; 
	Omiga.Show_Time();
	cout << endl;
}
