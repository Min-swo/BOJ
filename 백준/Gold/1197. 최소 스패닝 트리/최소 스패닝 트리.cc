#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

#define MAX 10001
int V, E;
vector<pair<int, pair<int, int>>> v;
int parent[MAX];

int findParent(int node) {
    if (parent[node] != node) {
        parent[node] = findParent(parent[node]);
    }
    return parent[node];
}

int kruskal() {
    int cnt = 0;
    int sum = 0;
    for (pair<int, pair<int, int>> e : v) {
        int weight = e.first;
        int start = e.second.first;
        int end = e.second.second;

        int startParent = findParent(start);
        int endParent = findParent(end);
        if (endParent != startParent) {
            parent[endParent] = startParent;
            cnt++;
            sum += weight;
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
        parent[i] = i;
    }

    int a, b, w;
    for (int i = 0; i < E; i++) {
        cin >> a >> b >> w;
        v.push_back({w, {a, b}});
    }

    sort(v.begin(), v.end());
    cout << kruskal() << "\n";

    return 0;
}