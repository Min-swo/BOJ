#include <iostream>
using namespace std;

#define MAX 50
int map[MAX][MAX];
int visited[MAX][MAX];

int dX[4] = {-1, 0, 1, 0};
int dY[4] = {0, 1, 0, -1};

int N, M;
int startX, startY, startD;

bool isSafe(pair<int, int> pos) {
    int x = pos.first;
    int y = pos.second;

    if (x < 0 || y < 0) {
        return false;
    }

    if (x >= N || y >= M) {
        return false;
    }

    if (map[x][y]) {
        return false;
    }

    return true;
}

int dfs(pair<int, int> start) {
    int cleanCnt = 0;

    pair<int, int> cur = start;
    while (1) {
        int curX = cur.first;
        int curY = cur.second;

        if (visited[curX][curY] == 0) {
            visited[curX][curY] = 1;
            cleanCnt++;
        }

        int tmpCnt = 0;
        for (int i = 0; i < 4; i++) {
            int nextX = curX + dX[i];
            int nextY = curY + dY[i];

            if (isSafe({nextX, nextY}) && visited[nextX][nextY] == 0) {
                tmpCnt++;
            }
        }

        if (tmpCnt == 0) {
            int backX = curX + dX[(startD + 2) % 4];
            int backY = curY + dY[(startD + 2) % 4];

            if (!isSafe({backX, backY})) {
                break;
            }

            cur = {backX, backY};
            continue;
        } else {
            startD = (startD + 3) % 4;
            int nextX = curX + dX[startD];
            int nextY = curY + dY[startD];

            if (isSafe({nextX, nextY}) && visited[nextX][nextY] == 0) {
                cur = {nextX, nextY};
            }
        }
    }

    return cleanCnt;
}

int main(void) {
    cin >> N >> M;
    cin >> startX >> startY >> startD;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> map[i][j];
            visited[i][j] = 0;
        }
    }

    cout << dfs({startX, startY}) << "\n";
    return 0;
}