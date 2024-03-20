#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main(void)
{
	vector<char> wrd;
	
	int num;
	cin >> num;
	cin.ignore();
	int ng = 0;
	string str;
	string tmp;
	for(int i = 0; i < num; i++)
	{
		str.clear();
		tmp.clear();
		
		getline(cin, str);
		for(int j = 0; j < str.length(); j++)
		{
			if(j != 0)
			{
				if(str[j] != str[j-1] && tmp.find(str[j]) != string::npos)
				{
					ng++;
					break;
				}
			}
			tmp.append(1, str[j]);
		}
	}
	cout << num - ng << "\n";
	
}