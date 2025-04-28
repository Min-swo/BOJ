#include <iostream>
#include <queue>
using namespace std;

#define MAX 1000

typedef pair<int, int> pii;

int dX[4] = {1, 0, -1, 0};
int dY[4] = {0, 1, 0, -1};

int N, M;
int map[MAX][MAX];
int visited[MAX][MAX];

bool isSafe(pii pos) {
    int x = pos.first;
    int y = pos.second;

    if (x < 0 || y < 0) {
        return false;
    }

    if (x >= N || y >= M) {
        return false;
    }

    if (map[x][y] == 0) {
        return false;
    }

    return true;
}

void bfs(pii start) {
    queue<pii> q;
    q.push(start);
    visited[start.first][start.second] = 0;

    while (!q.empty()) {
        pii cur = q.front();
        int curX = cur.first;
        int curY = cur.second;
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nextX = curX + dX[i];
            int nextY = curY + dY[i];
            pii next = {nextX, nextY};

            if (isSafe(next)) {
                if (visited[nextX][nextY] == -1 ||
                    visited[nextX][nextY] > visited[curX][curY] + 1) {
                    visited[nextX][nextY] = visited[curX][curY] + 1;
                    q.push(next);
                }
            }
        }
    }
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;

    pii start;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> map[i][j];
            if (map[i][j] == 2) {
                start = {i, j};
            }
            visited[i][j] = -1;
        }
    }

    bfs(start);

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (map[i][j] == 0 && visited[i][j] == -1) {
                cout << 0 << " ";
            } else {
                cout << visited[i][j] << " ";
            }
        }
        cout << "\n";
    }

    return 0;
}