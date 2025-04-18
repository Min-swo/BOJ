#include <iostream>
using namespace std;

#define MAX 101
unsigned long long dp[MAX];

int T, n;
int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    dp[1] = 1;
    dp[2] = 1;
    dp[3] = 1;
    dp[4] = 2;
    dp[5] = 2;

    int maxIdx = 5;
    cin >> T;
    for (int i = 0; i < T; i++) {
        cin >> n;
        if (n > maxIdx) {
            for (int i = maxIdx + 1; i <= n; i++) {
                dp[i] = dp[i - 1] + dp[i - 5];
            }
            maxIdx = n;
        }
        cout << dp[n] << "\n";
    }
    return 0;
}