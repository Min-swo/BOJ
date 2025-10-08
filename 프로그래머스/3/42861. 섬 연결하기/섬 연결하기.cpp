#include <string>
#include <vector>
#include <queue>
using namespace std;

typedef pair<int, int> pii;

vector<pii> edges[104];
priority_queue<pii, vector<pii>, greater<pii>> pq;
vector<int> visited(104);

int solution(int n, vector<vector<int>> costs) {
    for(int i = 0; i < costs.size(); i++) {
        edges[costs[i][0]].push_back({costs[i][2], costs[i][1]});
        edges[costs[i][1]].push_back({costs[i][2], costs[i][0]});
    }
    
    int cnt = 0;
    int sum = 0;
    int curIdx = costs[0][0];
    for(int i = 0; i < edges[curIdx].size(); i++) {
        pq.push(edges[curIdx][i]);
    }
    visited[curIdx] = true;
    cnt += 1;
    
    while(cnt < n) {
        pii cur = pq.top();
        pq.pop();
        
        int curCost = cur.first;
        int nextNode = cur.second;
        
        if(visited[nextNode]) {
            continue;
        }
        
        visited[nextNode] = true;
        for(int i = 0; i < edges[nextNode].size(); i++) {
            pq.push(edges[nextNode][i]);
        }

        cnt += 1;
        sum += curCost;
    }
    
    return sum;
}