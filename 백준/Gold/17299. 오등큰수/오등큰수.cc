#include <iostream>
#include <stack>
#include <utility>
using namespace std;

#define K 1000000
int count[K];

int main(void)
{
	int n;
	cin >> n;
	
	int* originalSeq = new int[n];
	
	
	for(int i = 0; i < K; i++)
		count[i] = 0;
	for(int i = 0; i < n; i++)
	{
		cin >> originalSeq[i];
		count[originalSeq[i]]++;
	}
	
	int* answer = new int[n];
	stack<pair<int, int>> seqStack;
	for(int i = 0; i < n; i++)
	{
		while(!seqStack.empty() && count[seqStack.top().first] < count[originalSeq[i]])
		{
			answer[seqStack.top().second] = originalSeq[i];
			seqStack.pop();
		}
		seqStack.push(make_pair(originalSeq[i], i));
	}
	while(!seqStack.empty())
	{
		answer[seqStack.top().second] = -1;
		seqStack.pop();
	}
	
	for(int i = 0; i < n; i++)
		cout << answer[i] << " ";
	cout << "\n";
}