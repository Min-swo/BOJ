#include <iostream>
using namespace std;

#define MAX 100001
#define DIV 9901

long long dp[MAX];
/*
[0] -> 1
[1] -> n
[2] ->'

0 0
0 0
0 0
0 0 

dp[4]
4 => dp[3][3]
3 => dp[3][3] + dp[3][2] - dp[2][2] + dp[2][2] * 2
2 => dp[3][2] + dp[3][1] - dp[2][1] + dp[2][1] * 2
1 => dp[3][1] + dp[3][0] - dp[2][0] + dp[2][0] * 2
0 => 1
=> (dp[3][3] + dp[3][2] + dp[3][1]) * 2 + dp[2][2] + dp[2][1] + dp[2][0]
=> dp[3] * 2 + dp[2]


0 0
0 0
0 0
dp[3]
0 => 1
1 => dp[2][1] + dp[2][0] + dp[1][0]

*/
int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n;
    cin >> n;
 
    dp[1] = 3;
    dp[2] = 7;

    for(int i = 3; i <= n; i++)
        dp[i] = ((dp[i-1] * 2) % DIV + dp[i-2] % DIV) % DIV;

    cout << dp[n] << "\n";
    return 0;
}