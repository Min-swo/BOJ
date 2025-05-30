#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> triangle) {
    int answer = 0;
    int len = int(triangle.size());
    
    vector<vector<int>> dp;
    
    vector<int> v;
    v.push_back(triangle[0][0]);
    dp.push_back(v);
        
    for(int i = 1; i < len; i++) {
        vector<int> cur = triangle[i];
        int s = int(cur.size());
        vector<int> tmp;
        
        for(int j = 0; j < s; j++) {
            if(j == 0) {
                tmp.push_back(dp[i-1][j] + cur[j]);
            } else if(j == s - 1) {
                tmp.push_back(dp[i-1][j-1] + cur[j]);
            } else {
                int maxVal = max(dp[i-1][j], dp[i-1][j-1]);
                tmp.push_back(maxVal + cur[j]);
            }
        }
        
        dp.push_back(tmp);
    }
    
    answer = *max_element(dp[len-1].begin(), dp[len-1].end());
    
    return answer;
}