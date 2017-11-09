
#include <iostream>
#include <string.h>
using namespace std;
// 定义两个全局字符指针数组，存取所需的单词
// num1中1到19，空出了0，所以可以直接用num1[0]调用，得到n对应单词
static char *num1[]=
{
	"","one ","two ","three ","four ","six ","seven ","eight ","nine ","ten ","eleven ","twelve ",
	"thirteen ","fourteen ","fifteen ","sixteen ","seventeen ","eighteen ","nineteen "
};
// num10中卫-90，空出了和，所以可以直接用num10[n/10]调用，得到n对应单词
static char *num10[]=
{
	"","","twenty ","thirty ","forty ","fifty ","sixty ","seventy ","eighty ","ninety "
};
class robot
{
     private:	
         char name[20];  //  the name of robot
         char type[20];  //  机器人型号
		 int num;        //  待翻译的整数
		 char *ps;       // 指向英文字符串
	 public:
	     robot()  // 构造函数
		 {
 		     strcpy(name,"xxxxxx");
			 strcpy(type,"xxxxxx");
			 num = 0;
			 ps = new char[5];  //动态分配一个数组
			 strcpy(ps,"zero");	
 	   	 } 
 	   	 void set(char n[], char t[], int m);   //设置修改数据
		 char *out(int a); // 英文中每三位数读法相同，所以定义out函数翻译小于1000的数
		 char *tran_int(int n); // 将整个整数翻译为英文句子 
		 void print_num(); // 输出整数及其英文句子
		 ~robot()   // 析构函数 
	 	{
 		    cout << "堆区中" << strlen(ps) + 1 << "个字节空间释放收回" << endl;
		    delete [] ps;	
 		}    
};
void robot::set(char n[], char t[], int m)   //设置修改数据
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
     	 strcpy(ps,"负数不能翻译"); 
     }
 	   	
}
void robot::print_num()
{
	cout << "整数为：" << num << endl;
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
	// 若百位不为零,输出百位数加hundred,若此时十位个位均为0,不加and 
	if(a/100 != 0) 	{
		 strcat(k,num1[a/100]);
		 strcat(k,"hundred ");
		 if(b != 0) {
             strcat(k,"and ");
	     } 
    } 
	if(b < 20) {             // 当后两位在20以内，直接调用num1[n] 
	     strcat(k,num1[b]);
	} else {
    	 strcat(k,num10[b/10]);
	 	 if(b%10 != 0) {          // b%10为个位数，判断是否为0 
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
    	strcpy(kk,"无法处理太大的数！\n"); 
    } else {
    	int a = n /1000000000, b = (n % 1000000000)/1000000, c = (n % 100000)/1000, d = n % 1000;
    	// 当abcd不为零的时候，输出加上billion,million,thousand
    	if(a != 0) {
	    	p = out(a);
	    	strcpy(kk,p);
	    	strcat(kk,"billion ");
	    	delete [] p;  // 释放在out函数中动态申请的空间 
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
