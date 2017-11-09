#include <iostream>

using namespace std;

int main(int argc, char* argv[])
{
    SAMSErrorHandling::initialize();
    
    do // at least once ...
    {
    	try
    	{
	    	float Dividend = GetDividend();
	    	float Divisor = GetDivisor();
	    	
	    	cout << Divide(Dividend,Divisor) << endl;
	    }
	    catch(...)
        {
    	    SAMSErrorHandling::HandleNotANumberError();
    	}
    }
    while(SAMSPrompt::UserWantsTocontinue
         ("More division? "));
    
    return 0;
}