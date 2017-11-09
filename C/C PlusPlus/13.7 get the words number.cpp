#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

class Wordtype   //单词类 
{
 public:
    char word[20];	
    int count;
};
//获取单词函数
int Getwords(Wordtype *words); 
 
int main()
{
	Wordtype words[100] = {"",0};
	
	int n = Getwords(words); 
	
	cout << "英文单词统计结果如下: " << endl;
	for (int m=0; m<n; m++)
	{
		cout << words[m].word << ':' << words[m].count << endl;
	}
	cout << "搜索出共" << n << "个单词。" << endl; 
	
	return 0;
}

int Getwords(Wordtype *words)
{
    ifstream in("words.txt");  // 打开英文单词文件
	if (!in)
	{
		cout << "failed to open the file!" << endl;
		return 1;
	}
	
	int n = 0;  // total number of words 
	char word[20];
	int m;    
	
	while (in)
	{
		in >> word;  // 读单词 
		if (!in)
		{   // 文件结尾时退出循环 
			break;
		} 
		bool flag = false;
		
		for (m = 0; m < n; m++)
		{   
			if (!strcmp(word,words[m].word)) // 第一次words[m].word无单词 
			{   //已存在该单词 
				words[m].count++; //原有单词计数加1 
				flag = true;
				break;
			}
		}
		if (!flag) // 发现新单词 
		{
		    words[m].count = 1;  //新单词计数为1 
			strcpy(words[m].word, word); //保存新单词 
			n++;        //单词总计数加1 
		} 
	}
	in.close();  //关闭文件 
	
	return n; //返回单词个数 
}