#include <iostream>
#include <queue>
using namespace std;

int N, M;
int map[300][300];
int visited[300][300];

queue<pair<int, int>> q;
int dX[2] = {1, 0};
int dY[2] = {0, 1};

int isSafe(int x, int y) {
    if (x < 0 || M <= x) {
        return false;
    }
    if (y < 0 || N <= y) {
        return false;
    }
    if (map[x][y] == 0) {
        return false;
    }
    if (visited[x][y]) {
        return false;
    }
    return true;
}

int bfs(pair<int, int> start, pair<int, int> end) {
    int endX = end.first;
    int endY = end.second;

    q.push(start);

    while (!q.empty()) {
        pair<int, int> cur = q.front();
        q.pop();
        int x = cur.first;
        int y = cur.second;

        if (x == endX && y == endY) {
            return 1;
        }

        for (int i = 0; i < 2; i++) {
            int newX = x + dX[i];
            int newY = y + dY[i];

            if (isSafe(newX, newY)) {
                visited[newX][newY] = 1;
                q.push({newX, newY});
            }
        }
    }
    return 0;
}

int main(void) {
    cin >> N >> M;
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            cin >> map[i][j];
            visited[i][j] = 0;
        }
    }

    string ans = bfs({0, 0}, {M - 1, N - 1}) ? "Yes" : "No";
    cout << ans << "\n";
}