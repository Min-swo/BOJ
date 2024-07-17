#include <iostream>
using namespace std;

#define MAX 500

int n, m;
int score[MAX][MAX];
bool visited[MAX][MAX];
int maxVal = -1;

bool isSafe(int x, int y)
{
    if((0 <= x && x < n) && (0 <= y && y < m))
    {
        if(visited[x][y] == false)
            return true;
    }
    return false;
}

bool isBound(int x, int y)
{
    if((0 <= x && x < n) && (0 <= y && y < m))
    {
        return true;
    }
    return false;
}

void dfs(int depth, int x, int y, int sum, int flag)
{
    if(depth == 3)
    {
        visited[x][y] = true;
        int dX[4] = {1, -1, 0, 0};
        int dY[4] = {0, 0, 1, -1};
        for(int i = 0; i < 4; i++)
        {
            if(isBound(x+dX[i], y+dY[i]))
            {
                if(visited[x+dX[i]][y+dY[i]])
                {
                    for(int j = 0; j < 4; j++)
                    {
                        if(isSafe(x+dX[i]+dX[j], y+dY[i]+dY[j]))
                        {
                            maxVal = max(maxVal, 
                                sum + score[x+dX[i]+dX[j]][y+dY[i]+dY[j]]);
                        }
                    }
                }
            }
        }
        visited[x][y] = false;
    }
    if(depth == 4)
    {
        maxVal = max(maxVal, sum);
        return;
    }

    if(isSafe(x-1, y))
    {
        visited[x][y] = true;
        dfs(depth+1, x-1, y, sum + score[x-1][y], 0);
        visited[x][y] = false;
    }
    if(isSafe(x+1, y))
    {
        visited[x][y] = true;
        dfs(depth+1, x+1, y, sum + score[x+1][y], 0);
        visited[x][y] = false;
    }
    if(isSafe(x, y-1))
    {
        visited[x][y] = true;
        dfs(depth+1, x, y-1, sum + score[x][y-1], 0);
        visited[x][y] = false;
    }
    if(isSafe(x, y+1))
    {
        visited[x][y] = true;
        dfs(depth+1, x, y+1, sum + score[x][y+1], 0);
        visited[x][y] = false;
    }
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
            cin >> score[i][j];
    }

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            dfs(1, i, j, score[i][j], 0);
        }
    }

    cout << maxVal << "\n";

    return 0;
}