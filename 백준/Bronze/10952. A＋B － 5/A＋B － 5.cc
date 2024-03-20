#include <iostream>
using namespace std;


int main(void)
{
	ios::sync_with_stdio(false); 
	cin.tie(NULL);
	
	while(1)
	{
		int a, b;
		cin >> a >> b;
		
		int res = a + b;
		if(res == 0)
			break;
		
		cout << res << "\n";
	}
	
	return 0;
}