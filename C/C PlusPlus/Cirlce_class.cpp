#include <iostream>
using namespace std;

class Point      // ������� 
{
      int x, y;;  // ���x��y���� 
   public:
      void InitPoint(int, int);   // ���õ����� 
      void Print_Point();         // ���������� 
      int GetX(){ return x; }  
      int GetY(){ return y; }
};
// ���ⶨ��������Ա����
void Point::InitPoint( int a, int b)
{
	x = a;
	
	y = b;
} 
void Point::Print_Point()
{
	cout << '[' << x << ',' << y << ']';
}
class Circle     // Բ�ඨ��
{
	private:
	   double radius;  // ����뾶����
	   Point Center;   // ����Բ�Ķ���
	public:
	   void InitCircle(double, Point);  // ����Բ������
	   double GetRadius();
	   Point GetCenter();
	   double Area();
	   void Print(); 
};
// ���ⶨ���Ա����
void Circle::InitCircle(double r, Point p)
{
	radius = ( r >= 0 ? r : 0 );
	Center = p;
} 
double Circle::GetRadius(){ return radius; }
Point Circle::GetCenter(){ return Center; }
double Circle::Area(){ return 3.14159*radius*radius; }
void Circle::Print()
{
	cout << "Center = ";
	Center.Print_Point();
	cout << "; Radius = " << radius << endl;
}
int main()
{
	Point p,center;
	p.InitPoint(30, 50);
	center.InitPoint(120, 80);
	
	Circle c;
	c.InitCircle(10.0, center);
	
	cout << "Point p:";
	p.Print_Point();
	cout << endl;
	
	cout << "Circle c:";
	c.Print();
	cout << "The center of the cirlce c:";
	c.GetCenter().Print_Point();
	cout << "\nThe area of the cirlce c:" << c.Area() << endl;
	
	return 0;
}
