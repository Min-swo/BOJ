#include <iostream>
using namespace std;

int main(void)
{
	int total;
	cin >> total;
	
	int cnt;
	cin >> cnt;
	
	int sum = 0;
	int a, b;
	for(int i = 0; i < cnt; i++)
	{
		cin >> a >> b;
		sum = sum + a * b;
	}
	
	if(sum == total)
		cout << "Yes";
	else
		cout << "No";
	
	return 0;
}