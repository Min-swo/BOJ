#include <iostream>
#include <string>
#include <stdlib.h>
using namespace std;

int ChangeIdx(int ch)
{
	if(ch >= 97)
		return ch - 97;
	else
		return ch - 65;
}


int main(void)
{
	ios::sync_with_stdio(false); 
	cin.tie(NULL);

	int c;
	cin >> c;
	
	int n, k, sum;
	double avg;
	for(int i = 0; i < c; i++)
	{
		cin >> n;
		
		int* scrs = new int[n];
		for(int j = 0; j < n; j++)
			cin >> scrs[j];
		
		sum = 0;
		for(int i = 0; i < n; i++)
			sum = sum + scrs[i];
			
		avg = double(sum) / n;
		
		k = 0;
		for(int i = 0; i < n; i++)
		{
			if(scrs[i] > avg)
				k++;
		}
		
		double res = double(double(k) / n * 100);
		
		cout << fixed;
    	cout.precision(3);
		cout << res << "%\n";
		
		delete scrs;
	}
	
	return 0;
}