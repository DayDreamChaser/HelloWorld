#include <iostream>
using namespace std;
int main()
{
    char s[15] = "Hello World!";
    int c[26] = {};
 
    // ��ĸһ�ɓQ��С��
    for (int i=0; s[i]; i++)
    {
    	if (s[i] >= 'A' && s[i] <= 'Z')
    	{
	    	s[i] = s[i] - 'A' + 'a';
	    }          
    }
        
    // �yӋ��ĸ����
    for (int i=0; s[i]; i++)
    {
    	if (s[i] >= 'a' && s[i] <= 'z')
    	{
	    	c[s[i] - 'a']++;
	    }
    }
        
    // ӡ���yӋ�Y��
    for (int i=0; i<26; i++)
    {
    	 cout << char('a'+i) << ':' << c[i] << '\n';
    }
       
	return 0;
}