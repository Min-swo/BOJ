#include <iostream>
#include <cmath>
using namespace std;


int diff(int* x, int a, int b, int c)
{
	if(x[a] == x[b])
		return x[c];
	else if(x[a] == x[c])
		return x[b];
	else
		return x[a];
}

int main(void)
{
	int x[3];
	int y[3];
	
	for(int i = 0; i < 3; i++)
		cin >> x[i] >> y[i];
	
	int a, b;
	a = diff(x, 0, 1, 2);
	b = diff(y, 0, 1, 2);
	
	cout << a << " " << b << "\n";
}