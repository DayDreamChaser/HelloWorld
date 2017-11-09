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
	void write(char *pstr);    // 写入字符串 
	~UDISK()
	{
		cout << "撤销U盘对象" << endl; 
	}	
};
void UDISk::read(void)         // 读信息 
{
    int i = 0;
    for (i = 0; i < nrow; i++) 
    {
    	cout << crow[i] << endl;
    }
}
void UDISK::write(char *pstr) //写信息，字符串地址赋予crow 
{
    crow[nrow] = pstr;
	nrow++;	
}
class MP3:public UDISK
{
public:
    MP3():UDISK(){};
    void play(char *pstr);    //播放
	~MP3()
	{
		cout << "撤销MP3对象" << endl; 
	} 
};
void MP3::play(char *pstr)
{
    char str[100] = "play ";
    strcat(str,pstr);
    cout << str;
    mciSendString(str,NULL,0,NULL);  // 播放函数使用 
}
int main()
{
	UDISK U1;
	cout << "--模拟U盘写--" << endl;
	U1.write("劝学 ");
	U1.write("三更灯火五更鸡 "); 
	U1.write("正是男儿读书时 "); 
	U1.write("黑发不知勤学早 "); 
	U1.write("白首方悔读书时 ");
	cout << "--模拟U盘读--" << endl;
	U1.read();
	MP3 M1;
	cout << "--模拟MP3播放--" << endl;
	M1.play("曲锦楠 - 霞光.mp3");
	char a;
	cin >> a; 
	return 0;
}

