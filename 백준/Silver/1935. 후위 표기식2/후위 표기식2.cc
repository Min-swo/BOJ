#include <iostream>
#include <iomanip>
#include <string>
#include <stack>
using namespace std;

int main(void)
{
	int n;
	cin >> n;
	cin.ignore();
	
	string postfix;
	getline(cin, postfix);
	
	double* operands = new double[n];
	for(int i = 0; i < n; i++)
		cin >> operands[i];
	
	int alpha = 65; double tmp1, tmp2;
	stack<double> calculate_stack;
	for(int i = 0; i < postfix.size(); i++)
	{
		if(postfix[i] == '*')
		{
			tmp2 = calculate_stack.top();
			calculate_stack.pop();
			tmp1 = calculate_stack.top();
			calculate_stack.pop();
			
			calculate_stack.push(tmp1 * tmp2);
		}
		else if(postfix[i] == '+')
		{
			tmp2 = calculate_stack.top();
			calculate_stack.pop();
			tmp1 = calculate_stack.top();
			calculate_stack.pop();
			
			calculate_stack.push(tmp1 + tmp2);
		}
		else if(postfix[i] == '-')
		{
			tmp2 = calculate_stack.top();
			calculate_stack.pop();
			tmp1 = calculate_stack.top();
			calculate_stack.pop();
			
			calculate_stack.push(tmp1 - tmp2);
		}
		else if(postfix[i] == '/')
		{
			tmp2 = calculate_stack.top();
			calculate_stack.pop();
			tmp1 = calculate_stack.top();
			calculate_stack.pop();
			
			calculate_stack.push(tmp1 / tmp2);
		}
		else
		{
			for(int j = 0; j < n; j++)
			{
				if(postfix[i] == alpha + j)
					calculate_stack.push(operands[j]);
			}
		}
	}
	//printf("%.2f\n", calculate_stack.top());
	cout.precision(2);
	cout << fixed << calculate_stack.top() << "\n";
}