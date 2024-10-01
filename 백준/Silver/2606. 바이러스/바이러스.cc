#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int N;
int pairN;
int a, b;

vector<vector<int>> graph;
queue<int> q;
int visited[101];

int main(void) {
  cin >> N >> pairN;

  for(int i = 0; i <= N; i++){
    vector<int> tmp;
    visited[i] = 0;
    graph.push_back(tmp);
  }

  for(int i = 0; i < pairN; i++) {
    cin >> a >> b;
    graph[a].push_back(b);
    graph[b].push_back(a);
  }

  int total = 0;
  visited[1] = 1;
  for(int i = 0; i < graph[1].size(); i++) {
      if(!visited[graph[1][i]]) {
        visited[graph[1][i]] = 1;
        q.push(graph[1][i]);
        total++;
      }
    }
  while(!q.empty()) {
    int idx = q.front();
    q.pop();
    for(int i = 0; i < graph[idx].size(); i++) {
      if(!visited[graph[idx][i]]) {
        visited[graph[idx][i]] = 1;
        q.push(graph[idx][i]);
        total++;
      }
    }
  }
  
  cout << total << "\n";

  return 0;
}