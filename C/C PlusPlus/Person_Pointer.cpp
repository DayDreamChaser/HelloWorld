#include <iostream>
#include <string.h>
using namespace std;
class Person      // build a person class
{
	private:
        char Name[9];
        char Sex;
		int Age;
	public:
	    Person()
		{
			strcpy(Name,"xxx");
			Age = 0;
			Sex = ' '; 
		} 
		~Person()
		{
			cout << "Now destroying Person" << endl;
		}
		void Register( char *name, int age, char sex);
		void ShowMe();
};
void Person::Register( char *name, int age, char sex)
{
	strcpy(Name,name);
	Age = age;
	Sex =sex;
}
void Person::ShowMe()
{
	cout << Name << '\t' << Age << '\t' << Sex << endl;
}
int main()
{
	Person *p1 = NULL, *p2 = NULL;  // define two pointer that point to object
	p1 = new Person;   // dynamicly create a Person object
    cout << "Person1: \t";
    p1->ShowMe();
    p1->Register("Zhang3", 19, 'm');
    cout << "person1;\t";
    p1->ShowMe();
    
    p2 = new Person;
    cout << "person2: \t";
    p2->ShowMe();
	*p2 = *p1;         //  assign between two objects
	cout << "person2: \t";
	p2->ShowMe();
	delete p1;        // release the space occupide by  the  object point from p1 pointer
	delete p2;        // Ö¸Ïòdestory function 
	
	return 0;
}