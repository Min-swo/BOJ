#include <iostream>
#include <queue>
#include <tuple>
using namespace std;

int N, M, K;
char map[1000][1000];
int visitedDepth[1000][1000];
int visitedCount[1000][1000];
// day, cnt, depth
queue<pair<pair<int, int>, tuple<int, int, int>>> q;
int dX[4] = {1, 0, -1, 0};
int dY[4] = {0, 1, 0, -1};

bool isSafe(int x, int y, int day, int cnt, int depth) {
    if (x < 0 || N <= x) {
        return false;
    }
    if (y < 0 || M <= y) {
        return false;
    }
    if (visitedDepth[x][y] != -1 && visitedCount[x][y] != -1) {
        if (visitedDepth[x][y] <= depth && visitedCount[x][y] <= cnt) {
            return false;
        }
    }
    if (map[x][y] == '1') {
        if (!day) {
            return false;
        }
        if (cnt >= K) {
            return false;
        }
    }

    return true;
}

bool isWall(int x, int y) {
    if (map[x][y] == '1') {
        return true;
    }

    return false;
}

int bfs(pair<int, int> start, pair<int, int> end) {
    q.push({start, {1, 0, 1}});

    while (!q.empty()) {
        pair<int, int> cur = q.front().first;
        int day = get<0>(q.front().second);
        int cnt = get<1>(q.front().second);
        int depth = get<2>(q.front().second);
        q.pop();

        if (cur == end) {
            return depth;
        }

        for (int i = 0; i < 4; i++) {
            int newX = cur.first + dX[i];
            int newY = cur.second + dY[i];

            if (isSafe(newX, newY, day, cnt, depth + 1)) {
                if (isWall(newX, newY)) {
                    visitedDepth[newX][newY] = depth + 1;
                    visitedCount[newX][newY] = cnt + 1;
                    q.push({{newX, newY}, {!day, cnt + 1, depth + 1}});

                } else {
                    visitedDepth[newX][newY] = depth + 1;
                    visitedCount[newX][newY] = cnt;
                    q.push({{newX, newY}, {!day, cnt, depth + 1}});
                }
            }
        }
        if (day == 0) {
            q.push({cur, {!day, cnt, depth + 1}});
        }
    }
    return -1;
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M >> K;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> map[i][j];
            visitedDepth[i][j] = -1;
            visitedCount[i][j] = -1;
        }
    }

    visitedDepth[0][0] = 1;
    visitedCount[0][0] = 0;
    cout << bfs({0, 0}, {N - 1, M - 1}) << "\n";
}