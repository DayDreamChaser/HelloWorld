#include <iostream> //  define date class  

using namespace std;
class Date
{
  public:
     int year, month, day;
	 void Init(int y, int m ,int d);
	 void print_ymd();	
};
void Date::Init(int yy, int mm, int dd)
{
	year = yy;
	month = mm;
	day = dd;
}
void Date::print_ymd()
{
	cout << year << '\t' << month << '\t' << day << endl;
}
int main()
{
	Date date1;
	Date *p1 = &date1;
	p1->Init(2017,1,21);
	p1->print_ymd();
	
	int *p2 = &date1.month;
	cout << *p2 << endl;
	
	// ����ָ�� - ����ֵ�� ��* ָ�����������βΡ��� 
	// ָ��������ڵ�ַ 
	void (Date::*p3)(int, int, int); // Date:: ���������� 
	void (Date::*p4)();
	p3 = Date::Init;            // ��Ӧ��Ӧ�ĺ��� 
	p4 = Date::print_ymd; 
    (date1.*p3)(2027,1,22); 
    (date1.*p4)();
    
	return 0;
}