#include <iostream>
using namespace std;

#define N 

int main(void)
{
	int n;
	cin >> n;
	
	int rng = 2;
	for(int i = 0; 1; i++)
	{
		rng = rng + 6 * i;
		if(n < rng)
		{
			cout << i+1 << "\n";
			break;
		}
	}
}