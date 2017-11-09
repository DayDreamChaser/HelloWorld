#include <iostream>
#include <windows.h>
#include <string.h>
using namespace std;
// 定义两个全局字符指针数组，存取所需的单词
// num1中1到19，空出了0，所以可以直接用num1[0]调用，得到n对应单词
static char *num1[]=
{
	"","one ","two ","three ","four ","six ","seven ","eight ","nine ","ten ","eleven ","twelve ",
	"thirteen ","fourteen ","fifteen ","sixteen ","seventeen ","eighteen ","nineteen "
};
// num10中为-90，空出了和，所以可以直接用num10[n/10]调用，得到n对应单词
static char *num10[]=
{
	"","","twenty ","thirty ","forty ","fifty ","sixty ","seventy ","eighty ","ninety "
};
class person
{
  private:
      char *name;   // 名字 字符指针 
	  char sex;
  	  char pid[19]; // 身份证号 
	  int weight;
      int high;	
  public:
      person();  // 无参构造函数
	  person(char *n, char s, char *p, int w, int h); // 有参构造函数 
	  void change_data(char *n, char s, char *p, int w, int h); // 修改数据
	  void walking(int k, int v);   // 以v速度行走w步
      void hearing(char *sentence); // 将字符串小写变大写，大写变小写输出
	  void speak(int n); // 说出整数num 的英文句子
	  void writing();    // 在屏幕上画出汉子"曲"
	  void print();
	  void out(int a);   // 翻译小于1000的整数
	  ~person();         // 析构函数 
};
person::person()
{
	name = new char[strlen("xxxxxx") + 1];// 动态申请7个字符空间 
	strcpy(name,"xxxxxx");
	strcpy(pid,"xxxxxxxxxxxxxxxxxx");
	sex = 'X';
	weight = 0;
	high = 0;
} 
person::person(char *n, char s, char *p, int w, int h)
{
	name = new char[strlen(n) + 1];  // 放在堆区 
	strcpy(name,n);
	strcpy(pid,p);
	sex = s;
	weight = w;
	high = h;
}
void person::change_data(char *n, char s, char*p, int w,int h)
{
	if(name != NULL)
	{
	   delete [] name;
	}
	name = new char[strlen(n)];  // 放在堆区 
	strcpy(name,n);
	strcpy(pid,p);
	sex = s;
	weight = w;
	high = h;
}
void person::out(int a)
{
	int b = a%100;
	// 若百位不为零,输出百位数加hundred,若此时十位个位均为0,不加and 
	if(a/100 != 0) 	
	{
		 cout << num1[a/100] << "hundred ";
		 if(b != 0) 
	 	 {
             cout << "and "; //strcat(k,"and ");
	     } 
    } 
	if(b < 20)   // 当后两位在20以内，直接调用num1[n] 
	{  
	     cout << num1[b];
	}
    else 
	{
    	 cout << num10[b/10];
	 	 if(b%10 != 0)          // b%10为个位数，判断是否为0 
         {    
		     cout << "\b-" << num1[b%10];   
		 }
	}
}
void person::walking(int k, int v)
{
	cout << "\n" << name << "水平直线行走" << k << "步" <<endl;
    for(int i = 0; i < k; i++)
    {
    	cout << ' ' << "o_o";
    	Sleep(1000/v);
    	cout << "\b\b\b";
    }
}
void person::hearing(char *sentence)
{
	cout << endl << sentence << endl;
	char *p = new char[strlen(sentence) + 1];
	strcpy(p,sentence);
	char *pp = p;
	while(*p) // 当字符不为结束符'\0' 
	{   // 字符在小写a - z间 
		if(*p >= 'a' && *p <= 'z')
		{
			*p = *p - ('a' - 'A');
		}
		else if(*p >= 'A' && *p <= 'Z')
		{
		    *p = 'a' + (*p - 'A');	
		}
		p++;
		cout << pp << endl;
		delete []pp;
	}
	
}
void person::speak(int n)
{
    if(n > 1999999999) 
    {
    	cout << "无法处理太大的数！\n" << endl; 
    } 
	else 
    {
    	int a = n /1000000000, b = (n % 1000000000)/1000000;
		int c = (n % 100000)/1000, d = n % 1000;
    	// 当abcd不为零的时候，输出加上billion,million,thousand
    	if(a != 0)
	    {
	    	out(a);
            cout <<"billion ";
	    }
	    if(b != 0) 
	    {
    		out(b);
    		cout << "million "; 
    	} 
    	if(c != 0) 
	    {
	        out(c);
	    	cout << "thousand ";
	    }
	    if(d != 0) 
	    {
    		if(d<100 && (a!=0 || b!=0 || c!=0))
			{
		    	cout << "and ";
		    }
		    out(d);
    	}  
	cout << endl; 	
    }
}
void person::writing()
{
	cout << endl;
	cout << "               " << endl;
	cout << "   # # # # #   " << endl;
	cout << "   #   #   #   " << endl;
	cout << "   # # # # #   " << endl;
	cout << "   #   #   #   " << endl;
	cout << "   # # # # #   " << endl; 
	cout << "       #       " << endl;
	cout << "       #       " << endl;
	cout << "       #       " << endl;
}
void person::print()
{
	cout << name << ' ' << sex << ' ' << pid << ' ' << weight << ' ' << high << endl;
}
person::~person()           // 析构函数
{
	delete []name;
} 
class sing_star:public person // 继承方式 基类名1，继承方式 基类名2  
{
	float salary;          // 薪水
public:
    sing_star();
	sing_star(char *n, char s, char *p, int w, int h, float s1);
	void change_date(char *n, char s, char *p, int w, int h, float s1); 
	void playing(char *ps);
	void print();          // 输出歌星属性值 
};
sing_star::sing_star():person()
{
	salary = 0.0;
} 
sing_star::sing_star(char *n, char s, char *p, int w, int h, float s1)
{
	person::change_data(n,s,p,w,h);
	salary = s1;
}
void sing_star::change_date(char *n, char s, char *p, int w, int h, float s1)
{
	person::change_data(n,s,p,w,h);
	salary = s1;
}
void sing_star::playing(char *ps)
{
	char str[100] = "play ";
	strcat(str,ps);
	cout << str;
	mciSendString(str,NULL,0,NULL);
	char a;
	cin >> a; 
}
void sing_star::print()
{
	person::print();
	cout << salary << endl;
}
int main()
{
	person Brown("Brown",'F',"511011199509275678",120,165); // 创建对象
	Brown.print();
	Brown.walking(10,5);	
	Brown.hearing("You are simple");	
	Brown.writing();
	Brown.speak(1003);
	system("pause"); 
	
	sing_star Jack("James Chen",'M',"511011199509275355",155,175,10000);
	Jack.print();
	Jack.walking(10,5);
	Jack.hearing("You are too naive");
	Jack.speak(1002);
	cout << endl;
	return 0;
}