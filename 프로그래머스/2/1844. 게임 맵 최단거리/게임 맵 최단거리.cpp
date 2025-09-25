#include <vector>
#include <queue>
using namespace std;

typedef pair<int, int> pii;

int dX[4] = {1, 0, -1, 0};
int dY[4] = {0, 1, 0, -1};

int n, m;
int map[100][100];
bool visited[100][100];

void init(vector<vector<int>> maps) {
    n = maps.size();
    m = maps[0].size();
    
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            map[i][j] = maps[i][j];
            visited[i][j] = false;
        }
    }
}

bool isSafe(pii pos) {
    int x = pos.first;
    int y = pos.second;
    
    if(x < 0 || y < 0) {
        return false;
    }
    
    if(x >= n || y >= m) {
        return false;
    }
    
    if(visited[x][y] || map[x][y] == 0) {
        return false;
    }
    
    return true;
}

int bfs() {
    pii start = {0, 0};
    pii end = {n - 1, m - 1};
    
    queue<pair<pii, int>> q;
    q.push({start, 1});
    visited[start.first][start.second] = true;
    
    while(!q.empty()) {
        pair<pii, int> cur = q.front();
        q.pop();
        
        pii curPos = cur.first;
        int curDist = cur.second;
        
        if(curPos == end) {
            return curDist;
        }
        
        int curX = curPos.first;
        int curY = curPos.second;
        
        for(int i = 0; i < 4; i++) {
            int nextX = curX + dX[i];
            int nextY = curY + dY[i];
            int nextDist = curDist + 1;
            
            if(isSafe({nextX, nextY})) {
                q.push({{nextX, nextY}, nextDist});
                visited[nextX][nextY] = true;
            }
        }
    }
    
    return -1;
}

int solution(vector<vector<int>> maps)
{
    init(maps);
    return bfs();
}