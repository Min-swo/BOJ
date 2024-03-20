#include <iostream>
#include <string>
#include <stack>

using namespace std;

int main(void)
{
	string batch;
	getline(cin, batch);
	
	int ans = 0;
	stack<char> s;
	for(int i = 0; i < batch.size(); i++)
	{
		if(batch[i] == '(')
			s.push(batch[i]);
		else
		{
			s.pop();
			if(batch[i-1] == '(')
				ans = ans + s.size();
			else
				ans++;
		}
	}
	
	cout << ans << "\n";
}