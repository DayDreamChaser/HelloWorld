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
void print_line(int n)  // m为一行的长度 
{
	for (int i=1; i<=n; i++) cout << '@';
	cout << endl; // cout << '\n';
}

void print_triangle(int n) // n为行数 
{
	for (int i=n; i>=1; i--) print_line(i); 
}
