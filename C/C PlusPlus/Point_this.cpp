#include <iostream>
using namespace std;
class Point
{
  private:
      double x, y;
  public:
      void set(double x, double y)
	  {
  	      	(*this).x = x;  // my
  	      	this->y = y;    // 返回指针或本对象 
  	  }	
  	  void show()
  	  {
  	  	cout << "(" << x << "," << y << ")" << endl;
   	  }
};
int main()
{
	Point a, b, c;
	a.set(100,50);
	a.show();
	cout << endl;
	
	b.set(123,12);
	b.show();
	cout << endl;
	return 0;
}
