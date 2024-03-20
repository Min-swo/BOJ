#include <iostream>
#include <algorithm>
using namespace std;

#define MAX 1000000
#define DIV 1000000009
long long dp[MAX];
int* tc;
int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t, n, max;
    cin >> t;

    max = -1;
    tc = new int[t];
    for(int i = 0; i < t; i++)
    {    
        cin >> tc[i];
        if(max < tc[i])
            max = tc[i];
    }

    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 4;
    for(int i = 4; i <= max; i++)
        dp[i] = (dp[i-1] % DIV + dp[i-2] % DIV + dp[i-3] % DIV) % DIV;

    for(int i = 0; i < t; i++)
        cout << dp[tc[i]] << "\n";
    return 0;
}