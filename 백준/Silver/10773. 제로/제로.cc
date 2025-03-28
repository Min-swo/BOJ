#include <iostream>
using namespace std;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int K;
    cin >> K;
    int dp[K + 1];

    int tmp;
    cin >> tmp;
    dp[0] = 0;
    dp[1] = tmp;

    int idx = 2;
    for (int i = 2; i < K + 1; i++) {
        cin >> tmp;
        if (tmp != 0) {
            dp[idx] = dp[idx - 1] + tmp;
            idx++;
        } else {
            idx--;
        }
    }

    cout << dp[idx - 1];
    return 0;
}