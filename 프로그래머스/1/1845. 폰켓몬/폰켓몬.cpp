#include <vector>
using namespace std;

int solution(vector<int> nums)
{
    int N = nums.size();
    int type[200001];
    
    for(int i = 0; i < 200001; i++) {
        type[i] = 0;
    }
    
    for (int i : nums) {
        type[i] = 1;
    }
    
    int cnt = 0;
    for(int i = 1; i < 200001; i++) {
        if(type[i] == 1) {
            cnt++;
        }
    }
    
    int answer = 0;
    
    if(cnt >= N / 2) {
        answer = N / 2;
    } else {
        answer = cnt;
    }
    
    return answer;
}