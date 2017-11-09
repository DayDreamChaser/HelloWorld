//复制MP3文件 

#include <iostream>
#include <fstream>
using namespace std;

//mp3文件复制函数声明 
bool mp3cpy(const char* szDestFile, const char *szOrigFile);

int main()
{
	char szDestFile[50]; //原始文件名
	char szOrigFile[50]; //目标文件名
	
	cout << "请输入原始文件名和目标文件名: ";
	cin >> szOrigFile;
	cin >> szDestFile;
	
	bool bRet = mp3cpy(szDestFile, szOrigFile);
	if (bRet)
	{
		cout << "文件复制成功！" << endl;	 
	}
	else 
	{
		cout << "文件复制失败" << endl;
	}
	
	return 0;
}

bool mp3cpy(const char* szDestFile, const char *szOrigFile)
{   //从原始文件读，写到目标文件 
	ofstream fout(szDestFile, ios::binary); //打开目标文件 
	ifstream fin(szOrigFile, ios::binary);  //打开原始文件
	
	bool bRet = true;
	if (fin.bad()) //原始文件出错 
	{
		bRet = false;
	} 
	else
	{
	    fin.seekg(0L, ios::beg); //定位原始文件开始位置
		while (!fin.eof()) //原始文件未结尾 
		{
		    char szBuf[256] = {0};
			fin.read(szBuf, sizeof(char) * 256);//读到缓存szBuf
			int length = fin.gcount();//实际读取的字节
			if (fout.bad()) //目标文件出错 
			{
			    bRet = false;
				break;	
			}
			fout.write(szBuf, length); //每次写入目标文件length个字节      	
		}			
	}
	fout.close();
	fin.close(); 
    
    return bRet;
}







