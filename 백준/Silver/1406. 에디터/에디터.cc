#include <iostream>
#include <string>
using namespace std;

#define K 600000

class Stack{
	private:
	char* data;
	int top;

	public:
	void init()
	{
		data = new char[K];
		top = -1;
	}
	
	char pop()
	{
		return data[top--];
	}
	
	void push(char a)
	{
		data[++top] = a;
	}
	
	int isEmpty()
	{
		if(top >= 0)
			return 0;
		return 1;
	}
	
	void printStack(int reverse)
	{
		if(reverse)
		{
			for(int i = top; i >= 0; i--)
				cout << data[i];
		}
		else
		{
			for(int i = 0; i <= top; i++)
				cout << data[i];
		}
		
	}
};


int main(void)
{
	string str;
	getline(cin, str);
	
	Stack leftStack, rightStack;
	leftStack.init();
	rightStack.init();
	
	for(int i = 0; i < str.size(); i++)
		leftStack.push(str[i]);
	
	int n;
	cin >> n;
	
	char cmd, d;
	for(int i = 0; i < n; i++)
	{
		cin >> cmd;
		switch(cmd)
		{
			case 'L':
				if(!leftStack.isEmpty())
					rightStack.push(leftStack.pop());
				break;
			case 'D':
				if(!rightStack.isEmpty())
					leftStack.push(rightStack.pop());
				break;
			case 'B':
				if(!leftStack.isEmpty())
					leftStack.pop();
				break;	
			case 'P':
				cin >> d;
				leftStack.push(d);
				break;
			default:
				break;	
		}
		
		// cout << "\nLeft Stack : ";
		// leftStack.printStack(0);
		// cout << "\nRight Stack : ";
		// rightStack.printStack(1);
		// cout << "\n";
	}
	
	leftStack.printStack(0);
	rightStack.printStack(1);
	cout << "\n";
}