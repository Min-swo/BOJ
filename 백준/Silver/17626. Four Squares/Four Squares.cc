#include <cmath>
#include <iostream>
using namespace std;

#define MAX 50001

int N;
int dp[MAX];

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    for (int i = 0; i <= N; i++) {
        dp[i] = 5;
    }
    dp[0] = 0;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= sqrt(i); j++) {
            dp[i] = min(dp[i], dp[i - j * j] + 1);
        }
    }

    cout << dp[N] << "\n";
    return 0;
}