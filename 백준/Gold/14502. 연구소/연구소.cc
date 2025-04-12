#include <iostream>
#include <queue>
#include <vector>
using namespace std;

#define MAX 8

typedef pair<int, int> pii;

int dX[4] = {1, 0, -1, 0};
int dY[4] = {0, 1, 0, -1};

int map[MAX][MAX];
int visited[MAX][MAX];
vector<pii> virus;
vector<pii> blank;

int N, M;

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

    if (map[x][y] == 1 || map[x][y] == 2) {
        return false;
    }

    return true;
}

int bfs() {
    int cnt = 0;
    queue<pii> q;
    for (pii v : virus) {
        q.push(v);
        visited[v.first][v.second] = 1;
    }

    while (!q.empty()) {
        pii cur = q.front();
        q.pop();
        int curX = cur.first;
        int curY = cur.second;
        for (int i = 0; i < 4; i++) {
            int nextX = curX + dX[i];
            int nextY = curY + dY[i];

            if (isSafe({nextX, nextY})) {
                cnt++;
                q.push({nextX, nextY});
                visited[nextX][nextY] = 1;
            }
        }
    }

    return cnt;
}

void clearVisited() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            visited[i][j] = 0;
        }
    }
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> map[i][j];
            if (map[i][j] == 0) {
                blank.push_back({i, j});
            } else if (map[i][j] == 2) {
                virus.push_back({i, j});
            }
        }
    }

    int maxCnt = -1;
    int blankSize = blank.size();
    for (int i = 0; i < blankSize; i++) {
        for (int j = i + 1; j < blankSize; j++) {
            for (int k = j + 1; k < blankSize; k++) {
                pii pos1 = blank[i];
                pii pos2 = blank[j];
                pii pos3 = blank[k];

                map[pos1.first][pos1.second] = 1;
                map[pos2.first][pos2.second] = 1;
                map[pos3.first][pos3.second] = 1;

                clearVisited();
                int cnt = bfs();

                map[pos1.first][pos1.second] = 0;
                map[pos2.first][pos2.second] = 0;
                map[pos3.first][pos3.second] = 0;

                maxCnt = max(maxCnt, blankSize - 3 - cnt);
            }
        }
    }

    cout << maxCnt << "\n";
    return 0;
}