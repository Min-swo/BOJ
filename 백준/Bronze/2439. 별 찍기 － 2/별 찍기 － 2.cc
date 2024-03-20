#include <iostream>
using namespace std;


int main(void)
{
	ios::sync_with_stdio(false); 
	cin.tie(NULL);
	
	int k;
	cin >> k;
	
	for(int i = 1; i < k+1; i++)
	{
		for(int n = 0; n < k-i; n++)
			cout << " ";
			
		for(int j = 0; j < i; j++)
			cout << "*";
		
		cout << "\n";
	}
	
	return 0;
}