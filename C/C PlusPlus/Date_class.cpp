#include <iostream>
#include <time.h>
using namespace std;
class Date
{
 private:
     int year, month, day;             
     void SetSystemDate();            // ȡ��ϵͳ����
 public:
     Date (int y = 1900, int m = 1, int d = 1) {  // ���캯�� 
    	  year = y; month = m; day = d;
     }
     void init(int y, int m, int d);  // ������������ 
     void print_ymd();                // ��ʾ������ 
   	 void print_mdy();                // ��ʾ������ 
   	 int get_year(){ return year; }   // �õ����ֵ 
   	 int get_month(){ return month; } // �õ��·�ֵ 
   	 int get_day(){ return day; }     // �õ��շ�ֵ 
   	 bool IsLeapYear();	              // �ж��Ƿ�Ϊ���� 
};

void Date::SetSystemDate()
{    // ȡ��ϵͳ����
	tm *gm;
	time_t t = time(NULL);
	gm = gmtime(&t);
	year = 1900 + gm->tm_year;
	month = gm->tm_mon + 1;
	day = gm->tm_mday;
} 
void Date::init(int yy, int mm, int dd)
{
	if (yy>=1900 && yy<=9999) {
		year == yy;
	} else {
		SetSystemDate();
		return;
	} if (mm>=1 && mm<=12) {
		month = mm;
	}  else {
		SetSystemDate();
		return;
	} if (dd>=1 && dd<=31) {
		day = dd;
	}  else {
		SetSystemDate();
		return;
	}
	    
}
void Date::print_ymd()
{
	cout << year << '-' << month << '-' << day << endl;
}
void Date::print_mdy()
{
	cout << month << '-' << day << "-" << year << endl;
}
bool Date::IsLeapYear()
{
	if ( year % 400 == 0 || (year % 100 != 0 && year % 4 == 0 )) {
		return true;
	} else {
		return false;
	}
}
int main()
{
	Date date1;                 // ����һ����������󣬵�δ��ʼ��
	cout << "������ڶ���date1������ֵ��";
	date1.print_ymd();          // ��ʾδ��ʼ�����ݵ����
	system("pause");
	
	date1.init( 2006, 3, 28);   // ��ʼ�����ݳ�Ա
	cout << "��������ڶ���date1������ֵ��";
	date1.print_ymd();
	system("pause");
	
	Date date2;                 // �ٴ���һ�����������
	date2.init( 2013, 11, 26);
	cout << "������ڶ���date2������ֵ��";
	date2.print_mdy();
	system("pause");
	
	if (date2.IsLeapYear()) {     // �����ж����꺯�� 
        cout << date2.get_year() << "������" << endl; 
	} else {
		cout << date2.get_year() << "��������" << endl; 
	}
	
	return 0;
}

