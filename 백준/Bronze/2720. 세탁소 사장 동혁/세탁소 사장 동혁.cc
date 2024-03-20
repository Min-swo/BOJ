#include <iostream>
using namespace std;

int main(void)
{
	int n;
	cin >> n;
	
	int dr, qrt, dme, nkl, pny;
	for(int i = 0; i < n; i++)
	{
		cin >> dr;
		
		qrt = dr / 25;
		dr = dr % 25;
		
		dme = dr / 10;
		dr = dr % 10;
		
		nkl = dr / 5;
		dr = dr % 5;
		
		pny = dr;
		
		cout << qrt << " " << dme << " " << nkl << " " << pny << "\n";
	}
}