#include <iostream>
#include <queue>
using namespace std;

#define MAX 100001
int N, K;

queue<pair<int, int>> q;
int cnt = 0;
int minVal = MAX;
int visited[MAX] = {};

bool isSafe(int x, int d) {
    if (x < 0 || 100001 <= x) {
        return false;
    }
    if (visited[x] != -1 && visited[x] < d) {
        return false;
    }
    return true;
}

void bfs(int start, int end) {
    q.push({start, 0});
    while (!q.empty()) {
        int cur = q.front().first;
        int depth = q.front().second;
        q.pop();

        if (cur == end) {
            if (minVal > depth) {
                minVal = depth;
                cnt = 1;
            } else if (minVal == depth) {
                cnt++;
            }
        }

        if (isSafe(cur * 2, depth + 1)) {
            visited[cur * 2] = depth + 1;
            q.push({cur * 2, depth + 1});
        }
        if (isSafe(cur + 1, depth + 1)) {
            visited[cur + 1] = depth + 1;
            q.push({cur + 1, depth + 1});
        }
        if (isSafe(cur - 1, depth + 1)) {
            visited[cur - 1] = depth + 1;
            q.push({cur - 1, depth + 1});
        }
    }
}

int main(void) {
    cin >> N >> K;
    for (int i = 0; i < MAX; i++) {
        visited[i] = -1;
    }
    visited[N] = 1;
    bfs(N, K);
    cout << minVal << "\n" << cnt << "\n";
}