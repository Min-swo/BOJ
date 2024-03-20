#include <iostream>
#include <vector>
using namespace std;


int* stack;
int top;
vector<char> pushPopVector;
int* used;

void init(int n)
{
	stack = new int[n];
	top = -1;
	
	used = new int[n];
	for(int i = 0; i < n; i++)
		used[i] = 0;
}

void push(int a)
{
	stack[++top] = a;
	pushPopVector.push_back('+');
}

int pop()
{
	pushPopVector.push_back('-');
	return stack[top--];
}

int peek()
{
	return stack[top];
}

int size()
{
	return top+1;
}

void push_continually(int tmp)
{
	for(int i = 1; i <= tmp; i++)
	{
		if(!used[i])
		{
			used[i] = 1;
			push(i);
		}
	}
	pop();
}

int main(void)
{
	int n;
	cin >> n;
	
	init(n+1);
	
	int error = 0;
	int tmp;
	for(int i = 1; i <= n; i++)
	{
		cin >> tmp;
		if(!error)
		{
			if(size() == 0)
			push_continually(tmp);
			else
			{
				if(peek() == tmp)
					pop();
				else if(peek() < tmp)
					push_continually(tmp);
				else
				{
					error = 1;
				}
			}
		}
		
	}
	
	if(error)
		cout << "NO\n";
	else
	{
		for(int i = 0; i < pushPopVector.size(); i++)
			cout << pushPopVector[i] << "\n";
	}
}