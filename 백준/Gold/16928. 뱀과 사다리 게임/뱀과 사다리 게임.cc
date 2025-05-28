#include <algorithm>
#include <iostream>
using namespace std;

#define MAX 101

int N, M;
int map[MAX];
int up[MAX];
int up2[MAX];
int down[MAX];
int dp[MAX];
int visited[MAX];
int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;

    for (int i = 0; i < MAX; i++) {
        up[i] = 0;
        up2[i] = 0;
        down[i] = 0;
        dp[i] = MAX;
        visited[i] = MAX;
    }

    int start, end;
    for (int i = 0; i < N; i++) {
        cin >> start >> end;
        up[end] = start;
        up2[start] = end;
    }
    for (int i = 0; i < M; i++) {
        cin >> start >> end;
        down[start] = end;
    }

    dp[1] = 0;
    for (int i = 2; i <= 100; i++) {
        int minVal = MAX;
        for (int k = 1; k <= 6 && i - k > 0; k++) {
            if (down[i - k] == 0 && up2[i - k] == 0) {
                minVal = min(minVal, dp[i - k] + 1);
            }
        }
        if (up[i] != 0) {
            minVal = min(minVal, dp[up[i]]);
        }

        dp[i] = min(minVal, dp[i]);

        if (down[i] != 0) {
            if (visited[i] != dp[i]) {
                visited[i] = dp[i];
                if (min(dp[down[i]], dp[i]) == dp[i]) {
                    dp[down[i]] = dp[i];
                    i = down[i];
                }
            }
        }
    }

    cout << dp[100] << "\n";
    return 0;
}