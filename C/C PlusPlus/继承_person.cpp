#include <iostream>
#include <windows.h>
#include <string.h>
using namespace std;
// ��������ȫ���ַ�ָ�����飬��ȡ����ĵ���
// num1��1��19���ճ���0�����Կ���ֱ����num1[0]���ã��õ�n��Ӧ����
static char *num1[]=
{
	"","one ","two ","three ","four ","six ","seven ","eight ","nine ","ten ","eleven ","twelve ",
	"thirteen ","fourteen ","fifteen ","sixteen ","seventeen ","eighteen ","nineteen "
};
// num10��Ϊ-90���ճ��˺ͣ����Կ���ֱ����num10[n/10]���ã��õ�n��Ӧ����
static char *num10[]=
{
	"","","twenty ","thirty ","forty ","fifty ","sixty ","seventy ","eighty ","ninety "
};
class person
{
  private:
      char *name;   // ���� �ַ�ָ�� 
	  char sex;
  	  char pid[19]; // ���֤�� 
	  int weight;
      int high;	
  public:
      person();  // �޲ι��캯��
	  person(char *n, char s, char *p, int w, int h); // �вι��캯�� 
	  void change_data(char *n, char s, char *p, int w, int h); // �޸�����
	  void walking(int k, int v);   // ��v�ٶ�����w��
      void hearing(char *sentence); // ���ַ���Сд���д����д��Сд���
	  void speak(int n); // ˵������num ��Ӣ�ľ���
	  void writing();    // ����Ļ�ϻ�������"��"
	  void print();
	  void out(int a);   // ����С��1000������
	  ~person();         // �������� 
};
person::person()
{
	name = new char[strlen("xxxxxx") + 1];// ��̬����7���ַ��ռ� 
	strcpy(name,"xxxxxx");
	strcpy(pid,"xxxxxxxxxxxxxxxxxx");
	sex = 'X';
	weight = 0;
	high = 0;
} 
person::person(char *n, char s, char *p, int w, int h)
{
	name = new char[strlen(n) + 1];  // ���ڶ��� 
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
	name = new char[strlen(n)];  // ���ڶ��� 
	strcpy(name,n);
	strcpy(pid,p);
	sex = s;
	weight = w;
	high = h;
}
void person::out(int a)
{
	int b = a%100;
	// ����λ��Ϊ��,�����λ����hundred,����ʱʮλ��λ��Ϊ0,����and 
	if(a/100 != 0) 	
	{
		 cout << num1[a/100] << "hundred ";
		 if(b != 0) 
	 	 {
             cout << "and "; //strcat(k,"and ");
	     } 
    } 
	if(b < 20)   // ������λ��20���ڣ�ֱ�ӵ���num1[n] 
	{  
	     cout << num1[b];
	}
    else 
	{
    	 cout << num10[b/10];
	 	 if(b%10 != 0)          // b%10Ϊ��λ�����ж��Ƿ�Ϊ0 
         {    
		     cout << "\b-" << num1[b%10];   
		 }
	}
}
void person::walking(int k, int v)
{
	cout << "\n" << name << "ˮƽֱ������" << k << "��" <<endl;
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
	while(*p) // ���ַ���Ϊ������'\0' 
	{   // �ַ���Сдa - z�� 
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
    	cout << "�޷�����̫�������\n" << endl; 
    } 
	else 
    {
    	int a = n /1000000000, b = (n % 1000000000)/1000000;
		int c = (n % 100000)/1000, d = n % 1000;
    	// ��abcd��Ϊ���ʱ���������billion,million,thousand
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
person::~person()           // ��������
{
	delete []name;
} 
class sing_star:public person // �̳з�ʽ ������1���̳з�ʽ ������2  
{
	float salary;          // нˮ
public:
    sing_star();
	sing_star(char *n, char s, char *p, int w, int h, float s1);
	void change_date(char *n, char s, char *p, int w, int h, float s1); 
	void playing(char *ps);
	void print();          // �����������ֵ 
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
	person Brown("Brown",'F',"511011199509275678",120,165); // ��������
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