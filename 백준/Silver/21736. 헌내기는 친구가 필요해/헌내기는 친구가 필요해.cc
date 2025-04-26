#include <iostream>
#include <queue>
using namespace std;

#define MAX 600

typedef pair<int, int> pii;

int N, M;
char map[MAX][MAX];
bool visited[MAX][MAX];

int dX[4] = {1, 0, -1, 0};
int dY[4] = {0, 1, 0, -1};

bool isSafe(pii pos) {
    int x = pos.first;
    int y = pos.second;

    if (x < 0 || y < 0) {
        return false;
    }

    if (x >= N || y >= M) {
        return false;
    }

    if (visited[x][y]) {
        return false;
    }

    if (map[x][y] == 'X') {
        return false;
    }
    return true;
}

int bfs(pii start) {
    int cnt = 0;

    queue<pii> q;
    q.push(start);

    while (!q.empty()) {
        pii cur = q.front();
        q.pop();

        int curX = cur.first;
        int curY = cur.second;

        if (map[curX][curY] == 'P') {
            cnt++;
        }

        for (int i = 0; i < 4; i++) {
            int nextX = curX + dX[i];
            int nextY = curY + dY[i];

            if (isSafe({nextX, nextY})) {
                q.push({nextX, nextY});
                visited[nextX][nextY] = true;
            }
        }
    }

    return cnt;
}

int main(void) {
    cin >> N >> M;

    pii start;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> map[i][j];
            if (map[i][j] == 'I') {
                start = {i, j};
            }
        }
    }

    int cnt = bfs(start);
    if (cnt) {
        cout << cnt << "\n";
    } else {
        cout << "TT\n";
    }
    return 0;
}