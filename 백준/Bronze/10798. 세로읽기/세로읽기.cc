#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main(void)
{
	string str[15];
	string tmp;
	while(getline(cin, tmp))
	{
		//getline(cin, tmp);
		for(int i = 0; i < tmp.length(); i++)
		{
			str[i].append(1, tmp[i]);
		}
	}
	
	for(int i = 0; i < 15; i++)
	{
		cout << str[i];
	}
	cout << "\n";
	
}