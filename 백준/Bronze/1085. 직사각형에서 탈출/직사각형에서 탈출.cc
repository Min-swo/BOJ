#include <iostream>
using namespace std;

int main(void)
{
	int x, y, w, h;
	cin >> x >> y >> w >> h;
	
	int a, b;
	if(x > w - x)
		a = w - x;
	else
		a = x;
	
	if(y > h - y)
		b = h - y;
	else
		b = y;
	
	if(a < b)
		cout << a << "\n";
	else
		cout << b << "\n";
}