#include <iostream>
using namespace std;
class pet     // 多态：1.一个类里面重载，编译时多态，不同返回值，不同参数 
{             //       2.virtual ,不同类之间实现运行时多态 
 public:
    virtual void speak()  // virtual使speak()成为虚函数 ，实现指向派生类的基类指针 
    {                     // 访问派生类成员函数 
   	    cout << "little mice,use you loaf!" << endl;
    }	
};
class dog : public pet
{
 public:
    void speak()
	{
		cout << "What a pity dog!" << endl;
	}   
};
class cat : public pet
{
 public:
     void speak()
     {
     	cout << "I'm your king,it's time to establish my dynasty of!" << endl;
     }
};
int main()
{   // 一个接口，多个功能 
    pet pet1, *p = &pet1, *p1 = NULL;
    cat cat1;
    dog dog1;
    p1 = new dog;
    p1->speak();
    
    pet &p2 = cat1;
    p2.speak();
    
    int x;
    cin >> x;
    if(x == 1) {
    	p = &dog1;
    }
    if(x == 2) {
    	p = &cat1;
    }
    p ->speak();
    
	return 0;
}