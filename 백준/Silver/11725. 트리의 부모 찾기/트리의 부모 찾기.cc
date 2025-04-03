#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;

    vector<int> v[N + 1];
    int visited[N + 1];
    int parent[N + 1];

    int n1, n2;
    for (int i = 1; i < N; i++) {
        cin >> n1 >> n2;
        v[n1].push_back(n2);
        v[n2].push_back(n1);
        visited[i] = 0;
        parent[i] = 0;
    }
    visited[N] = 0;
    parent[N] = 0;

    queue<int> q;
    q.push(1);
    visited[1] = 1;
    while (!q.empty()) {
        int cur = q.front();
        q.pop();

        for (int next : v[cur]) {
            if (!visited[next]) {
                parent[next] = cur;
                q.push(next);
                visited[next] = 1;
            }
        }
    }

    for (int i = 2; i <= N; i++) {
        cout << parent[i] << "\n";
    }

    return 0;
}