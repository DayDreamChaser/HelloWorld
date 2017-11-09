//����MP3�ļ� 

#include <iostream>
#include <fstream>
using namespace std;

//mp3�ļ����ƺ������� 
bool mp3cpy(const char* szDestFile, const char *szOrigFile);

int main()
{
	char szDestFile[50]; //ԭʼ�ļ���
	char szOrigFile[50]; //Ŀ���ļ���
	
	cout << "������ԭʼ�ļ�����Ŀ���ļ���: ";
	cin >> szOrigFile;
	cin >> szDestFile;
	
	bool bRet = mp3cpy(szDestFile, szOrigFile);
	if (bRet)
	{
		cout << "�ļ����Ƴɹ���" << endl;	 
	}
	else 
	{
		cout << "�ļ�����ʧ��" << endl;
	}
	
	return 0;
}

bool mp3cpy(const char* szDestFile, const char *szOrigFile)
{   //��ԭʼ�ļ�����д��Ŀ���ļ� 
	ofstream fout(szDestFile, ios::binary); //��Ŀ���ļ� 
	ifstream fin(szOrigFile, ios::binary);  //��ԭʼ�ļ�
	
	bool bRet = true;
	if (fin.bad()) //ԭʼ�ļ����� 
	{
		bRet = false;
	} 
	else
	{
	    fin.seekg(0L, ios::beg); //��λԭʼ�ļ���ʼλ��
		while (!fin.eof()) //ԭʼ�ļ�δ��β 
		{
		    char szBuf[256] = {0};
			fin.read(szBuf, sizeof(char) * 256);//��������szBuf
			int length = fin.gcount();//ʵ�ʶ�ȡ���ֽ�
			if (fout.bad()) //Ŀ���ļ����� 
			{
			    bRet = false;
				break;	
			}
			fout.write(szBuf, length); //ÿ��д��Ŀ���ļ�length���ֽ�      	
		}			
	}
	fout.close();
	fin.close(); 
    
    return bRet;
}







