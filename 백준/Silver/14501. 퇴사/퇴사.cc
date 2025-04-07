#include <iostream>
using namespace std;

#define MAX 20
int prices[MAX];
int times[MAX];
int dp[MAX];
int N;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> times[i] >> prices[i];
        dp[i] = 0;
    }
    dp[N] = 0;

    int maxValue = 0;
    for (int i = N - 1; i >= 0; i--) {
        if (i + times[i] <= N) {
            dp[i] = max(prices[i] + dp[i + times[i]], dp[i + 1]);
        } else {
            dp[i] = dp[i + 1];
        }
        maxValue = max(maxValue, dp[i]);
    }

    cout << maxValue << "\n";
    return 0;
}