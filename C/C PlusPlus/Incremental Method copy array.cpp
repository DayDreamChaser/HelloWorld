#include <iostream>
using namespace std;

void MyCopy(char s[],char  t[]);
void MyLowercase(char t[]);

int main()
{
    char s[70] = "The offical site of Ghibli Museum, Mitaka in Japan";   	
	char t[70];
	
	MyCopy(s, t);
	MyLowercase(t);
	cout << t;
	return 0;
}

void MyCopy(char s[],char  t[])
{
	for (int i=0; s[i]; i++)
	{
		t[i] = s[i];
	}
}

void MyLowercase(char t[])
{
	for (int i=0; t[i]; i++)
	{
		if(t[i] >= 'A' && t[i] <= 'Z')
		{
			t[i] += 'a' - 'A'; 
		}
	}
}