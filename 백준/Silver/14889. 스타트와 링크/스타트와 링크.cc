#include <iostream>
#include <vector>
using namespace std;

int n;
int** stat;
int minVal = 100 * 20 * 20;
vector<int> v1;
vector<int> v2;

void dfs(int idx)
{
    if(idx == n)
    {
        int sum1 = 0; int sum2 = 0;

        for(int i : v1)
            for(int j : v1)
                sum1 += stat[i][j];

        for(int i : v2)
            for(int j : v2)
                sum2 += stat[i][j];

        minVal = min(minVal, abs(sum1 - sum2));
        return;
    }

    if(v1.size() < n/2)
    {
        v1.push_back(idx);
        dfs(idx+1);
        v1.pop_back();
    }
    if(v2.size() < n/2)
    {
        v2.push_back(idx);
        dfs(idx+1);
        v2.pop_back();
    }
    
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;

    stat = new int*[n];
    for(int i = 0; i < n; i++)
        stat[i] = new int[n];

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
            cin >> stat[i][j];
    }

    dfs(0);
    cout << minVal << "\n";

    return 0;
}