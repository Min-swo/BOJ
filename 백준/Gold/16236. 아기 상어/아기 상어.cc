#include <iostream>
#include <queue>
#include <vector>
using namespace std;

typedef pair<int, int> pii;
typedef pair<int, pii> pipii;

#define MAX 20
int map[MAX][MAX];
int visited[MAX][MAX];
int dX[4] = {1, 0, -1, 0};
int dY[4] = {0, 1, 0, -1};

int N;
pii shark;
int sharkSize = 2;
int sharkCount = 0;
priority_queue<pipii, vector<pipii>, greater<pipii>> fishes;

bool isSafe(pii pos) {
    int x = pos.first;
    int y = pos.second;

    if (x < 0 || y < 0) {
        return false;
    }

    if (x >= N || y >= N) {
        return false;
    }

    if (visited[x][y]) {
        return false;
    }

    if (map[x][y] > sharkSize) {
        return false;
    }

    return true;
}

int bfs(pii start, pii end) {
    queue<pipii> q;
    if (sharkSize > map[end.first][end.second]) {
        q.push({0, start});
        visited[start.first][start.second] = 1;
    }

    while (!q.empty()) {
        pii cur = q.front().second;
        int dist = q.front().first;
        q.pop();

        if (cur == end) {
            return dist;
        }

        int curX = cur.first;
        int curY = cur.second;

        for (int i = 0; i < 4; i++) {
            int nextX = curX + dX[i];
            int nextY = curY + dY[i];
            if (isSafe({nextX, nextY})) {
                visited[nextX][nextY] = 1;
                q.push({dist + 1, {nextX, nextY}});
            }
        }
    }

    return N * N;
}

void clearVisited() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            visited[i][j] = 0;
        }
    }
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> map[i][j];

            if (map[i][j] == 9) {
                shark = {i, j};
            } else if (map[i][j] != 0) {
                fishes.push({N * N, {i, j}});
            }
        }
    }

    int total = 0;
    while (1) {
        // cout << "============================\n";
        queue<pipii> q;

        int fishSize = fishes.size();
        if (fishSize == 0) {
            break;
        }

        for (int i = 0; i < fishSize; i++) {
            pii fish = fishes.top().second;
            fishes.pop();

            clearVisited();
            int dist = bfs(shark, fish);
            // cout << "dist : " << dist << "\n";
            q.push({dist, fish});
        }

        int qSize = q.size();
        // cout << "qSize : " << qSize << "\n";
        for (int i = 0; i < qSize; i++) {
            fishes.push(q.front());
            q.pop();
        }

        int min = fishes.top().first;
        pii fish = fishes.top().second;
        // cout << "min : " << min << "\n";
        if (min == N * N) {
            break;
        }

        fishes.pop();
        total += min;
        map[shark.first][shark.second] = 0;
        shark = fish;
        // cout << "fish : " << fish.first << ", " << fish.second << "\n";
        sharkCount++;
        if (sharkCount == sharkSize) {
            sharkSize++;
            sharkCount = 0;
        }
        // cout << "============================\n";
    }

    cout << total << "\n";
    return 0;
}