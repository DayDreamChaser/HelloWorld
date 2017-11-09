#include <iostream>
using namespace std;
class Complex
{
	double real, imag;
 public:
    Complex(double r = 0, double i = 0):real(r), imag(i){} 
    double Real(){ return real; }
    double Imag(){ return imag; }
    Complex operator + (Complex&);  //��������� +
	Complex operator + (double);
	bool operator == (Complex);
	Complex operator ++();         // ���������++ 
	Complex operator ++(int); 
    ~Complex(){ } 
};
Complex Complex::operator + (Complex &c)
{
    Complex temp;
	temp.real = c.real + real;
    temp.imag = c.imag + imag;
    return temp;
}
Complex Complex::operator + (double d)
{
	Complex temp;
	temp.real = real + d;
	temp.imag = imag;
	return temp;
}
bool Complex::operator == (Complex c)  // ����������鲿 
{
	if(real == c.real && imag == c.imag) {
		return true;
	} else {
		return false; 
	}
}
Complex Complex::operator ++ ()     // ����ǰ�������++ 
{
    real += 1;
	return *this;	
}
Complex Complex::operator ++ (int)  // ���غ��������++
{
	real += 1;
	return *this;
}
int main()
{
	Complex c1(4,5), c2(7,8), c3;
	cout << "c1 = " << c1.Real() << "+j" << c1.Imag() << endl;
	system("pause");
	cout << "c2 = " << c2.Real() << "+j" << c2.Imag() << endl;
	system("pause");
	c3 = c1 + c2;
	cout << "c3 = c1 + c2 =" << c3.Real() << "+j" << c3.Imag() << endl;
	system("pause");
	c3 = c3 + 6.5;
	cout << "c3 = c3 + 6.5 =" << c3.Real() << "+j" << c3.Imag() << endl;
	system("pause");
	if (c1 == c2) {
		cout << "c1��c2�����������" << endl;	 
	} else {
		cout << "c1��c2�������������" << endl; 
	}
	system("pause");
	c2 ++;
	cout << "c2++ =" << c2.Real() << "+j" << c2.Imag() << endl;
	system("pause");
	++ c1;
	cout << "++c1 = " << c1.Real() << "+j" << c1.Imag() << endl; 
	
	return 0;
}