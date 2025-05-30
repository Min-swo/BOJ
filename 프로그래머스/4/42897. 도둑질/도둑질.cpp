#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> money) {
    int answer = 0;
    int len = int(money.size());
    vector<int> dp1;
    vector<int> dp2;
    
    dp1.push_back(money[0]);
    dp1.push_back(money[0]);
    for(int i = 2; i < len - 1; i++) {
        int maxVal = -1;
        for(int j = 2; j <= 3 && i - j >= 0; j++) {
            maxVal = max(maxVal, dp1[i - j]);
        }
        dp1.push_back(maxVal + money[i]);
    }
    
    dp2.push_back(money[1]);
    dp2.push_back(money[2]);
    for(int i = 2; i < len-1; i++) {
        int maxVal = -1;
        for(int j = 2; j <= 3 && i - j >= 0; j++) {
            maxVal = max(maxVal, dp2[i - j]);
        }
        dp2.push_back(maxVal + money[i+1]);
    }
    
    int maxVal1 = *max_element(dp1.begin(), dp1.end());
    int maxVal2 = *max_element(dp2.begin(), dp2.end());
    answer = max(maxVal1, maxVal2);
    
    return answer;
}