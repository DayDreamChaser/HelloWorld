#include <iostream>
using namespace std;
class Fraction   //分数类 
{
 private:
    int a;       //分子 
	int b;
	int divisor(int p,int q);   //求最大公约数	
 public:
    Fraction()  //无参构造函数 
	{
	  a = 0; b = 1;
	} 
	Fraction(int , int);
	void set(int aa, int bb);  //设置参数 
	void show();
	Fraction add(Fraction u);  //加一个分数 
	Fraction operator + (Fraction u); //运算符+号重载
	bool operator == (Fraction u);
	Fraction operator - ();    // 求负运算重载
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
		b = bb;   // 分母有效性检验 
	} else {
		a = 0;
		b = 1;
	}
} 
void Fraction:: show()
{
	cout << a << "/" << b;
} 
//分数类相加，本类对象加u 
Fraction Fraction:: add(Fraction u)
{
	int tmp;
	Fraction v;
	
	v.a = a * u.b + u.a * b; // 分子
	v.b = b * u.b;
	tmp = divisor(v.a,v.b); //计算分子分母最大公约数
	v.a = v.a / tmp; 
	v.b = v.b / tmp;
}
Fraction Fraction::operator + (Fraction u)
{
	int tmp;
	Fraction v;
	
	v.a = a * u.b + u.a * b; // 分子
	v.b = b * u.b;
	tmp = divisor(v.a,v.b); //计算分子分母最大公约数
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