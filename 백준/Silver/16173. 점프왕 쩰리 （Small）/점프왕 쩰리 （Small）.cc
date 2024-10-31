#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int N;
int map[3][3];
int visited[3][3];
int dX[2] = {1, 0};
int dY[2] = {0, 1};
queue<pair<int, int>> q;

bool isSafe(int x, int y) {
  if(x < 0 || x >= N || y < 0 || y >= N)
    return false;
  if(visited[x][y])
    return false;
  return true;
}

bool bfs(pair<int, int> s, pair<int, int> e) {
  q.push(s);
  while (!q.empty())
  {
    pair<int, int> tmp = q.front();
    q.pop();

    int x = tmp.first;
    int y = tmp.second;
    
    if(x == e.first && y == e.second) {
      return true;
    }

    for(int i = 0; i < 2; i++) {
      int newX = x + dX[i] * map[x][y];
      int newY = y + dY[i] * map[x][y];

      if(isSafe(newX, newY)) {
        visited[newX][newY] = true;
        q.push({newX, newY});
      }
    }
  }
  return false;
}

int main(void) {
  cin >> N;
  for(int i = 0; i < N; i++) {
    for(int j = 0; j < N; j++) {
      cin >> map[i][j];
      visited[i][j] = 0;
    }
  }

  string result = bfs({0, 0}, {N-1, N-1}) ? "HaruHaru" : "Hing";
  cout << result << "\n";
  return 0;
}