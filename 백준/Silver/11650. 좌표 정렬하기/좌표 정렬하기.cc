#include <iostream>
#include <algorithm>
using namespace std;

#define K 1000000

int main(void)
{
	int n;
	cin >> n;
	
	long long int* x_points = new long long int[n];
	long long int* y_points = new long long int[n];
	
	for(int i = 0; i < n; i++)
		cin >> x_points[i] >> y_points[i];
	
	long long int* weight_xy_sum = new long long int[n];
	for(int i = 0; i < n; i++)
	{
		weight_xy_sum[i] = x_points[i] * K + y_points[i];
		//cout << "Weight Sum: " << weight_xy_sum[i] << "\n";
	}
	
	sort(weight_xy_sum, weight_xy_sum + n);
	
	int x, y;
	for(int i = 0; i < n; i++)
	{
		x = weight_xy_sum[i] / K;
		y = weight_xy_sum[i] % K;
		// I) x > 0, y > 0 => x = w / K, y = w % K
		// II) x > 0, y < 0 => x = w / K + 1, y = w % K - K
		// III) x < 0, y > 0 => x = w / K - 1, y = w % K + K
		/// IV) x < 0, y < 0 => 
		
		if(y >= 0)
		{
			if(y > K / 2)
			{
				x = x + 1;
				y = y - K;
			}
		}
		else
		{
			if(y < K / 2 * -1)
			{
				x = x - 1;
				y = y + K;
			}
		}
		
		cout << x << " " << y << "\n";
	}
}