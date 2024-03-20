#include <iostream>
#include <string>
using namespace std;
#define K 50

char ps[K];
int top;

int size()
{
	return top+1;
}

char peek()
{
	if(top < 0)
		return '\0';
	return ps[top];
}

void pop()
{
	if(top < 0)
		return;
	top--;
}

void push(char p)
{
	ps[++top] = p;
}

int main(void)
{
	int n;
	cin >> n;
	cin.ignore();
	
	string tmp;
	for(int i = 0; i < n; i++)
	{
		getline(cin, tmp);
		top = -1;
		for(int j = 0; j < tmp.size(); j++)
		{
			if(tmp[j] == ')' && peek() == '(')
					pop();
				else
					push(tmp[j]);	
		}
		if(size())
			cout << "NO\n";
		else
			cout << "YES\n";
	}
}