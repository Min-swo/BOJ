#include <iostream>
using namespace std;

int main(void)
{
	int num;
	int max = -1;
	int x, y;
	for(int i = 0; i < 9; i++)
	{
		for(int j = 0; j < 9; j++)
		{
			cin >> num;
			if(max < num)
			{
				max = num;
				x = i;
				y = j;
			}
		}
	}
	
	cout << max << "\n" << x+1 << " " << y+1 << "\n";
}