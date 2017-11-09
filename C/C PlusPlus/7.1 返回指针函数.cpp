#include <iostream>
using namespace std;

char *idonot(char *str);

int main()
{
    char *str1 = "    wodeasdaf fuck!";
	char *str2 = NULL;
	
	str2 = idonot(str1);
	cout << "i am:" << str2 << endl;
		
	return 0;
}

char *idonot(char *str)
{
	while (*str == ' ')
	{
		str++;
	}
	
	return str;
}
