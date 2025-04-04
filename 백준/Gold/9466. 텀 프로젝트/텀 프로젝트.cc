#include <iostream>
#include <queue>
#include <stack>
using namespace std;

#define MAX 100001

int T, n;
int arr[MAX];
int visited[MAX];
int joined[MAX];

void bfs(int start) {
    queue<int> q;
    queue<int> q2;

    if (!joined[start] && !visited[start]) {
        q.push(start);
        visited[start] = 1;
    }

    while (!q.empty()) {
        int cur = q.front();
        q.pop();
        q2.push(cur);

        int next = arr[cur];
        if (joined[next]) {
            break;
        } else if (visited[next]) {
            int flag = 0;
            while (!q2.empty()) {
                int front = q2.front();
                q2.pop();

                if (!flag && front != next) {
                    continue;
                } else {
                    flag = 1;
                }

                joined[front] = 1;
            }
        } else {
            q.push(next);
            visited[next] = 1;
        }
    }
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> T;
    for (int tc = 0; tc < T; tc++) {
        cin >> n;
        for (int i = 1; i <= n; i++) {
            cin >> arr[i];
            visited[i] = 0;
            joined[i] = 0;
        }

        for (int i = 1; i <= n; i++) {
            bfs(i);
        }

        int sum = 0;
        for (int i = 1; i <= n; i++) {
            sum += joined[i];
        }

        cout << n - sum << "\n";
    }
    return 0;
}