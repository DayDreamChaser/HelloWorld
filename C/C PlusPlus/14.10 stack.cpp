#include <iostream>
#include <stack>
using namespace std;
int main()
{
    stack <int> s;
	s.push(1);	
	s.push(2);
	s.push(3);
	s.push(4);
	s.push(11);
	
	cout << "top of the stack:" << s.top() << endl;
	cout << "the number of elements:" << s.size() << endl;
	cout << "process of pop:" << endl;
	
	while (s.empty() != true) // stack isn't empty
	{   cout << "\t\t";
	    cout << s.top() << endl; //read the top of the stack	
	    s.pop();  // pop, and delete the top
	}
	
	return 0;
}