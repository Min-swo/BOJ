#include <iostream>
#include <queue>
using namespace std;

#define MAX 50
int map[MAX][MAX];
int visited[MAX][MAX];
int w, h;

int dX[8] = {1, 1, 1, 0, -1, -1, -1, 0};
int dY[8] = {-1, 0, 1, 1, 1, 0, -1, -1};

bool isSafe(pair<int, int> pos) {
    int x = pos.first;
    int y = pos.second;

    if (x < 0 || y < 0) {
        return false;
    }

    if (x >= h || y >= w) {
        return false;
    }

    if (visited[x][y] || map[x][y] == 0) {
        return false;
    }

    return true;
}

int bfs(pair<int, int> start) {
    queue<pair<int, int>> q;
    if (!isSafe(start)) {
        return 0;
    }

    q.push(start);
    visited[start.first][start.second] = 1;

    while (!q.empty()) {
        pair<int, int> cur = q.front();
        q.pop();

        int curX = cur.first;
        int curY = cur.second;

        for (int i = 0; i < 8; i++) {
            int nextX = curX + dX[i];
            int nextY = curY + dY[i];
            if (isSafe({nextX, nextY})) {
                q.push({nextX, nextY});
                visited[nextX][nextY] = 1;
            }
        }
    }
    return 1;
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    while (1) {
        cin >> w >> h;
        if (w == 0 && h == 0) {
            break;
        }

        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                cin >> map[i][j];
                visited[i][j] = 0;
            }
        }

        int cnt = 0;
        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                cnt += bfs({i, j});
            }
        }

        cout << cnt << "\n";
    }

    return 0;
}