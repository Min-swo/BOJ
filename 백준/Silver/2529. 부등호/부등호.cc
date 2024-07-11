#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int k;
    cin >> k;

    int num[10];
    for(int i = 0; i < 10; i++)
        num[i] = 0;

    int* min = new int[k+1];
    int* max = new int[k+1];

    char tmp;
    vector<char> v;
    for(int i = 0; i < k; i++)
    {
        cin >> tmp;
        v.push_back(tmp);
    }

    int idx = 0;
    int max_num = 9;
    stack<int> max_stack;
    for(int i = 0; i < v.size(); i++)
    {
        max_stack.push(max_num--);
        if(v[i] == '>')
        {
            if(!max_stack.empty())
            {
                for(int j = max_stack.size(); j > 0; j--)
                {
                    max[idx++] = max_stack.top();
                    max_stack.pop();
                }
            }
        }
    }

    if(!max_stack.empty())
    {
        max_stack.push(max_num--);
        for(int j = max_stack.size(); j > 0; j--)
        {
            max[idx++] = max_stack.top();
            max_stack.pop();
        }
    }
    else
    {
        max[idx++] = max_num--;
    }
    
    for(int i = 0; i < k+1; i++)
        cout << max[i];
    cout << "\n";
    

    idx = 0;
    int min_num = 0;
    stack<int> min_stack;
    for(int i = 0; i < v.size(); i++)
    {
        min_stack.push(min_num++);
        if(v[i] == '<')
        {
            if(!min_stack.empty())
            {
                for(int j = min_stack.size(); j > 0; j--)
                {
                    min[idx++] = min_stack.top();
                    min_stack.pop();
                }
            }
        }
    }
    if(!min_stack.empty())
    {
        min_stack.push(min_num++);
        for(int j = min_stack.size(); j > 0; j--)
        {
            min[idx++] = min_stack.top();
            min_stack.pop();
        }
    }
    else
    {
        min[idx++] = min_num++;
    }

    for(int i = 0; i < k+1; i++)
        cout << min[i];
    cout << "\n";

    return 0;
}