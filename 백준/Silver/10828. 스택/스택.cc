#include <iostream>
#include <string>
using namespace std;

int* stack;
int top;

void push(int data)
{
	stack[++top] = data;
}

void pop()
{
	if(top < 0)
		cout << -1 << "\n";
	else
		cout << stack[top--] << "\n";
}

void size()
{
	cout << top + 1 << "\n";
}

void empty()
{
	if(top == -1)
		cout << 1 << "\n";
	else
		cout << 0 << "\n";
}

void top_f()
{
	if(top == -1)
		cout << -1 << "\n";
	else
		cout << stack[top] << "\n";
}

void command(string cmd, int data)
{
	if(cmd == "push")
		push(data);
	else if(cmd == "pop")
		pop();
	else if(cmd == "size")
		size();
	else if(cmd == "empty")
		empty();
	else if(cmd == "top")
		top_f();
}

int main(void)
{
	int n;
	cin >> n;
	
	stack = new int[n];
	top = -1;
	
	string cmd;
	int data = 0;
	for(int i = 0; i < n; i++)
	{
		cin >> cmd;
		
		if(cmd == "push")
			cin >> data;
		
		command(cmd, data);
	}
	
}