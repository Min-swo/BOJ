#include <iostream>
using namespace std;

#define MAX 15
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
        if (i + times[i] <= N) {
            dp[i] = prices[i];
        } else {
            dp[i] = 0;
        }
    }

    int maxValue = dp[0];
    for (int i = 1; i < N; i++) {
        for (int j = i - 1; j >= 0; j--) {
            if (times[j] + j <= i) {
                int tmp = 0;
                if (i + times[i] <= N) {
                    tmp = dp[j] + prices[i];
                } else {
                    tmp = dp[j];
                }
                dp[i] = max(dp[i], tmp);
            }
        }
        maxValue = max(maxValue, dp[i]);
    }

    cout << maxValue << "\n";

    return 0;
}