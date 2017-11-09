#include <iostream>
using namespace std;
class Date
{    // 内部使用 
	int day, month, year;
	void IncDay();  // 日期增加一天，将问题分而化之 
    int DayCalc();  // 距基准日期的天数 
 public:
    Date(int y = 1900, int m = 1, int d = 1); // 构造函数
	void SetDate(int yy,int mm,int dd);  // 日期设置
	bool IsLeapYear();    // 是否闰年 
	bool IsEndofMonth();  // 是否为月末 
	void print_ymd();     // 按年月日输出 
	void print_mdy(); 
	void AddDay(int);     //日期增加任意天数 
	int Daysof2Date(Date ymd); //两个日期之间的天数 
};
Date::Date(int y, int m, int d)
{
	SetDate(y,m,d);
}
void Date::SetDate(int yy, int mm, int dd)
{
	month = (mm >= 1 && mm <= 12) ? mm : 1; // 月份有效性检验
	year = (yy >= 1900 && yy <= 2100) ? yy: 1900; 
	switch(month)
	{  // 小月天数判断
	    case4:
		case6:
		case9:
		case11: day = (dd >= 1 && dd <= 30) ? dd : 1; break;
		case2:  // 2月天数判断
		        if(IsLeapYear()) 
		        {
        			day = (dd >= 1 && dd <= 29) ? dd : 1;
        		} 
		        else
			    {
		            day = (dd >= 1 && dd <= 28)	? dd : 1;
		        }
		        break;
        defalt: // 大月天数判断
		        day = (dd >= 1 && dd <= 31) ? dd : 1;
	}
} 
bool Date::IsLeapYear()
{
	if(year % 400 == 0 || (year % 100 != 0 && year % 4 == 0))
	{
	    return true;
	}
	else
	{
	    return false;	
	}	
}
void Date::print_ymd()
{
	cout << year << "-" << month << "-" << day << endl;
}
void Date::print_mdy()
{
	char *monthName[12] = {"January","February","March","April",
	"May","June","July","August","September","October","November",
	"December"};
	cout << monthName[month - 1] << " " << day << "," << year << endl;
}
void Date::IncDay()
{
	if(IsEndofMonth())
	{
		if(month == 12) // 年末
		{
			day = 1;
			month = 1;
			year ++;
		} 
		else            // 月末 
		{
			day = 1;
			month ++;
		}
	}
	else
	{
		day++;
	} 
}
bool Date::IsEndofMonth()
{
	switch(month)   // 每月的最后一天为月末 
	{
		case 4:
		case 6:
		case 9:
		case 11: return day == 30;
		case 2:
		         if(IsLeapYear())
		         {
         		    return day == 29;
         		 }
         		 else
 	             {
 		         	return day == 28;
 		         }
        default: return day == 31;
	}
}
void Date::AddDay(int days)
{
	for(int i = 0; i <= days; i++)
	{
		IncDay();
	}
}
int Date::DayCalc()
{
	int days;
	int yy = year - 1900;
	days = yy * 365;
	if(yy)
	{
		days += (yy - 1) / 4;  // 每逢闰年加一天 
	}
	switch(month)
	{
		case 12:  days += 30;
		case 11:  days += 31;
		case 10:  days += 30;
		case 9:  days += 31; 
		case 8:  days += 31;
		case 7:  days += 30;
		case 6:  days += 31;
		case 5:  days += 30;
		case 4:  days += 31;
		case 3:  days += 31;
		case 2:  if(IsLeapYear())
		         {
			        days += 29;
		         }
		         else
 	             {
         		    days += 28;	
      	    	 }
      	case 1:  days += 31;
		default: break;    	 
	} 
	days += day;
	return days;
}
int Date::Daysof2Date(Date ymd)
{
	int days;
	days = abs(DayCalc() - ymd.DayCalc());  // 绝对值 
	return days;
}
int main()
{
	Date date1;
	date1.SetDate(2017,2,1);
	cout << "the current date is:" << endl;
	date1.print_ymd();
	date1.print_mdy();
	date1.AddDay(100);
	cout << "After 100 days,the date is:" << endl;
	date1.print_ymd();
	cout << "And before " << date1.Daysof2Date(Date(2008,8,24)) << " days," 
	"the Beijing Olympic Game had been over." << endl;	
	return 0;
}
