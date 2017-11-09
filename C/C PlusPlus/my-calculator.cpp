#include <iostream> 
#include <cmath>
using namespace std;
int main()
{
	double num1, num2;
	char op;
	double result;	
	char caption1[20] = "Error,Divided by 0!";
	char caption2[20] = "Invalid opereator!";	
	cout << "Please input the expression:" << endl;
	cin >> num1 >> op >> num2;	
	switch(op)
    {	
		case '+': result = num1 + num2;
		   cout << num1 << op << num2 << "=" << result << endl;
		   break;		   
        case '-': result = num1 - num2;
           cout << num1 << op << num2 << "=" << result << endl;
           break;         
        case '*': result = num1 * num2;
           cout << num1 << op << num2 << "=" << result << endl;
           break;        
        case '/': 
		   if(fabs(num2) < 1.0e-8) {
               cout << caption1 << endl;  
		   } else {
   		       	result = num1 / num2;
			    cout << num1 << op << num2 << "=" << result << endl;
   		   }   
           break;         
        default:
           cout << caption2 << endl;
	}		
	return 0;
}
