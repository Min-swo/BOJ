#include <iostream>
using namespace std;

int main(void)
{
	ios::sync_with_stdio(false); 
	cin.tie(NULL);
	
	int n;
	cin >> n;
	
	int tmp;
	int max = 0;
	int sum = 0;
	for(int i = 0; i < n; i++)
	{
		cin >> tmp;
		if(max < tmp)
			max = tmp;
		sum = sum + tmp;
	}
	
 	double avg = double(sum * 100) / double(max * n);
	
	cout << avg;
	return 0;
}