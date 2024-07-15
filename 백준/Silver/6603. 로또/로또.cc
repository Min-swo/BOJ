#include <iostream>
#include <vector>
using namespace std;

int n;
int* num;

void dfs(int* num, int cur, vector<int> v)
{
    if(v.size() == 6)
    {
        for(int i = 0; i < v.size(); i++)
            cout << v[i] << " ";
        cout << "\n";
        return;
    }

    for(int i = cur+1; i <= n; i++)
    {
        v.push_back(num[i-1]);
        dfs(num, i, v);
        v.erase(v.end() - 1);
    }
    
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    while(1)
    {
        cin >> n;

        if(n == 0)
            break;
        
        num = new int[n];
        for(int i = 0; i < n; i++)
            cin >> num[i];
        
        vector<int> v;
        dfs(num, 0, v);

        delete[] num;
        cout << "\n";
    }


}