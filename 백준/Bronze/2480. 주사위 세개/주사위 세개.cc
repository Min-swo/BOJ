#include <iostream>
using namespace std;

int main(void)
{
	int arr[3];
	cin >> arr[0] >> arr[1] >> arr[2];
	
	int res;
	if (arr[0] == arr[1] && arr[1] == arr[2])
		res = 10000 + arr[0] * 1000;
	else if (arr[0] == arr[1] || arr[1] == arr[2])
		res = 1000 + arr[1] * 100;
	else if (arr[0] == arr[2])
		res = 1000 + arr[0] * 100;
	else
	{
		int max = 0;
		for(int i = 0; i < 3; i++)
		{
			if(max < arr[i])
				max = arr[i];
		}
		res = max * 100;
	}
	cout << res;
	
	return 0;
}