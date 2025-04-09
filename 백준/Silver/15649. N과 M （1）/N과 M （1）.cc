#include <iostream>
#include <queue>
using namespace std;

int N, M;
deque<int> dq;
int visited[9];

void dfs() {
    if (int(dq.size()) == M) {
        for (int i = 0; i < M; i++) {
            cout << dq.at(i) << " ";
        }
        cout << "\n";
        return;
    }

    for (int i = 1; i <= N; i++) {
        if (visited[i]) {
            continue;
        }

        visited[i] = 1;
        dq.push_back(i);

        dfs();

        int back = dq.back();
        dq.pop_back();
        visited[back] = 0;
    }
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;

    dfs();

    return 0;
}