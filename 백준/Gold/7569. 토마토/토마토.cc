#include <iostream>
#include <queue>
#include <tuple>
using namespace std;

int M, N, H;
int num;
int cnt = 0;
int tomatos[100][100][100];

queue<pair<tuple<int, int, int>, int>> q;
int dX[6] = {1, 0, 0, -1, 0, 0};
int dY[6] = {0, 1, 0, 0, -1, 0};
int dZ[6] = {0, 0, 1, 0, 0, -1};

bool isSafe(int x, int y, int z) {
    if (x < 0 || H <= x) {
        return false;
    }
    if (y < 0 || N <= y) {
        return false;
    }
    if (z < 0 || M <= z) {
        return false;
    }
    if (tomatos[x][y][z] == -1 || tomatos[x][y][z] == 1) {
        return false;
    }
    return true;
}

int bfs() {
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < N; j++) {
            for (int k = 0; k < M; k++) {
                if (tomatos[i][j][k] == 1) {
                    q.push({{i, j, k}, 0});
                }
            }
        }
    }

    while (!q.empty()) {
        tuple<int, int, int> cur = q.front().first;
        int x = get<0>(cur);
        int y = get<1>(cur);
        int z = get<2>(cur);
        int depth = q.front().second;
        q.pop();

        if (num == cnt) {
            while (!q.empty()) {
                depth = q.front().second;
                q.pop();
            }
            return depth;
        }

        for (int i = 0; i < 6; i++) {
            int newX = x + dX[i];
            int newY = y + dY[i];
            int newZ = z + dZ[i];

            if (isSafe(newX, newY, newZ)) {
                tomatos[newX][newY][newZ] = 1;
                q.push({{newX, newY, newZ}, depth + 1});
                cnt++;
            }
        }
    }

    return -1;
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> M >> N >> H;
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < N; j++) {
            for (int k = 0; k < M; k++) {
                int tomato;
                cin >> tomato;
                tomatos[i][j][k] = tomato;
                if (tomato == 1 || tomato == 0) {
                    num++;
                    if (tomato == 1) {
                        cnt++;
                    }
                }
            }
        }
    }

    cout << bfs() << "\n";
    return 0;
}