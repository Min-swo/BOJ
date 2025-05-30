#include <string>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

bool isInclude(vector<int> v, int number) {
    for(int k : v) {
        if(k == number) {
            return true;
        }
    }
    return false;
}

int solution(int N, int number) {
    int answer = -1;
    
    if(N == number) {
        return 1;
    }
    
    vector<int> pre;
    int tmp = 0;
    pre.push_back(tmp);
    for(int i = 0; i < 8; i++) {
        tmp += N * pow(10, i);
        pre.push_back(tmp);
    }
    
    vector<int> dp[9];
    dp[1].push_back(pre[1]);
   
    for(int i = 2; i <= 8; i++) {
        dp[i].push_back(pre[i]);

        for(int j = 1; j <= i / 2; j++) {
            for(int k : dp[j]) {
                for(int m : dp[i - j]) {
                    dp[i].push_back(k + m);
                    dp[i].push_back(k - m);
                    dp[i].push_back(m - k);
                    dp[i].push_back(k * m);
                    if(m != 0) {
                        dp[i].push_back(k / m);
                    }
                    if(k != 0) {
                        dp[i].push_back(m / k);
                    }
                }
            }
        }
        
        if(isInclude(dp[i], number)) {
            answer = i;
            break;
        }
    }
    
    
    return answer;
}