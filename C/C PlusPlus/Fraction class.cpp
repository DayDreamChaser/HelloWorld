#include <iostream>
using namespace std;
class Fraction   //������ 
{
 private:
    int a;       //���� 
	int b;
	int divisor(int p,int q);   //�����Լ��	
 public:
    Fraction()  //�޲ι��캯�� 
	{
	  a = 0; b = 1;
	} 
	Fraction(int , int);
	void set(int aa, int bb);  //���ò��� 
	void show();
	Fraction add(Fraction u);  //��һ������ 
	Fraction operator + (Fraction u); //�����+������
	bool operator == (Fraction u);
	Fraction operator - ();    // ����������
	~Fraction(){}; 
};
Fraction::Fraction(int x, int y)
{
    set(x,y);
}
void Fraction:: set(int aa, int bb)
{
	a = aa;
	if(bb != 0) {
		b = bb;   // ��ĸ��Ч�Լ��� 
	} else {
		a = 0;
		b = 1;
	}
} 
void Fraction:: show()
{
	cout << a << "/" << b;
} 
//��������ӣ���������u 
Fraction Fraction:: add(Fraction u)
{
	int tmp;
	Fraction v;
	
	v.a = a * u.b + u.a * b; // ����
	v.b = b * u.b;
	tmp = divisor(v.a,v.b); //������ӷ�ĸ���Լ��
	v.a = v.a / tmp; 
	v.b = v.b / tmp;
}
Fraction Fraction::operator + (Fraction u)
{
	int tmp;
	Fraction v;
	
	v.a = a * u.b + u.a * b; // ����
	v.b = b * u.b;
	tmp = divisor(v.a,v.b); //������ӷ�ĸ���Լ��
	v.a = v.a / tmp; 
	v.b = v.b / tmp;
}
bool Fraction:: operator == (Fraction u)
{
	float x, y;
	x = (float) a / b;
	y = (float) u.a / u.b;
	if(x == y) {
		return true;
	} else {
		return false;
	}
}
Fraction Fraction:: operator - ()
{
	a = a * (-1);
	return *this;
}
int Fraction:: divisor(int p, int q)
{
	int r;
	if(p < q) {
		int tmp;
		tmp = p;
		p = q;
		q = tmp;
	}
	r = p % q;
	while(r != 0) {
	    p = q;
		q = r;
		r = p % q;	
	}
	return q;
}
int main()
{
	Fraction f1, f2, f3;
	f1.set(-4,5);
	f2.set(3,6);
	f1.show();
	cout << " + ";
	f2.show();
	f3 = f1 + f2;
	cout << " = ";
	f3.show();
	f1.set(6,-23);
	if(f1 == f3) {
		cout << "\nf1==f3" << endl;
	} else {
		cout << "\nf1!=f3" << endl;
	}
	f2 = (-f2);
	f2.show();
	cout << endl;

	return 0;
}