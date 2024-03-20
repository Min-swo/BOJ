#include <iostream>
using namespace std;

int main(void)
{
	int n;
	cin >> n;
	
	int s = 1;
	int nmr = 1;
	int dnm;
	int wt;
	for(int i = 1; 1; i++)
	{
		s = s + i;
		if(n < s)
		{
			dnm = i;
			//cout << "i : " << i << "\n";
			wt = n - (s - i);
			nmr += wt;
			dnm -= wt;
			if(i % 2 == 0)
				cout << nmr << "/" << dnm << "\n";
			else
				cout << dnm << "/" << nmr << "\n";
			break;
		} 
	}
}