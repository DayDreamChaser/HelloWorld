#include <iostream>

using namespace std;

int main(int argc, char* argv[])
{
	// Without "using" statement, this would be std::cout
	cout << "Hello world!" << endl; // "<<" = ²åÈë·û; "endl" = next line
	cout << (6/2)+3 << endl;
	
    float Dividend = 1;
    cout << "Dividend: ";
    cin >> Dividend;
    
	float Divisor = 1;
	cout << "Divisor: ";
	cin >> Divisor;
	
	float Result = (Dividend/Divisor);
	//Result += 3;
	cout << Result << endl; 
	
	
	// Note: You must type something before the Enter key
	char StopCharacter;
	cout << endl << "Press a key and \"Enter\": ";
	cin >> StopCharacter; // ">>" = "ÌáÈ¡·û" 
	
	return 0;
} 

 
                                                                                                 