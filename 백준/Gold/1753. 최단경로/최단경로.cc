#include <iostream>
#include <queue>
#include <vector>
using namespace std;

#define MAX 20001

int V, E, S;
int dist[MAX];
vector<pair<int, int>> graph[MAX];

void bfs(int start) {
    priority_queue<pair<int, int>> q;
    dist[start] = 0;
    q.push({dist[start], start});

    while (!q.empty()) {
        int cur = q.top().second;
        q.pop();

        for (pair<int, int> node : graph[cur]) {
            int next = node.first;
            int w = node.second;

            if (dist[next] > dist[cur] + w) {
                dist[next] = dist[cur] + w;
                q.push({-1 * dist[next], next});
            }
        }
    }
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> V >> E;
    cin >> S;

    for (int i = 1; i <= V; i++) {
        dist[i] = MAX * V;
    }

    int u, v, w;
    for (int i = 0; i < E; i++) {
        cin >> u >> v >> w;
        graph[u].push_back({v, w});
    }

    bfs(S);

    for (int i = 1; i <= V; i++) {
        if (dist[i] == MAX * V) {
            cout << "INF" << "\n";
        } else {
            cout << dist[i] << "\n";
        }
    }
    return 0;
}