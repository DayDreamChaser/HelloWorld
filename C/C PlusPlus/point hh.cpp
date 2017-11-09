#include<iostream> 
#include<cmath>
using namespace std;
//__________________________点__________________________________ 
class Point
{
   int x,y;
   public:
     Point(int = 0,int = 0); //构造函数
  void SetPoint(int,int); //设置坐标
  int GetX() { return x;}
  int GetY() { return y;}
  void Print(); //输出点的坐标 
};
Point::Point(int a,int b) { SetPoint(a,b);}
void Point::SetPoint(int a,int b)
{ x=a;y=b; }
void Point::Print() 
{  cout<<'['<<x<<','<<y<<']'; }
//_____________________________长方形____________________________________
class Rectangle:public Point
{
 double length,width;
 public:
  Rectangle(int x=0,int y=0,double length=0.0,double width=0.0);
  void SetWL(double,double); 
  double Getlength();
  double Getwidth();
  double Area();
  void Print();
};
Rectangle::Rectangle(int a,int b,double length,double width):Point(a,b)
{ SetWL(length,width);}
void Rectangle::SetWL(double length,double width)
{ 
    length=(length>=0.0?length:0.0);
    width=(width>=0.0?width:0.0);
}
double Rectangle::Getwidth(){ return width;}
double Rectangle::Getlength(){ return length;}
double Rectangle::Area() { return length*width;}
void Rectangle::Print()
{
 cout<<"\nCenter = " ;
 Point::Print();
 cout<<"; length = "<<length<<"; width = "<<width<<endl;
}
//__________________________长方体_______________________________
class Rectanglar_cuboid:public Rectangle
{
 double high;
 public:
  Rectanglar_cuboid(int x,int y,double length,double width,double h);
  void Set_data(int x,int y,double length,double width,double h);
  double Area();  //表面积 
  double Volume(); //体积 
  void Print(); 
};
Rectanglar_cuboid::Rectanglar_cuboid(int x,int y,double length,double width,double h):Rectangle(x,y,length,width)
{ high=h;}
void Rectanglar_cuboid::Set_data(int x,int y,double length,double width,double h)
{
 SetPoint(x,y);
 SetWL(length,width);
 high=h;
}
double Rectanglar_cuboid::Volume()
{ return Rectangle::Area()*high; }
double Rectanglar_cuboid::Area()
{
 double length=Getlength(),width=Getwidth();
 return (length*width+high*length+width*high)*2; 
}
void Rectanglar_cuboid::Print()
{
 cout<<"\nCenter = " ;
 Rectangle::Point::Print();
 cout<<"; length = "<<Rectangle::Getlength()<<"; width = "<<Rectangle::Getwidth()<<"; high = "<<high<<endl;
}
//____________________________________________________________
int main()
{
 cout<<"Test Point Class"<<endl;
 Point p(30,50);
 p.Print();
 cout<<endl;
 system("pause");
  
 cout<<endl<<endl<<"Test Rectangle Class"<<endl;
 Rectangle r(120,80,10.0,5.0);
 cout<<"the center of Rectangle: ";
    r.Print();
 cout<<"the area of Rectangle: "<<r.Area()<<endl;
 system("pause");
  
 cout<<endl<<"Test Rectanglar_cuboid Class"<<endl;
 Rectanglar_cuboid rc(240,160,10.0,5.0,2.0);
 cout<<"the center of Rectanglar_cuboid: ";
 rc.Print();
 cout<<"the body's area of Rectanglar_cuboid: "<<rc.Area()<<endl;
 cout<<"the volume of Rectanglar_cuboid: "<<rc.Volume()<<endl;
 return 0;
}