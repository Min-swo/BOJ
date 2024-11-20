#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int N;
int cnt = 0;
vector<int> cntVector;
char map[25][25];
int visited[25][25];
int dX[4] = {1, 0, -1, 0};
int dY[4] = {0, 1, 0, -1};

bool isSafe(int x, int y) {
    if (x < 0 || N <= x) {
        return false;
    }
    if (y < 0 || N <= y) {
        return false;
    }
    if (map[x][y] == '0') {
        return false;
    }
    if (visited[x][y]) {
        return false;
    }

    return true;
}

int dfs(int curX, int curY) {
    int cnt = 1;

    for (int i = 0; i < 4; i++) {
        int newX = curX + dX[i];
        int newY = curY + dY[i];

        if (isSafe(newX, newY)) {
            visited[newX][newY] = 1;
            cnt += dfs(newX, newY);
        }
    }
    return cnt;
}

int main(void) {
    cin >> N;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> map[i][j];
            visited[i][j] = 0;
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (isSafe(i, j)) {
                visited[i][j] = 1;
                cntVector.push_back(dfs(i, j));
                cnt++;
            }
        }
    }

    sort(cntVector.begin(), cntVector.end());
    cout << cnt << "\n";
    for (auto count : cntVector) {
        cout << count << "\n";
    }
}