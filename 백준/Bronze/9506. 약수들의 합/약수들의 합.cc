#include <iostream>
#include <vector>
using namespace std;

int main(void)
{
	int n;
	int sum;
	vector<int> v;
	while(1)
	{
		cin >> n;
		if(n == -1)
			break;
		
		v.clear();
		for(int i = 1; i < n; i++)
		{
			if(n % i == 0)
				v.push_back(i);
		}
		
		sum = 0;
		for(int i = 0; i < v.size(); i++)
			sum = sum + v[i];
		
		if(n == sum)
		{
			cout << n << " = ";
			for(int i = 0; i < v.size(); i++)
			{
				cout << v[i];
				if(i != v.size() - 1)
					cout << " + ";
			}
			cout << "\n";
		}
		else
		{
			cout << n << " is NOT perfect.\n";
		}		
	}
}