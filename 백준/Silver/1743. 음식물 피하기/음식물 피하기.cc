#include <iostream>
#include <vector>
#include <queue>
using namespace std;

bool map[101][101];
bool visited[101][101];

queue<pair<int, int>> q;
vector<pair<int, int>> targets;

int dX[4] = {1, 0, -1, 0};
int dY[4] = {0, 1, 0, -1};

int N, M, K;

void init() {
  for(int i = 1; i <= N; i++) {
    for(int j = 1; j <= M; j++) {
      map[i][j] = false;
      visited[i][j] = false;
    }
  }

  for(int i = 0; i < K; i++) {
    int x, y;
    cin >> x >> y;
    targets.push_back({x, y});
    map[x][y] = true;
  }
}

bool isSafe(int x, int y) {
  if(x <= 0 || x > N)
    return false;
  if(y <= 0 || y > M)
    return false;
  if(visited[x][y] || !map[x][y])
    return false;

  return true;
}

int bfs(pair<int, int> start) {
  int cnt = 0;

  visited[start.first][start.second] = true;
  q.push(start);
  while(!q.empty()) {
    cnt += 1;

    int x = q.front().first;
    int y = q.front().second;
    q.pop();

    for(int i = 0; i < 4; i++) {
      int newX = x + dX[i];
      int newY = y + dY[i];

      if(isSafe(newX, newY)) {
        visited[newX][newY] = true;
        q.push({newX, newY});
      }
    }
  }
  return cnt;
}

int main(void) {
  cin >> N >> M >> K;

  init();

  int maxVal = -1;
  for(int i = 0; i < int(targets.size()); i++) {
    if(!visited[targets[i].first][targets[i].second]) {
      int tmp = bfs(targets[i]);
      if(maxVal < tmp) {
        maxVal = tmp;
      }
    }
  }

  cout << maxVal << "\n";
  return 0;
}