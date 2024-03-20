#include <iostream>
using namespace std;

int main(void)
{
	int a, b, v;
	cin >> a >> b >> v;
	
	int d;
	int qnt, rem;
	qnt = (v - b) / (a - b);
	rem = (v - b) % (a - b);
	if(rem != 0)
	{
		d = qnt + 1;
	}
	else
	{
		d = qnt;
	}
	cout << d << "\n";
}