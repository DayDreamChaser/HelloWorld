#include <iostream>
#include <fstream> 
using namespace std;
int main()
{
	//open the file
    ifstream in("firstFile.txt");
    if (!in)
    {
    	cout << "can't open the file" << endl;
        return 1;
	}
	
	// read the file
	char ch[80];
	in >> ch;  // because the blank,it's read line by line
	cout << ch;
	in >> ch;
	cout << ch;
	
	while (in)
	{
		char c = in.get();
		if (in)
		{
			cout << c;
		}
	}
	in.close();
	cout << endl;
	
	return 0;
}