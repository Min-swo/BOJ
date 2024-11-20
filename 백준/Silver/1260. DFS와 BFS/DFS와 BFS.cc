#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

struct Node {
    int data;
    vector<Node *> edges;
};

Node *graph = new Node[1001];
int *visitedDfs = new int[1001];
int *visitedBfs = new int[1001];

int N, M, V;
queue<int> q;

void dfs(int pos) {
    cout << pos << " ";
    for (Node *node : graph[pos].edges) {
        if (!visitedDfs[node->data]) {
            visitedDfs[node->data] = 1;
            dfs(node->data);
        }
    }
}

void bfs(int start) {
    q.push(start);
    while (!q.empty()) {
        int cur = q.front();
        cout << cur << " ";
        q.pop();

        for (Node *node : graph[cur].edges) {
            if (!visitedBfs[node->data]) {
                visitedBfs[node->data] = 1;
                q.push(node->data);
            }
        }
    }
}

int main(void) {
    cin >> N >> M >> V;

    for (int i = 0; i < M; i++) {
        int n1, n2;
        cin >> n1 >> n2;

        graph[n1].edges.push_back(&graph[n2]);
        graph[n2].edges.push_back(&graph[n1]);
    }

    for (int i = 0; i <= N; i++) {
        graph[i].data = i;
        sort(graph[i].edges.begin(), graph[i].edges.end());
        visitedDfs[i] = 0;
        visitedBfs[i] = 0;
    }

    visitedDfs[V] = 1;
    dfs(V);
    cout << "\n";

    visitedBfs[V] = 1;
    bfs(V);
    cout << "\n";

    return 0;
}