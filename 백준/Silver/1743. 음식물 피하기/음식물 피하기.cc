#include <iostream>
#include <vector>
using namespace std;

int maxVal = -1;
int cnt = 0;

int map[101][101];
int visited[101][101];
vector<pair<int, int>> targets;

int dX[4] = {1, 0, -1, 0};
int dY[4] = {0, 1, 0, -1};

int N, M, K;

void init() {
  for(int i = 1; i <= N; i++) {
    for(int j = 1; j <= M; j++) {
      map[i][j] = 0;
      visited[i][j] = 0;
    }
  }

  for(int i = 0; i < K; i++) {
    int x, y;
    cin >> x >> y;
    targets.push_back({x, y});
    map[x][y] = 1;
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

void dfs(int x, int y) {
  visited[x][y] = 1;
  cnt += 1;
  for(int i = 0; i < 4; i++) {
    int newX = x + dX[i];
    int newY = y + dY[i];

    if(isSafe(newX, newY)) {
      dfs(newX, newY);
    }
  }

  if(maxVal < cnt)
    maxVal = cnt;
}

// void printMap() {
//   for(int i = 1; i <= N; i++) {
//     for(int j = 1; j <= M; j++) {
//       cout << map[i][j] << " ";
//     }
//     cout << "\n";
//   }
// }

void resetVisited() {
  for(int i = 1; i <= N; i++) {
    for(int j = 1; j <= M; j++) {
      visited[i][j] = 0;
    }
  }
}

int main(void) {
  cin >> N >> M >> K;

  init();

  for(int i = 0; i < targets.size(); i++) {
    dfs(targets[i].first, targets[i].second);
    cnt = 0;
    resetVisited();
  }

  cout << maxVal << "\n";
  return 0;
}