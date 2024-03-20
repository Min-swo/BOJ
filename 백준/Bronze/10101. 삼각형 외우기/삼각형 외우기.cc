#include <iostream>
using namespace std;

int isTri(int a, int b, int c)
{
	if(a + b + c == 180)
		return 1;
	return 0;		
}

int isEqu(int a, int b, int c)
{
	if(a == 60 && b == 60 && c == 60)
		return 1;
	return 0;
}

int isIso(int a, int b, int c)
{
	if(a == b || b == c || a == c)
		return 1;
	return 0;
}

int main(void)
{
	int a, b, c;
	cin >> a >> b >> c;
	
	if(!isTri(a, b, c))
		cout << "Error\n";
	else
	{
		if(isEqu(a, b, c))
			cout << "Equilateral\n";
		else if(isIso(a, b, c))
			cout << "Isosceles\n";
		else
			cout << "Scalene\n";
	}
	
}