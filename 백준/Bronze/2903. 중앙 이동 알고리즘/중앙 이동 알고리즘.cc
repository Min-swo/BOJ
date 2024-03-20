#include <iostream>
#include <cmath>
using namespace std;

int main(void)
{
	int n;
	cin >> n;
	
	int rslt = 2;
	for(int i = 0; i < n; i++)
	{
		rslt = rslt + rslt - 1;
	}
	cout << rslt * rslt << "\n";
}