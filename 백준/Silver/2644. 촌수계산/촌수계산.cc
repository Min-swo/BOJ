#include <iostream>
#include <queue>
using namespace std;

int N, M;
int A, B;

struct Node {
    int idx;
    vector<int> parent;
    vector<int> child;
};

Node *node = new Node[101];
queue<pair<int, int>> q;
int *visited = new int[101];

bool isSafe(int idx) {
    if (!visited[idx]) {
        return true;
    }
    return false;
}

int bfs(int startIdx, int endIdx) {
    q.push({startIdx, 0});

    while (!q.empty()) {
        pair<int, int> cur = q.front();
        int curIdx = cur.first;
        int curCount = cur.second;
        q.pop();

        if (curIdx == endIdx) {
            return curCount;
        }

        for (int parentIdx : node[curIdx].parent) {
            if (isSafe(parentIdx)) {
                visited[parentIdx] = true;
                q.push({parentIdx, curCount + 1});
            }
        }

        for (int childIdx : node[curIdx].child) {
            if (isSafe(childIdx)) {
                visited[childIdx] = true;
                q.push({childIdx, curCount + 1});
            }
        }
    }
    return -1;
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    for (int i = 0; i <= N; i++) {
        node[i].idx = i;
        visited[i] = false;
    }

    cin >> A >> B;

    cin >> M;
    for (int i = 0; i < M; i++) {
        int parent, child;
        cin >> parent >> child;

        node[parent].child.push_back(child);
        node[child].parent.push_back(parent);
    }

    cout << bfs(A, B) << "\n";
    return 0;
}