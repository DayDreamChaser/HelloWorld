#include <iostream>
using namespace std;
class Point
{
    int x, y;   // 点的X和Y
public:
    Point(int = 0, int = 0);  // 构造函数
	void SetPoint( int, int);
	int GetX() { return x; }  // 间接获取x
	int GetY() { return y; }
	void Print();             // 输出点的坐标 
}; 
Point::Point(int a, int b){ SetPoint(a,b); }
void Point::SetPoint(int a, int b)
{
	x = a;
	y = b;
}
void Point::Print()
{ 
    cout << x << ',' << y << endl; 
}
class Circle:public Point
{
    double radius;
public:
    Circle(int x = 0, int y = 0, double r = 0.0); // 构造函数 
    void SetRadius(double );   // 设置半径
	double GetRadius();
	double Area();
	void Print(); 
};                                    // Point 构造函数 
Circle::Circle(int a, int b, double r):Point(a,b)
{ 
    SetRadius(r);
}
void Circle::SetRadius(double r)
{ 
    radius = (r >= 0 ? r : 0);
}
double Circle::GetRadius(){ return radius; }
double Circle::Area(){ return 3.1415926 * radius * radius; }
void Circle::Print()     // 点 半径 
{
	cout << "Center=";
	Point::Print();      // 限定作用域为Point类
	cout << ";Radius=" << radius << endl;
}
class Cylinder:public Circle
{
    double high;
public:
    Cylinder(int x, int y, double r, double h);     // 构造函数 
	void Set_data(int x, int y ,double r, double h);
	double Area();    // 计算表面积 
	double Volume();  // 计算体积 
    void Print();
};
Cylinder::Cylinder(int x, int y, double r, double h):Circle(x,y,h)
{
	high = h;
}
void Cylinder::Set_data(int x, int y , double r, double h)
{
	SetPoint(x,y);
	SetRadius(r);
	high = h;
}
double Cylinder::Area()
{
	double r = GetRadius();
	return 2 * 3.14159 * r * (r + high);
}
double Cylinder::Volume()
{
	return Circle::Area() * high;
}
void Cylinder::Print()
{   // 点 半径 高 
	Circle::Print();
	cout << ";high=" << high << endl;
}
int main()
{
    cout << "测试点类哈" << endl;
	Point p(20,17);
	p.Print();
	
	cout << endl << endl << "测试圆类" << endl;
	Circle c(120,80,20.0);
	cout << "圆心:";
	c.Point::Print();
	cout << "\n圆面积:" << c.Area() << endl;
	
	cout << endl << "测试圆柱类:";
	Cylinder cy(230,129,12.0,12.0);
	cout << "圆柱体中心点:";
	cy.Point::Print();
	cout << "\n圆柱体圆面积:" << cy.Circle::Area() << endl;
	cout << "圆柱体表面积:" << cy.Area() << endl;
	cout << "圆柱体体积:" << cy.Volume() << endl;
	 
	return 0;
}
