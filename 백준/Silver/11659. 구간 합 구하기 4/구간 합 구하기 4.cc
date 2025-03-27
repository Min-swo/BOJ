#include <iostream>
using namespace std;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M;
    cin >> N >> M;

    int arr[N];
    int dp[N];
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    dp[0] = arr[0];
    for (int i = 1; i < N; i++) {
        dp[i] = dp[i - 1] + arr[i];
    }

    int s, e;
    for (int i = 0; i < M; i++) {
        cin >> s >> e;
        cout << dp[e - 1] - dp[s - 1] + arr[s - 1] << "\n";
    }

    return 0;
}