
#include <iostream>
#include <string.h>
using namespace std;
// ��������ȫ���ַ�ָ�����飬��ȡ����ĵ���
// num1��1��19���ճ���0�����Կ���ֱ����num1[0]���ã��õ�n��Ӧ����
static char *num1[]=
{
	"","one ","two ","three ","four ","six ","seven ","eight ","nine ","ten ","eleven ","twelve ",
	"thirteen ","fourteen ","fifteen ","sixteen ","seventeen ","eighteen ","nineteen "
};
// num10����-90���ճ��˺ͣ����Կ���ֱ����num10[n/10]���ã��õ�n��Ӧ����
static char *num10[]=
{
	"","","twenty ","thirty ","forty ","fifty ","sixty ","seventy ","eighty ","ninety "
};
class robot
{
     private:	
         char name[20];  //  the name of robot
         char type[20];  //  �������ͺ�
		 int num;        //  �����������
		 char *ps;       // ָ��Ӣ���ַ���
	 public:
	     robot()  // ���캯��
		 {
 		     strcpy(name,"xxxxxx");
			 strcpy(type,"xxxxxx");
			 num = 0;
			 ps = new char[5];  //��̬����һ������
			 strcpy(ps,"zero");	
 	   	 } 
 	   	 void set(char n[], char t[], int m);   //�����޸�����
		 char *out(int a); // Ӣ����ÿ��λ��������ͬ�����Զ���out��������С��1000����
		 char *tran_int(int n); // ��������������ΪӢ�ľ��� 
		 void print_num(); // �����������Ӣ�ľ���
		 ~robot()   // �������� 
	 	{
 		    cout << "������" << strlen(ps) + 1 << "���ֽڿռ��ͷ��ջ�" << endl;
		    delete [] ps;	
 		}    
};
void robot::set(char n[], char t[], int m)   //�����޸�����
{
	 strcpy(name,n);
	 strcpy(type,t);
	 if(num == m) {
 		 return;
     } else {
     	 num = m;
     	 delete [] ps;
     } if(num > 0) {
         char *tp = tran_int(num);
   	     ps = new char[strlen(tp) + 1];
   	     strcpy(ps,tp);
   	     delete []tp;
     } else if( num == 0) {
     	 ps = new char[5];
     	 strcpy(ps,"zero");
     } else {
     	 ps = new char[13];
     	 strcpy(ps,"�������ܷ���"); 
     }
 	   	
}
void robot::print_num()
{
	cout << "����Ϊ��" << num << endl;
	if(ps == NULL) {
		 cout << "zero" << endl;
	}  else {
		 cout << ps << endl;
	}
}
char *robot::out(int a)
{
	char k[1000] = "";
	int b = a%100;
	// ����λ��Ϊ��,�����λ����hundred,����ʱʮλ��λ��Ϊ0,����and 
	if(a/100 != 0) 	{
		 strcat(k,num1[a/100]);
		 strcat(k,"hundred ");
		 if(b != 0) {
             strcat(k,"and ");
	     } 
    } 
	if(b < 20) {             // ������λ��20���ڣ�ֱ�ӵ���num1[n] 
	     strcat(k,num1[b]);
	} else {
    	 strcat(k,num10[b/10]);
	 	 if(b%10 != 0) {          // b%10Ϊ��λ�����ж��Ƿ�Ϊ0 
		     strcat(k,"\b-");
		     strcat(k,num1[b%10]);   
		 }
	}
	char *p = new char[strlen(k) + 1];
	strcpy(p,k);
    return p;			
} 
char *robot::tran_int(int n)
{
    char *p;
    char kk[1000] = "";
    if(n > 1999999999) {
    	strcpy(kk,"�޷�����̫�������\n"); 
    } else {
    	int a = n /1000000000, b = (n % 1000000000)/1000000, c = (n % 100000)/1000, d = n % 1000;
    	// ��abcd��Ϊ���ʱ���������billion,million,thousand
    	if(a != 0) {
	    	p = out(a);
	    	strcpy(kk,p);
	    	strcat(kk,"billion ");
	    	delete [] p;  // �ͷ���out�����ж�̬����Ŀռ� 
	    }
	    if(b != 0) {
    		p = out(b);
    		strcat(kk,p);
			strcat(kk,"million ");
    		delete [] p;  
    	} 
    	if(c != 0) {
	    	p = out(c);
	    	strcat(kk,p);
	    	strcat(kk,"thousand ");
   		    delete [] p; 
	    }
	    if(d != 0) {
    		if(d<100 && (a!=0 || b!=0 || c!=0)){
		    	strcat(kk,"and ");
		    }
		    p = out(d);
		    strcat(kk,p);
		    delete [] p;
    	}   	
    }
	p = new char[strlen(kk) + 1];
	strcpy(p,kk);
    return p;
}
int main()
{
	robot brown;
	brown.print_num();
	int n;
	cout << "Please input n: ";
	cin >> n;
	brown.set("brown","800#",n);
	brown.print_num();
	
	return 0;
}
