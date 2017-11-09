#include <iostream>
#include <windows.h>
#include <mmsystem.h>  // 媒体控制函数头文件 
using namespace std;

class automobile
{
	private: 
        char type[20];                // 汽车型号 
        char color[20];               // 汽车颜色 
        float price;                  // 价格 
        int carry_weight;             // 载重量 
        int carry_customer;           // 载客量 
    public:
         // 初始化或修改数据成员
        void set_data(char *t, char *c, float pri, int cw, int cc);
        void movecar(int L, int k);   // 汽车水平运动K步 
        void horming(int num);        // 汽车鸣笛
		void downcar(int L);          // 倒车
		void play_mp3(char *ps);      // 播放歌曲 
        char *show_type(){ return type; } // 取出汽车型号 
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
	cout << "\n" << type << "水平直线运动" << endl;
	for (int i=0; i<L; i++) {
		cout << ' ' << "o_o";
		Sleep(1000/k);
		cout << "\b\b\b";
	} 
}
void automobile::downcar(int L)
{
	// 垂直下降运动
	cout << "\n" << type << "垂直下降运动:" << endl;
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
	cin >> a;        // 输入任何字符结束播放 
}

int main()
{
	automobile nison;
	char tp[] = "yyida";
	char ys[] = "white";
	nison.set_data(tp, ys, 300000, 5, 4);   // 测试设置初始值函数
	nison.horming(5);                       // 测试鸣笛函数
    nison.movecar(10, 4);                   // 测试水平移动
	nison.downcar(9);                       // 测试垂直移动
	char mp[] = "c:\\Olivia Ong - Fly Me to the Moon.mp3";
	// 将歌曲文件"Fly..”放到C盘根目录
	nison.play_mp3(mp);                     // 测试播放mp3歌曲
	
	return 0; 
} 








