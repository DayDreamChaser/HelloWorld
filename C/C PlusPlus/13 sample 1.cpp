/*
Author (c) LeiXiaoYi
All copyright researved 

Filename  io stream library
2017,02,15
*/

#include <iostream>
#include <fstream> 
using namespace std;
int main()
{
    //open the file
	ofstream out("firstFile.txt");
	if (!out)
	{
		cout << "打开文件失败" << endl;
		return 1;
	}		
	//write the file
	out << "welcome to";
	char ch[] = "Nei jiang city.";
	int i = 0;
	while (ch[i] != 0)
	{
		out.put(ch[i]);
		i++;
	} 
	out.close();  // close the file
	
	return 0;
}