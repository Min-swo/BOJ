#include <iostream>
#include <queue>
using namespace std;

int N, M;
char map[100][100];
int visited[100][100];

queue<pair<pair<int, int>, int>> q;
int dX[4] = {1, 0, -1, 0};
int dY[4] = {0, 1, 0, -1};

bool isSafe(int x, int y) {
    if (x < 0 || N <= x) {
        return false;
    }
    if (y < 0 || M <= y) {
        return false;
    }
    if (map[x][y] == '0') {
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
    q.push({start, 1});

    while (!q.empty()) {
        pair<int, int> pos = q.front().first;
        int x = pos.first;
        int y = pos.second;
        int count = q.front().second;
        q.pop();

        if (x == endX && y == endY) {
            return count;
        }

        for (int i = 0; i < 4; i++) {
            int newX = x + dX[i];
            int newY = y + dY[i];

            if (isSafe(newX, newY)) {
                visited[newX][newY] = 1;
                q.push({{newX, newY}, count + 1});
            }
        }
    }
    return 1;
}

int main(void) {
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> map[i][j];
            visited[i][j] = 0;
        }
    }

    visited[0][0] = 1;
    cout << bfs({0, 0}, {N - 1, M - 1}) << "\n";
}