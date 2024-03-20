#include <iostream>
#include <string>
#include <stack>
using namespace std;

stack<char> s;

void popAll()
{
	while(!s.empty())
	{
		cout << s.top();
		s.pop();
	}
}

int main(void)
{
	string str;
	getline(cin, str);
	
	char data;
	int angleBraketOpen = 0;
	for(int i = 0; i < str.size(); i++)
	{
		data = str[i];
		if(data == '<')
		{
			popAll();
			angleBraketOpen = 1;
			cout << data;
		}
		else if(data == '>')
		{
			angleBraketOpen = 0;
			cout << data;
		}
		else if(angleBraketOpen)
		{
			cout << data;
		}
		else if(data == ' ')
		{
			popAll();
			cout << " ";
		}
		else
		{
			s.push(data);
		}
	}
	popAll();
}