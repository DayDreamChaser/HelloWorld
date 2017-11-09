//�˿����ϴ�ƽ�����浽�ļ� 

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
    string suit;  //��ɫ �ַ����� 
	string face;  //��ֵ 
};

class CardManager
{
 private:
    Card deck[SUIT_NUMBER][FACE_NUMBER];  // 4*13 = 52 ���˿���
 public:
    CardManager();    //���캯��
	void Shuffle();   //ϴ��
    void Deal();      //���� 
};
CardManager::CardManager()
{
	string suit[] = { "����", "����", "÷��", "����" };
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
void CardManager::Shuffle()  //ϴ��
{
	srand(time(NULL));
	for (int i=0; i<SUIT_NUMBER; i++)
    {
     	for (int j=0; j<FACE_NUMBER; j++)
     	{   // ������� 
	        int m = rand() % SUIT_NUMBER;
			int k = rand() % FACE_NUMBER;
			Card temp = deck[i][j];	
			deck[i][j] = deck[m][k];
			deck[m][k] = temp;
        }
    }
}
void CardManager::Deal() //����
{
	ofstream out("poke.txt"); // open the file
	if(!out)
	{
		cout << "failed to open the file!" << endl;
	}
	// wirte 
	out << "================" << endl;
	out << "52����ϴ�ƽ��" << endl;
	out << "================" << endl;
	string person[] = { "��", "��", "��", "��" };
	
	for (int i=0; i<SUIT_NUMBER; i++)
    {
    	out << person[i] << "���ƣ�" << endl;
     	for (int j=0; j<FACE_NUMBER; j++)
     	{   // ������� 
	        out << "��"<< j+i <<"��: " << deck[i][j].suit 
			<< deck[i][j].face << "\t\t";
			if ((j + 1) % 4 == 0)
			{
				out << endl; // ���� 
			}
        }
        out << endl << endl; 
    }
    out.close();  // �ر��ļ� 
    cout << "poke.txt was built,please check it!" << endl;
}
int main()
{
	CardManager cm;  // �˿˹��������
	cm.Shuffle();
	cm.Deal();
	 
	return 0;
}
