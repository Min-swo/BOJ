#include <iostream>
#include <stack>
using namespace std;

#define MAX 500
int M, N;

int map[MAX][MAX];
int dp[MAX][MAX];
stack<pair<int, int>> s;

int dX[4] = {1, 0, -1, 0};
int dY[4] = {0, 1, 0, -1};

bool isSafe(int x, int y, int height) {
    if (x < 0 || M <= x) {
        return false;
    }
    if (y < 0 || N <= y) {
        return false;
    }
    if (map[x][y] >= height) {
        return false;
    }
    return true;
}

int recursive_dfs(pair<int, int> cur, pair<int, int> end) {
    int curX = cur.first;
    int curY = cur.second;

    if (dp[curX][curY] != -1) {
        return dp[curX][curY];
    }

    if (cur == end) {
        return 1;
    }

    dp[curX][curY] = 0;
    for (int i = 0; i < 4; i++) {
        int newX = curX + dX[i];
        int newY = curY + dY[i];

        if (isSafe(newX, newY, map[curX][curY])) {
            dp[curX][curY] += recursive_dfs({newX, newY}, end);
        }
    }

    return dp[curX][curY];
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> M >> N;
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            cin >> map[i][j];
            dp[i][j] = -1;
        }
    }

    recursive_dfs({0, 0}, {M - 1, N - 1});
    cout << dp[0][0] << "\n";
    return 0;
}