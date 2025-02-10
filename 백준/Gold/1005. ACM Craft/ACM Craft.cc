#include <iostream>
#include <queue>
#include <vector>
using namespace std;

#define MAX 1001

int delay[MAX] = {0};
int visited[MAX] = {0};
int isNotStart[MAX] = {0};
vector<int> *graph = new vector<int>[MAX];
queue<int> q;

void bfs(int start) {
    visited[start] = delay[start];
    q.push(start);

    while (!q.empty()) {
        int cur = q.front();
        q.pop();

        for (int node : graph[cur]) {
            if (visited[node] < visited[cur] + delay[node]) {
                visited[node] = visited[cur] + delay[node];
                q.push(node);
            }
        }
    }
}

int main(void) {
    int T;
    int N, K;
    int end;

    cin >> T;
    for (int i = 0; i < T; i++) {
        cin >> N >> K;

        for (int j = 1; j <= N; j++) {
            cin >> delay[j];
            visited[j] = delay[j];
            isNotStart[j] = 0;
            graph[j].clear();
        }

        int x, y;
        for (int j = 1; j <= K; j++) {
            cin >> x >> y;
            graph[x].push_back(y);
            isNotStart[y] = 1;
        }

        cin >> end;

        for (int j = 1; j <= N; j++) {
            if (isNotStart[j] == 0) {
                bfs(j);
            }
        }
        cout << visited[end] << "\n";
    }
}