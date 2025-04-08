#include <algorithm>
#include <iostream>
using namespace std;

int N;
int main(void) {
    cin >> N;
    int time[N];
    int dp[N];

    for (int i = 0; i < N; i++) {
        cin >> time[i];
    }

    sort(time, time + N);
    dp[0] = time[0];
    for (int i = 1; i < N; i++) {
        dp[i] = dp[i - 1] + time[i];
    }

    int sum = 0;
    for (int i = 0; i < N; i++) {
        sum += dp[i];
    }

    cout << sum << "\n";
    return 0;
}