#include <string>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

int bfs(vector<int> numbers, int t) {
    sort(numbers.begin(), numbers.end());
    int cnt = 0;
    queue<pair<int, int>> q;
    
    q.push({0, 0});
    if(numbers[0] <= t) {
        q.push({numbers[0], 0});
    }
    
    while(!q.empty()) {
        int cur = q.front().first;
        int idx = q.front().second;
        q.pop();
        
        if(t == cur) {
            cnt += 1;
        }
        
        if(idx < int(numbers.size()) - 1 && cur < t) {
            q.push({cur, idx+1});
        }
        
        if(idx < int(numbers.size()) - 1 && cur + numbers[idx+1] <= t) {
            q.push({cur + numbers[idx+1], idx+1});
        }
        
    }
    
    return cnt;
}

int solution(vector<int> numbers, int target) {
    int answer = 0;
    
    int sum = 0;
    for(int n : numbers) {
        sum += n;
    }
    
    if(sum < target) {
        answer = 0;
    } else if(sum > target) {
        int diff = sum - target;
        if(diff % 2 != 0) {
            answer = 0;
        } else {
            int t = diff / 2;
            answer = bfs(numbers, t);
        }
    } else {
        answer = 1;
    }
    
    return answer;
    
    
    // a + b + c = 16
    // 10
    // 6
    // 2(a + b) = 6
    // a, b, c => 3
}