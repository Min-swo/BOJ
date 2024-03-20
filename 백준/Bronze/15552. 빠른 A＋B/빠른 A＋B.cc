#include <iostream>
using namespace std;


int main(void)
{
	ios::sync_with_stdio(false); 
	cin.tie(NULL);
	
	int k;
	cin >> k;
	
	int a, b;
	for(int i = 0; i < k; i++)
	{
		cin >> a >> b;
		cout << a + b << "\n";
	}
	
	return 0;
}