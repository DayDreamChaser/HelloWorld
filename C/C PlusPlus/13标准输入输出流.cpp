#include <iostream>
using namespace std;
int main()
{
    cout.setf(ios::left|ios::showpoint); //设左对齐，显示小数点	
    cout.precision(5); //设置除小数点外有5位 
    cout << 124.142428 << endl;
    
    cout.width(9);    //设置显示区域宽10 
    cout.fill('#');    //在显示区域空白处用*填充 
    cout.unsetf(ios::left); //清除状态左对齐
	cout.setf(ios::right);
	cout << 247.436459 << endl;
	
	cout.setf(ios::left|ios::fixed);
	cout.precision(7);
	cout << 999.1234456 << endl;
	cout << 99.123456 << endl;
	
	cout.unsetf(ios::left|ios::fixed);
	cout.setf(ios::left|ios::scientific);
	cout.precision(6);
	cout << 123.45678 << endl;
    
	return 0;
}