#include <string>
#include <vector>
using namespace std;

#define MAX 101

int map[MAX][MAX];

bool isSafe(int x, int y, int m, int n) {
    if(x < 1 || y < 1) {
        return false;
    }
    
    if(x > m || y > n) {
        return false;
    }
    
    if(map[x][y] == 1) {
        return false;
    }
    
    return true;
}

int solution(int m, int n, vector<vector<int>> puddles) {
    int answer = 0;
    int dp[m+1][n+1];
    
    for(int i = 1; i <= m; i++) {
        for(int j = 1; j <= n; j++) {
            map[i][j] = 0;
            dp[i][j] = 0;
        }
    }
    
    for(vector<int> puddle : puddles) {
        int x = puddle[0];
        int y = puddle[1];
        
        map[x][y] = 1;
    }
    
    dp[1][1] = 1;
    for(int i = 1; i <= m; i++) {
        for(int j = 1; j <= n; j++) {
            if(isSafe(i-1, j, m, n)) {
                dp[i][j] += (dp[i-1][j] % 1000000007);
            }
            
            if(isSafe(i, j-1, m, n)) {
                dp[i][j] += (dp[i][j-1] % 1000000007);
            }
            dp[i][j] %= 1000000007;
        }
    }
    
    answer = dp[m][n] % 1000000007;
    
    return answer;
}