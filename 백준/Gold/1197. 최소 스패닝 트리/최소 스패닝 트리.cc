#include <iostream>
#include <queue>
#include <vector>
using namespace std;

#define MAX 10001
int V, E;
vector<pair<int, int>> v[MAX];
int visited[MAX];

int prim(int start) {
    priority_queue<pair<int, int>> q;
    int cnt = 0;
    int sum = 0;

    visited[start] = 1;
    for (pair<int, int> e : v[start]) {
        q.push({-1 * e.first, e.second});
    }

    while (!q.empty() && cnt < V - 1) {
        int cur = q.top().second;
        int curW = q.top().first;
        q.pop();

        if (visited[cur]) {
            continue;
        }

        sum += -1 * curW;
        cnt++;

        visited[cur] = 1;

        for (pair<int, int> e : v[cur]) {
            int next = e.second;
            int nextW = e.first;
            if (!visited[next]) {
                q.push({-1 * nextW, next});
            }
        }
    }

    return sum;
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> V >> E;
    for (int i = 1; i <= V; i++) {
        visited[i] = 0;
    }

    int a, b, w;
    for (int i = 0; i < E; i++) {
        cin >> a >> b >> w;
        v[a].push_back({w, b});
        v[b].push_back({w, a});
    }

    cout << prim(1) << "\n";
    return 0;
}