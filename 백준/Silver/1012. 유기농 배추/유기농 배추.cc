#include <iostream>
#include <queue>
#include <vector>
using namespace std;

#define MAX 50

int dX[4] = {1, 0, -1, 0};
int dY[4] = {0, 1, 0, -1};

int map[MAX][MAX];
int visited[MAX][MAX];

int T;
int M, N, K;

bool isSafe(pair<int, int> pos) {
    int x = pos.first;
    int y = pos.second;
    if (x < 0 || x > M || y < 0 || y > N) {
        return false;
    }

    if (map[x][y] == 0 || visited[x][y]) {
        return false;
    }

    return true;
}

int bfs(pair<int, int> start) {
    int cnt = 0;
    queue<pair<int, int>> q;

    if (isSafe(start)) {
        q.push(start);
        visited[start.first][start.second] = 1;
    }

    while (!q.empty()) {
        pair<int, int> cur = q.front();
        q.pop();
        cnt++;

        for (int i = 0; i < 4; i++) {
            pair<int, int> next = {cur.first + dX[i], cur.second + dY[i]};

            if (isSafe(next)) {
                q.push(next);
                visited[next.first][next.second] = 1;
            }
        }
    }

    return cnt != 0 ? 1 : 0;
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> T;

    vector<pair<int, int>> v;
    for (int t = 0; t < T; t++) {
        cin >> M >> N >> K;

        for (int i = 0; i < M; i++) {
            for (int j = 0; j < N; j++) {
                map[i][j] = 0;
                visited[i][j] = 0;
            }
        }

        int x, y;
        for (int i = 0; i < K; i++) {
            cin >> x >> y;
            map[x][y] = 1;
            v.push_back({x, y});
        }

        int sum = 0;
        for (pair<int, int> pos : v) {
            sum += bfs(pos);
        }

        cout << sum << "\n";
        v.clear();
    }

    return 0;
}