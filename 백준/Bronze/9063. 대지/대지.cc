#include <iostream>
using namespace std;

#define N 100000
#define MAX 10001
#define MIN -10001

int main(void)
{
	int num;
	cin >> num;
	
	int x[N];
	int y[N];
	
	for(int i = 0; i < num; i++)
		cin >> x[i] >> y[i];
	
	int maxX = MIN;
	int maxY = MIN;
	int minX = MAX;
	int minY = MAX;
	
	for(int i = 0; i < num; i++)
	{
		if(maxX < x[i])
			maxX = x[i];
		if(maxY < y[i])
			maxY = y[i];
		if(minX > x[i])
			minX = x[i];
		if(minY > y[i])
			minY = y[i];
	}
	
	int w = (maxX - minX) * (maxY - minY);
	cout << w << "\n";
	
}