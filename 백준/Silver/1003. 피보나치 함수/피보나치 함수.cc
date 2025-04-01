#include <iostream>
using namespace std;

#define MAX 41
int dp[MAX][2];

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t, n;
    cin >> t;

    dp[0][0] = 1;
    dp[0][1] = 0;

    dp[1][0] = 0;
    dp[1][1] = 1;
    for (int i = 2; i < MAX; i++) {
        dp[i][0] = dp[i - 1][0] + dp[i - 2][0];
        dp[i][1] = dp[i - 1][1] + dp[i - 2][1];
    }

    for (int i = 0; i < t; i++) {
        cin >> n;
        cout << dp[n][0] << " " << dp[n][1] << "\n";
    }

    return 0;
}