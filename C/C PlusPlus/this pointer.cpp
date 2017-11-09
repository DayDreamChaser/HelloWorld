#include <iostream>
using namespace std;
class Test
{
         int x;
  public:
       	 Test( int = 0 );
       	 void print();
};
Test::Test(int a)
{
   x = a;  // ¹¹Ôìº¯Êı 
}
void Test::print()
{
   int x = 13;
   cout << "      x=" << x << endl;
   cout << "this->x=" << this->x << endl;
   cout << "(*this).x=" << (*this).x << endl;
} 
int main()
{
   Test testObject( 12 );
   testObject.print();
   
   return 0;
}
