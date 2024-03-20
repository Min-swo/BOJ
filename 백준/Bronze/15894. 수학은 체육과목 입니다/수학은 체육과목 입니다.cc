#include <iostream>
using namespace std;

int main(void)
{
	long long int n;
	cin >> n;
	
	long long int dup = n * (n-1) / 2;
	long long int sqr = n * (n+1) / 2;
	
	long long int wd = 4 * (sqr - dup);
	
	cout << wd << "\n";
}