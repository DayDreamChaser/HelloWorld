//扑克随机洗牌结果保存到文件 

#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;
#define SUIT_NUMBER 4
#define FACE_NUMBER 13

class Card
{ 	
 public:
    string suit;  //花色 字符串型 
	string face;  //面值 
};

class CardManager
{
 private:
    Card deck[SUIT_NUMBER][FACE_NUMBER];  // 4*13 = 52 张扑克牌
 public:
    CardManager();    //构造函数
	void Shuffle();   //洗牌
    void Deal();      //发牌 
};
CardManager::CardManager()
{
	string suit[] = { "红桃", "方块", "梅花", "黑桃" };
	string face[] = { "A", "2", "3", "4", "5", "6", "7",
     "8", "9", "10", "J", "Q", "K" };
     
     for (int i=0; i<SUIT_NUMBER; i++)
     {
     	for (int j=0; j<FACE_NUMBER; j++)
     	{
	        deck[i][j].suit = suit[i];
			deck[i][j].face = face[j];	
        }
     }
}
void CardManager::Shuffle()  //洗牌
{
	srand(time(NULL));
	for (int i=0; i<SUIT_NUMBER; i++)
    {
     	for (int j=0; j<FACE_NUMBER; j++)
     	{   // 随机交换 
	        int m = rand() % SUIT_NUMBER;
			int k = rand() % FACE_NUMBER;
			Card temp = deck[i][j];	
			deck[i][j] = deck[m][k];
			deck[m][k] = temp;
        }
    }
}
void CardManager::Deal() //发牌
{
	ofstream out("poke.txt"); // open the file
	if(!out)
	{
		cout << "failed to open the file!" << endl;
	}
	// wirte 
	out << "================" << endl;
	out << "52张牌洗牌结果" << endl;
	out << "================" << endl;
	string person[] = { "甲", "乙", "丙", "丁" };
	
	for (int i=0; i<SUIT_NUMBER; i++)
    {
    	out << person[i] << "的牌：" << endl;
     	for (int j=0; j<FACE_NUMBER; j++)
     	{   // 随机交换 
	        out << "第"<< j+i <<"张: " << deck[i][j].suit 
			<< deck[i][j].face << "\t\t";
			if ((j + 1) % 4 == 0)
			{
				out << endl; // 换行 
			}
        }
        out << endl << endl; 
    }
    out.close();  // 关闭文件 
    cout << "poke.txt was built,please check it!" << endl;
}
int main()
{
	CardManager cm;  // 扑克管理类对象
	cm.Shuffle();
	cm.Deal();
	 
	return 0;
}
