#include <algorithm>
#include <iostream>
#include <stack>
#include <vector>
using namespace std;

#define MAX 10001
vector<int> *nodes = new vector<int>[MAX];
int visited[MAX];

stack<int> s;
int N, M;
int maxVal = -1;
vector<int> result;

bool isSafe(int pos) {
    if (pos <= 0 || N < pos) {
        return false;
    }
    if (visited[pos]) {
        return false;
    }

    return true;
}

int dfs(int start) {
    int cnt = 1;
    s.push(start);

    while (!s.empty()) {
        int curPos = s.top();
        s.pop();

        for (int newPos : nodes[curPos]) {
            if (isSafe(newPos)) {
                cnt++;
                visited[newPos] = 1;
                s.push(newPos);
            }
        }
    }
    return cnt;
}

int main(void) {
    cin >> N >> M;

    for (int i = 1; i <= N; i++) {
        visited[i] = 0;
    }

    for (int i = 0; i < M; i++) {
        int n1, n2;
        cin >> n1 >> n2;
        nodes[n2].push_back(n1);
    }

    for (int i = 1; i <= N; i++) {
        visited[i] = 1;
        int tmp = dfs(i);
        if (maxVal < tmp) {
            result.clear();
            result.push_back(i);
            maxVal = tmp;
        } else if (maxVal == tmp) {
            result.push_back(i);
        }

        for (int j = 1; j <= N; j++) {
            visited[j] = 0;
        }
    }

    sort(result.begin(), result.end());
    for (int node : result) {
        cout << node << " ";
    }
    cout << "\n";

    return 0;
}