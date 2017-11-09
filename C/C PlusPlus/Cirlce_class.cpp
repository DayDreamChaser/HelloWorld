#include <iostream>
using namespace std;

class Point      // 定义点类 
{
      int x, y;;  // 点的x和y坐标 
   public:
      void InitPoint(int, int);   // 设置点坐标 
      void Print_Point();         // 输出坐标参数 
      int GetX(){ return x; }  
      int GetY(){ return y; }
};
// 类外定义两个成员函数
void Point::InitPoint( int a, int b)
{
	x = a;
	
	y = b;
} 
void Point::Print_Point()
{
	cout << '[' << x << ',' << y << ']';
}
class Circle     // 圆类定义
{
	private:
	   double radius;  // 定义半径对象
	   Point Center;   // 定义圆心对象
	public:
	   void InitCircle(double, Point);  // 设置圆类数据
	   double GetRadius();
	   Point GetCenter();
	   double Area();
	   void Print(); 
};
// 类外定义成员函数
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
