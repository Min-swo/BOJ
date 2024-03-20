#include <iostream>
#include <stack>
#include <utility>
using namespace std;

int main(void)
{
	int n;
	cin >> n;
	
	int* ans = new int[n];
	
	int tmp;
	stack<pair<int, int>> seqStack;
	for(int i = 0; i < n; i++)
	{
		cin >> tmp;
		while(!seqStack.empty() && seqStack.top().first < tmp)
		{
			ans[seqStack.top().second] = tmp;
			seqStack.pop();
		}
		seqStack.push(make_pair(tmp, i));
	}
	while(!seqStack.empty())
	{
		ans[seqStack.top().second] = -1;
		seqStack.pop();
	}
	
	for(int i = 0; i < n; i++)
		cout << ans[i] << " ";
	cout << "\n";
}