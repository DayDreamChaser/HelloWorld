#include <iostream>
#include <string.h>
using namespace std;
class Person
{
   private:
      char Name[9];
	  char Sex;
	  int Age;
	  char Pid[19];   // personal number
	  char *Addr;
   public:
      Person()        // 构造函数 
  	  {
 	      strcpy(Name,"xxxxxxxx");
 	      Age = 0;
 	      Sex = 'x';
 	      strcpy(Pid,"xxxxxxxxxxxxxxxxxx");
 	      Addr = NULL;
      }	
      Person(char *N, int A, char S, char *p, char *Ad)
      {
  	      strcpy(Name,N);
  	      Age = A;
  	      Sex = S;
  	      strcpy(Pid,p);
  	      int L = strlen(Ad);
  	      Addr = new char[L + 1];
  	      strcpy(Addr,Ad);
      }
      ~Person()     // 析构函数 
      {
      	  cout << "Now destroying Person" << Name << endl;
      	  delete [] Addr;  // if Addr != Null ,delete it
      }
      void Register(char *name, int age, char sex, char *pid, char *addr);
      void ShowMe();
};
void Person::Register(char *name, int age, char sex, char *pid, char *addr)
{
	  strcpy(Name,name);
	  Age = age;
	  Sex = sex;
	  strcpy(Pid,pid);
	  if(Addr != NULL) { delete [] Addr; }
	  int L = strlen(addr);
	  Addr = new char[L + 1];
	  strcpy(Addr,addr);
}
void Person::ShowMe()
{
	cout << Name << " " << Age << " " << Sex << " " << Pid << " ";
	if(Addr != NULL) { cout << Addr; }
	cout << endl;
}
int main()
{
	Person person1;
	Person person2("杜牧",19,'m',"61010319940919239","中国西安市咸宁西路29号");
	Person person3;
	cout << "person1:";
	person1.ShowMe();
	cout << "person2:";
	person2.ShowMe();
	person3.Register("李四",29,'w',"610103198409192493","中国上海市华山北路33号");
	cout << "person3:";
	person3.ShowMe();
	person2.Register("赵五",29,'w',"610103198409152127","中国新疆乌璐木齐市王家沟12号");
	cout << "person2:";
	person2.ShowMe();
	return 0; 
}
