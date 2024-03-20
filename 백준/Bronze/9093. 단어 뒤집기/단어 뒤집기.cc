#include <iostream>
using namespace std;
#define K 1100

char stack[K];
int top;

int main(void)
{
	int n;
	cin >> n;
	cin.ignore();
	
	int len;
	string str;
	for(int i = 0; i < n; i++)
	{
		getline(cin, str);
		len = str.size();
		
		top = -1;
		for(int j = 0; j < len; j++)
		{
			if(str[j] == ' ')
			{
				while(top >= 0)
					cout << stack[top--];
				cout << " ";
			}
			else
				stack[++top] = str[j];
		}
		while(top >= 0)
					cout << stack[top--];
		cout << "\n";
	}
	
}