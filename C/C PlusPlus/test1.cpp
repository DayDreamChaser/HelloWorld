#include <iostream>
using namespace std;

void print_line(int n);
void print_triangle(int n);
int main()
{
	int n;
	cout << "Please input the number of the line:" << endl;
	cin >> n;
	print_triangle(n);
	
	return 0;
}
void print_line(int n)  // mΪһ�еĳ��� 
{
	for (int i=1; i<=n; i++) cout << '@';
	cout << endl; // cout << '\n';
}

void print_triangle(int n) // nΪ���� 
{
	for (int i=n; i>=1; i--) print_line(i); 
}
