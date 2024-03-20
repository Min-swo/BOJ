#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main(void)
{
	string str;
	getline(cin, str);
	
	vector<string> crtn = {"c=", "c-", "dz=", "d-", "lj", "nj", "s=", "z="};
	
	string::size_type idx;
	for(int i = 0; i < crtn.size(); i++)
	{
		while(1)
		{
			idx = str.find(crtn[i]);
			if(idx == string::npos)
				break;
			str.replace(idx, crtn[i].length(), "#");
		}
	}
	cout << str.length() << "\n";
}