#include <iostream>
#include <vector>
using namespace std;

int main(void)
{
	int n, b;
	cin >> n >> b;
	
	vector<int> num;
	while(n != 0)
	{
		num.push_back(n % b);
		n = n / b;
	}
	
	for(int i = num.size()-1; i >= 0; i--)
	{
		if(num[i] > 9)
			cout << char(num[i]+55);
		else
			cout << char(num[i]+48);
	}
	cout << "\n";
}