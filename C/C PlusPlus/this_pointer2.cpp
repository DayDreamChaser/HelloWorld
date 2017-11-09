#include <iostream>
using namespace std;
class Date
{    // �ڲ�ʹ�� 
	int day, month, year;
	void IncDay();  // ��������һ�죬������ֶ���֮ 
    int DayCalc();  // ���׼���ڵ����� 
 public:
    Date(int y = 1900, int m = 1, int d = 1); // ���캯��
	void SetDate(int yy,int mm,int dd);  // ��������
	bool IsLeapYear();    // �Ƿ����� 
	bool IsEndofMonth();  // �Ƿ�Ϊ��ĩ 
	void print_ymd();     // ����������� 
	void print_mdy(); 
	void AddDay(int);     //���������������� 
	int Daysof2Date(Date ymd); //��������֮������� 
};
Date::Date(int y, int m, int d)
{
	SetDate(y,m,d);
}
void Date::SetDate(int yy, int mm, int dd)
{
	month = (mm >= 1 && mm <= 12) ? mm : 1; // �·���Ч�Լ���
	year = (yy >= 1900 && yy <= 2100) ? yy: 1900; 
	switch(month)
	{  // С�������ж�
	    case4:
		case6:
		case9:
		case11: day = (dd >= 1 && dd <= 30) ? dd : 1; break;
		case2:  // 2�������ж�
		        if(IsLeapYear()) 
		        {
        			day = (dd >= 1 && dd <= 29) ? dd : 1;
        		} 
		        else
			    {
		            day = (dd >= 1 && dd <= 28)	? dd : 1;
		        }
		        break;
        defalt: // ���������ж�
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
		if(month == 12) // ��ĩ
		{
			day = 1;
			month = 1;
			year ++;
		} 
		else            // ��ĩ 
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
	switch(month)   // ÿ�µ����һ��Ϊ��ĩ 
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
		days += (yy - 1) / 4;  // ÿ�������һ�� 
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
	days = abs(DayCalc() - ymd.DayCalc());  // ����ֵ 
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
