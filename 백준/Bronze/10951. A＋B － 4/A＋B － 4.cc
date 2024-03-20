#include <iostream>
using namespace std;


int main(void)
{
	ios::sync_with_stdio(false); 
	cin.tie(NULL);
	
	int a, b;
	while(1)
	{
		if((cin >> a >> b).eof())
			break;
		cout << a+b << "\n";
	}
	
	return 0;
}