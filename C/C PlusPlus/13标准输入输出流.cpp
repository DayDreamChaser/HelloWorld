#include <iostream>
using namespace std;
int main()
{
    cout.setf(ios::left|ios::showpoint); //������룬��ʾС����	
    cout.precision(5); //���ó�С��������5λ 
    cout << 124.142428 << endl;
    
    cout.width(9);    //������ʾ�����10 
    cout.fill('#');    //����ʾ����հ״���*��� 
    cout.unsetf(ios::left); //���״̬�����
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