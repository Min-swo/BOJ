#include <string>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

// K분이 가능한가? -> n명이 ? -> 어떻게 알 수 있지?
// K분동안 몇명이 최대로 가능한가 -> 다 더하면 최대 인원수

vector<int> times;

long long getTotalCnt(long long k) {
    long long cnt = 0;
    for(int i = 0; i < times.size(); i++) {
        cnt += k / times[i];
    }
    
    return cnt;
}

long long bsearch(long long n) {
    long long left = 1;
    long long right = LONG_MAX / 100000;
    
    while(left < right) {
        long long mid = left + (right - left) / 2;
        
        if(getTotalCnt(mid) < n) {
            left = mid + 1;
        } else {
            right = mid;
        }
    }
    
    return left;
}

long long solution(int n, vector<int> mTimes) {
    times = mTimes;
    return bsearch(n);
}