#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> num(31);

int solution(int n, vector<int> lost, vector<int> reserve) {    
    for(int i = 1; i <= n; i++) {
        num[i] = 1;
    }
    
    for(int i = 0; i < reserve.size(); i++) {
        num[reserve[i]] += 1;
    }
    for(int i = 0; i < lost.size(); i++) {
        num[lost[i]] -= 1;
    }
    
    sort(lost.begin(), lost.end());
    
    for(int i = 0; i < lost.size(); i++) {
        if(num[lost[i]] != 0) {
            continue;
        } 
        
        int front = lost[i] - 1;
        int back = lost[i] + 1;
        if(front >= 1 && num[front] > 1) {
            num[lost[i]] += 1;
            num[front] -= 1;
        }  else if(back <= n && num[back] > 1) {
            num[lost[i]] += 1;
            num[back] -= 1;
        }
    }
    
    int cnt = 0;
    for(int i = 1; i <= n; i++) {
        if(num[i] > 0) {
            cnt += 1;
        } 
    }
    
    return cnt;
}