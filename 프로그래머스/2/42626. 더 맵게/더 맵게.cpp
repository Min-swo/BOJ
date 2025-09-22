#include <string>
#include <vector>
#include <queue>
using namespace std;

int solution(vector<int> scoville, int K) {
    priority_queue<int, vector<int>, greater<int>> pq(scoville.begin(), scoville.end());
    
    int cnt = 0;
    while(1) {
        if(pq.size() == 1) {
            if(pq.top() >= K) {
                return cnt;
            }
            return -1;
        }
        
        int first = pq.top();
        pq.pop();
        int second = pq.top();
        pq.pop();
        
        if(second == 0) {
            return -1;
        }
        
        if(first >= K) {
            break;
        }
        
        int mixed = first + second * 2;
        pq.push(mixed);
        cnt++;
    }
    
    return cnt;
}