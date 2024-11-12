#include <iostream>
#include <queue>
using namespace std;

int N;
int map[100][100];
int visited[100][100];
int maxVal = 0;

queue<pair<int, int>> q;
int dX[4] = {1, 0, -1, 0};
int dY[4] = {0, 1, 0, -1};

bool isSafe(int x, int y, int h) {
    if (x < 0 || x >= N) {
        return false;
    }
    if (y < 0 || y >= N) {
        return false;
    }
    if (visited[x][y]) {
        return false;
    }
    if (map[x][y] <= h) {
        return false;
    }

    return true;
}

int bfs(pair<int, int> start, int h) {
    q.push(start);

    while (!q.empty()) {
        pair<int, int> cur = q.front();
        q.pop();
        int x = cur.first;
        int y = cur.second;

        for (int i = 0; i < 4; i++) {
            int newX = x + dX[i];
            int newY = y + dY[i];

            if (isSafe(newX, newY, h)) {
                visited[newX][newY] = 1;
                q.push({newX, newY});
            }
        }
    }

    return 1;
}

int ans(int h) {
    int count = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (isSafe(i, j, h)) {
                visited[i][j] = 1;
                count += bfs({i, j}, h);
            }
        }
    }
    return count;
}

void setVisitedFalseAll() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            visited[i][j] = 0;
        }
    }
}

int main(void) {
    cin >> N;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> map[i][j];
        }
    }

    for (int i = 0; i <= 100; i++) {
        setVisitedFalseAll();
        int count = ans(i);
        if (count == 0) {
            break;
        }

        if (maxVal < count) {
            maxVal = count;
        }
    }

    cout << maxVal << "\n";
}