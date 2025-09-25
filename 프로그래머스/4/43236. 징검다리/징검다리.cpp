#include <string>
#include <vector>
#include <algorithm>
using namespace std;

// 10억
// log(10억) => 30
// 30번 * 50000

// 일단 정렬을 해야함
// 0 2 11 14 17 21 25
// 2 9 3 3 4 4

// K를 최소로 만들기 위해서 필요한 N의 수를 구해보자
// K가 4라고 가정 -> 2, 9 합치기 11 3 3 4 4
// 3,3 합치기 11 6 4 4 -> 굳 2
// K가 5라고 가정
// 최소값을 가지고 있자.

// 여기서 거리의 최솟값이 K일때 n으로 가능한가?

int dist;
int n;
vector<int> diff;

void init(int mDist, vector<int> rocks, int mN) {
    sort(rocks.begin(), rocks.end());
    rocks.push_back(mDist);
    
    dist = mDist;
    n = mN;
    
    diff.push_back(rocks[0]);
    for(int i = 1; i < rocks.size(); i++) {
        int d = rocks[i] - rocks[i - 1];
        diff.push_back(d);
    }
}

int getN(int k) {
    vector<int> tmp(diff);
    int cnt = 0;
    while(1) {
        int idx = -1;
        
        for(int i = 0; i < tmp.size(); i++) {
            if(tmp[i] < k) {
                cnt += 1;
                idx = i;
                break;
            }
        }
        
        if(idx == -1) {
            break;
        }
        
        int tmpVal;
        if(tmp.size() == 1) {
            if(tmp[0] < k) {
                return 0;
            }
        } else if(idx == tmp.size() - 1) {
            tmpVal = tmp[idx - 1] + tmp[idx];
            tmp.erase(tmp.begin() + idx - 1);
            tmp[idx - 1] = tmpVal;
        } else {
            tmpVal = tmp[idx] + tmp[idx + 1];
            tmp.erase(tmp.begin() + idx);
            tmp[idx] = tmpVal;
        }
    }
    
    if(cnt < n) {
        return 1;
    } else if(cnt == n) {
        return 2;
    }
    
    return 0;
}

int bSearch() {
    int left = 1;
    int right = dist+3;
    
    while(left < right) {
        int mid = left + (right - left) / 2;
        if(getN(mid) == 1) {
            left = mid + 1;
        } else if(getN(mid) == 2) {
            left = mid + 1;
        } else {
            right = mid;
        }
    }
    
    return right - 1;
}

int solution(int mDist, vector<int> rocks, int mN) {
    init(mDist, rocks, mN);
    
    return bSearch();
}