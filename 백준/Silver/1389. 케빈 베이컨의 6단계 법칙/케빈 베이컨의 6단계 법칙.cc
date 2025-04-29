#include <iostream>
#include <queue>
#include <vector>
using namespace std;

#define MAX 101

typedef pair<int, int> pii;

int N, M;
vector<int> v[MAX];
int visited[MAX];
int bfs(int start) {
    int total = 0;
    queue<pii> q;
    visited[start] = 1;
    q.push({0, start});

    while (!q.empty()) {
        int depth = q.front().first;
        int cur = q.front().second;
        q.pop();

        total += depth;
        for (int node : v[cur]) {
            if (visited[node] != 1) {
                visited[node] = 1;
                q.push({depth + 1, node});
            }
        }
    }

    return total;
}

void setVisited() {
    for (int i = 0; i <= N; i++) {
        visited[i] = 0;
    }
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;

    int a, b;
    for (int i = 0; i < M; i++) {
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }

    int minVal = N * M;
    int minNode = 0;
    for (int i = 1; i <= N; i++) {
        setVisited();
        int depth = bfs(i);
        if (depth < minVal) {
            minVal = depth;
            minNode = i;
        }
    }
    cout << minNode << "\n";
    return 0;
}