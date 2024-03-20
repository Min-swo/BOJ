#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int* seq;
int* dp;
vector<int>* v;

bool compare(vector<int> a, vector<int> b)
{
	return a.size() < b.size();
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, tmp;
    cin >> n;

    seq = new int[n];
    dp = new int[n];
    v = new vector<int>[n];
    for(int i = 0; i < n; i++)
        cin >> seq[i];
    for(int i = 0; i < n; i++)
        dp[i] = 1;
    for(int i = 0; i < n; i++)
        v[i].push_back(seq[i]);
    int max, idx;
    for(int i = n - 2; i >= 0; i--)
    {
        max = -1;
        for(int j = i + 1; j < n; j++)
        {
            if(seq[i] < seq[j])
            {
                tmp = dp[j] + 1;
                if(max < tmp)
                {
                    max = tmp;
                    idx = j;
                }
            }
        }
        if(max != -1)
        {
            dp[i] = max;
            for(int k = 0; k < v[idx].size(); k++)
                v[i].push_back(v[idx][k]);
        }

    }

    // for(int i = 0; i < n; i++)
    // {
    //     for(int j = 0; j < v[i].size(); j++)
    //     {
    //         cout << v[i][j] << " ";
    //     }
    //     cout << "\n";
    // }

    sort(dp, dp + n);
    sort(v, v + n, compare);
    // for(int i = 0; i < n; i++)
    //     cout << dp[i] << " ";
    // cout << "\n";
    cout << dp[n-1] << "\n";
    for(int i = 0; i < v[n-1].size(); i++)
        cout << v[n-1][i] << " ";
    cout << "\n";
}