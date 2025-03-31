#include <iostream>
#include <queue>
#include <vector>
using namespace std;

#define MAX 1001

int N, M;
int visited[MAX];

bool isSafe(int node) {
    if (visited[node]) {
        return false;
    }
    return true;
}

int bfs(int start, vector<int> *nodes) {
    int cnt = 0;

    queue<int> q;
    if (isSafe(start)) {
        q.push(start);
        visited[start] = 1;
    }

    while (!q.empty()) {
        int cur = q.front();
        q.pop();
        cnt++;

        for (int next : nodes[cur]) {
            if (isSafe(next)) {
                q.push(next);
                visited[next] = 1;
            }
        }
    }

    return cnt != 0 ? 1 : 0;
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;

    vector<int> *nodes = new vector<int>[N + 1];
    for (int i = 0; i < N; i++) {
        visited[i] = 0;
    }

    int u, v;
    for (int i = 0; i < M; i++) {
        cin >> u >> v;
        nodes[u].push_back(v);
        nodes[v].push_back(u);
    }

    int sum = 0;
    for (int i = 1; i <= N; i++) {
        sum += bfs(i, nodes);
    }
    cout << sum << "\n";

    return 0;
}