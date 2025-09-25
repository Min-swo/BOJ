#include <string>
#include <vector>

using namespace std;

vector<int> parent(200);

void init() {
    for(int i = 0; i < 200; i++) {
        parent[i] = i;
    }
}

int mFind(int node) {
    while(parent[node] != node) {
        node = parent[node];
    }
    
    return node;
}

void mUnion(int node1, int node2) {
    parent[mFind(node2)] = mFind(node1);
}

int solution(int n, vector<vector<int>> computers) {
    init();
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(i != j && computers[i][j] == 1) {
                mUnion(i, j);
            }
        }
    }
    
    int cnt = 0;
    for(int i = 0; i < n; i++) {
        if(parent[i] == i) {
            cnt += 1;
        }
    }
    return cnt;
}