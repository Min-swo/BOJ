#include <string>
#include <vector>
#include <queue>
using namespace std;

typedef pair<int, int> pii;
typedef pair<pii, int> piii;

int solution(vector<vector<int>> jobs) {
    
    priority_queue<piii, vector<piii>, greater<piii>> rPq;
    priority_queue<piii, vector<piii>, greater<piii>> wPq;
    
    for(int i = 0; i < jobs.size(); i++) {
        rPq.push({{jobs[i][0], jobs[i][1]}, i});
    }
    
    int cnt = 0;
    int sum = 0;
    int cTime = 0;
    while(1) {
        while(!rPq.empty()) {
            piii tmp = rPq.top();
            if(cTime < tmp.first.first) {
                break;
            }
            wPq.push({{tmp.first.second, tmp.first.first}, tmp.second});
            rPq.pop();
        }
        
        if(wPq.empty()) {
            if(cnt == jobs.size()) {
                break;
            } else {
                cTime += 1;
                continue;                
            }
        }
        
        piii job = wPq.top();
        wPq.pop();
        
        cnt += 1;
        cTime += job.first.first;
        sum += (cTime - job.first.second);
    }
    
    return sum / jobs.size();
}