#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

class Wordtype   //������ 
{
 public:
    char word[20];	
    int count;
};
//��ȡ���ʺ���
int Getwords(Wordtype *words); 
 
int main()
{
	Wordtype words[100] = {"",0};
	
	int n = Getwords(words); 
	
	cout << "Ӣ�ĵ���ͳ�ƽ������: " << endl;
	for (int m=0; m<n; m++)
	{
		cout << words[m].word << ':' << words[m].count << endl;
	}
	cout << "��������" << n << "�����ʡ�" << endl; 
	
	return 0;
}

int Getwords(Wordtype *words)
{
    ifstream in("words.txt");  // ��Ӣ�ĵ����ļ�
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
		in >> word;  // ������ 
		if (!in)
		{   // �ļ���βʱ�˳�ѭ�� 
			break;
		} 
		bool flag = false;
		
		for (m = 0; m < n; m++)
		{   
			if (!strcmp(word,words[m].word)) // ��һ��words[m].word�޵��� 
			{   //�Ѵ��ڸõ��� 
				words[m].count++; //ԭ�е��ʼ�����1 
				flag = true;
				break;
			}
		}
		if (!flag) // �����µ��� 
		{
		    words[m].count = 1;  //�µ��ʼ���Ϊ1 
			strcpy(words[m].word, word); //�����µ��� 
			n++;        //�����ܼ�����1 
		} 
	}
	in.close();  //�ر��ļ� 
	
	return n; //���ص��ʸ��� 
}