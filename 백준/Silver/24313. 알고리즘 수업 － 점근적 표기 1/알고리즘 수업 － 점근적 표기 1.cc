#include <iostream>
#include <vector>
using namespace std;

int main(void)
{
	int a1, a0;
	int c;
	int n0;
	
	cin >> a1 >> a0;
	cin >> c >> n0;
	
	int k = 0;
	int tmp = c - a1;
	if(tmp > 0)
	{
		if(n0 >= a0 / tmp)
			k = 1;
	}
	else if(tmp < 0)
	{
		
	}
	else
	{
		if(a0 <= 0)
			k = 1;
	}
	
	cout << k << "\n";
}