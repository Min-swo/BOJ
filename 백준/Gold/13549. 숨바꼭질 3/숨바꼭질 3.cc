#include <iostream>
#include <queue>
using namespace std;

#define MAX 100001

int N, K;
queue<pair<int, int>> q;
bool visited[MAX];

bool isSafe(int a) {
    if (a < 0 || a >= MAX || visited[a]) {
        return false;
    }

    return true;
}

int bfs(int start, int end) {
    q.push({start, 0});

    while (!q.empty()) {
        pair<int, int> curPair = q.front();
        int cur = curPair.first;
        int count = curPair.second;
        q.pop();

        if (cur == end) {
            return count;
        }

        if (isSafe(cur * 2)) {
            visited[cur * 2] = true;
            q.push({cur * 2, count});
        }
        if (isSafe(cur - 1)) {
            visited[cur - 1] = true;
            q.push({cur - 1, count + 1});
        }
        if (isSafe(cur + 1)) {
            visited[cur + 1] = true;
            q.push({cur + 1, count + 1});
        }
    }
    return -1;
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    for (int i = 0; i < MAX; i++) {
        visited[i] = false;
    }

    cin >> N >> K;

    cout << bfs(N, K) << "\n";
    return 0;
}