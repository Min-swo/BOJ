#include <string>
#include <vector>
#include <queue>

using namespace std;

long long solution(int n, vector<int> works) {
    long long answer = 0;
    priority_queue<int> pq(works.begin(), works.end());
    
    for(int i = 0; i < n; i++) {
        int tmp = pq.top();
        if(tmp == 0) {
            break;
        }
        pq.pop();
        pq.push(tmp-1);
    }
    
    long long sum = 0;
    while(!pq.empty()) {
        int k = pq.top();
        pq.pop();
        sum += k * k;
    }
    answer = sum;
    return answer;
}