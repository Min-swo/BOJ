#include <iostream>
using namespace std;

int factor(int a, int b)
{
	if(b % a == 0)
		return 1;
	return 0;
}

int multiple(int a, int b)
{
	if(a % b == 0)
		return 1;
	return 0;
}

void sol(int a, int b)
{
	if(factor(a, b))
		cout << "factor" << "\n";
	else if(multiple(a, b))
		cout << "multiple" << "\n";
	else
		cout << "neither" << "\n";
}


int main(void)
{
	int a, b;
	while(1)
	{
		cin >> a >> b;
		if(a == 0 && b == 0)
			break;
		
		sol(a, b);
	}
}