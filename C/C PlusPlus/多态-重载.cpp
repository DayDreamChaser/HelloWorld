#include <iostream>
using namespace std;
class pet     // ��̬��1.һ�����������أ�����ʱ��̬����ͬ����ֵ����ͬ���� 
{             //       2.virtual ,��ͬ��֮��ʵ������ʱ��̬ 
 public:
    virtual void speak()  // virtualʹspeak()��Ϊ�麯�� ��ʵ��ָ��������Ļ���ָ�� 
    {                     // �����������Ա���� 
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
{   // һ���ӿڣ�������� 
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