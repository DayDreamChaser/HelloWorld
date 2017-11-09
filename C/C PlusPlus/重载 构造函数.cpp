#include <iostream>
#include <string.h>
#include <stdlib.h>
using namespace std;

class Date
{
        int year, month, day;
public:
        Date():year(1900), month(1), day(1){}    // 无参构造函数
		Date(int yy, int mm = 1, int dd = 1);    // 默认参数构造函数
		Date(Date &d):year(d.year), month(d.month), day(d.day){}  // 日期对象参数构造函数
		Date(char *ps);      // 字符串日期构造函数
		void print_ymd(); 
		~Date()              // 析构函数定义  无参 无返回
		{ 
		   static int i = 1;
		   cout << "撤销日期对象" << i << "\n";
		   i++;
		}          	
};
Date::Date(int yy, int mm, int dd):year(1900), month(1), day(1)
{
	if (yy >= 1900 && yy <= 9999) {
		year = yy;
	} else {
		return;
	} if (mm >= 1 && mm <= 12) {
		month = mm;
	} else {
		return;
	} if (dd >= 1 && dd <= 31) {
		day = dd;
	} else {
		year = 1900; month = 1; return;
	}
}
Date::Date(char *ps):year(1900), month(1), day(1)
{
	char py[5], pm[3], pd[3];
	strncpy(py, ps, 4);
	ps = ps + 5;
	strncpy(pm, ps, 2);
	ps = ps + 3;
	strncpy(pd, ps, 2);
	int yy = atoi(py), mm = atoi(pm), dd = atoi(pd);
	if (yy >= 1900 && yy <= 9999) year = yy; else return;
	if (mm >= 1 && mm <= 12) {
		month = mm;
	} else {
		year = 1900;
		return;
	}   
	if( dd >= 1 && dd <= 31) {
		day = dd;
	} else {
		year = 1900;
		month = 1;
		return;
	}
}
void Date::print_ymd()
{
	cout << year << '-' << month << '-' << day << endl;
} 
int main()
{
	Date date1;               // 使用无参构造函数
	cout << "date1:";
	date1.print_ymd();
	
	Date date2(2006);        // 使用哪个构造函数？  
	cout << "date2:";
	date2.print_ymd();
	
	Date date3(2006, 4);     // 使用哪个构造函数？
    cout << "date3:";
    date3.print_ymd();
    
    Date date4(2006, 4, 8);  // 使用哪个构造函数？
    cout << "date4:";
    date4.print_ymd();
    
    Date date5(2006, 14, 8); // 使用哪个构造函数？
    cout << "date5:";
	date5.print_ymd();
	
	Date date6(date4);       // 使用哪个构造函数？
	cout << "date6:"; 
	date6.print_ymd();
	
	Date date7("2008-08-08");// 使用哪个构造函数？
	cout << "date7:";
	date7.print_ymd();
	return 0;
}
