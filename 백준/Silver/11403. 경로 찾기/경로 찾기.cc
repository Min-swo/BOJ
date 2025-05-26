#include <iostream>
#include <queue>
using namespace std;

#define MAX 100

int N;
int graph[MAX][MAX];
int answer[MAX][MAX];
int visited[MAX];

bool isSafe(int cur, int idx) {
    int next = graph[cur][idx];
    if (visited[idx] == 1) {
        return false;
    }

    if (next == 0) {
        return false;
    }

    return true;
}

void bfs(int start) {
    queue<int> q;
    for (int i = 0; i < N; i++) {
        if (isSafe(start, i)) {
            q.push(i);
            visited[i] = 1;
        }
    }

    while (!q.empty()) {
        int cur = q.front();
        q.pop();

        answer[start][cur] = 1;

        for (int i = 0; i < N; i++) {
            if (isSafe(cur, i)) {
                q.push(i);
                visited[i] = 1;
            }
        }
    }
}

void clearVisited() {
    for (int i = 0; i < N; i++) {
        visited[i] = 0;
    }
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> graph[i][j];
            answer[i][j] = 0;
        }
        visited[i] = 0;
    }

    for (int i = 0; i < N; i++) {
        clearVisited();
        bfs(i);
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << answer[i][j] << " ";
        }
        cout << "\n";
    }

    return 0;
}