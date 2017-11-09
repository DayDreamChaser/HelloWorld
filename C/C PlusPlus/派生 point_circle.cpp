#include <iostream>
using namespace std;
class Point
{
    int x, y;   // ���X��Y
public:
    Point(int = 0, int = 0);  // ���캯��
	void SetPoint( int, int);
	int GetX() { return x; }  // ��ӻ�ȡx
	int GetY() { return y; }
	void Print();             // ���������� 
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
    Circle(int x = 0, int y = 0, double r = 0.0); // ���캯�� 
    void SetRadius(double );   // ���ð뾶
	double GetRadius();
	double Area();
	void Print(); 
};                                    // Point ���캯�� 
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
void Circle::Print()     // �� �뾶 
{
	cout << "Center=";
	Point::Print();      // �޶�������ΪPoint��
	cout << ";Radius=" << radius << endl;
}
class Cylinder:public Circle
{
    double high;
public:
    Cylinder(int x, int y, double r, double h);     // ���캯�� 
	void Set_data(int x, int y ,double r, double h);
	double Area();    // �������� 
	double Volume();  // ������� 
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
{   // �� �뾶 �� 
	Circle::Print();
	cout << ";high=" << high << endl;
}
int main()
{
    cout << "���Ե����" << endl;
	Point p(20,17);
	p.Print();
	
	cout << endl << endl << "����Բ��" << endl;
	Circle c(120,80,20.0);
	cout << "Բ��:";
	c.Point::Print();
	cout << "\nԲ���:" << c.Area() << endl;
	
	cout << endl << "����Բ����:";
	Cylinder cy(230,129,12.0,12.0);
	cout << "Բ�������ĵ�:";
	cy.Point::Print();
	cout << "\nԲ����Բ���:" << cy.Circle::Area() << endl;
	cout << "Բ��������:" << cy.Area() << endl;
	cout << "Բ�������:" << cy.Volume() << endl;
	 
	return 0;
}
