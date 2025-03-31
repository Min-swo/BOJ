#include <iostream>
#include <queue>
using namespace std;

#define MAX 100000

queue<pair<int, int>> q;
int visited[MAX + 1];

void init() {
    for (int i = 0; i < MAX + 1; i++) {
        visited[i] = 0;
    }
}

bool isSafe(int n) {
    if (n < 0 || n > MAX || visited[n]) {
        return false;
    }
    return true;
}

int bfs(int start, int end) {
    q.push({start, 0});

    while (!q.empty()) {
        int cur = q.front().first;
        int cnt = q.front().second;
        q.pop();

        if (cur == end) {
            return cnt;
        }

        if (isSafe(cur - 1)) {
            q.push({cur - 1, cnt + 1});
            visited[cur - 1] = 1;
        }
        if (isSafe(cur + 1)) {
            q.push({cur + 1, cnt + 1});
            visited[cur + 1] = 1;
        }
        if (isSafe(cur * 2)) {
            q.push({cur * 2, cnt + 1});
            visited[cur * 2] = 1;
        }
    }
    return 0;
}

int main(void) {
    int N, K;
    cin >> N >> K;

    init();
    cout << bfs(N, K) << "\n";
    return 0;
}