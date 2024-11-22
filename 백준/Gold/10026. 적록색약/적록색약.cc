#include <iostream>
#include <queue>
#include <stack>
using namespace std;

#define MAX 100
int N;
int normalCount = 0;
int abnormalCount = 0;
char map[MAX][MAX];
int dX[4] = {1, 0, -1, 0};
int dY[4] = {0, 1, 0, -1};

stack<pair<int, int>> s;
int visited[MAX][MAX];

bool isSafe(int x, int y, char color, bool normal) {
    if (x < 0 || N <= x) {
        return false;
    }
    if (y < 0 || N <= y) {
        return false;
    }
    if (visited[x][y]) {
        return false;
    }
    if (normal) {
        if (map[x][y] != color) {
            return false;
        }
    } else {
        if (map[x][y] != color) {
            if (map[x][y] == 'B' || color == 'B') {
                return false;
            }
        }
    }

    return true;
}

void dfs(pair<int, int> start, char color, bool normal) {
    visited[start.first][start.second] = 1;
    s.push(start);

    while (!s.empty()) {
        pair<int, int> cur = s.top();
        int curX = cur.first;
        int curY = cur.second;
        s.pop();

        for (int i = 0; i < 4; i++) {
            int newX = curX + dX[i];
            int newY = curY + dY[i];

            if (isSafe(newX, newY, color, normal)) {
                visited[newX][newY] = 1;
                s.push({newX, newY});
            }
        }
    }
}

int main(void) {
    cin >> N;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> map[i][j];
            visited[i][j] = 0;
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (!visited[i][j]) {
                dfs({i, j}, map[i][j], true);
                normalCount++;
            }
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            visited[i][j] = 0;
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (!visited[i][j]) {
                dfs({i, j}, map[i][j], false);
                abnormalCount++;
            }
        }
    }

    cout << normalCount << " " << abnormalCount << "\n";
    return 0;
}