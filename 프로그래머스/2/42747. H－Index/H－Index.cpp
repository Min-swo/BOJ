#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<int> citations) {
    int answer = 0;
    sort(citations.begin(), citations.end());
    
    int left = 0;
    int right = citations[citations.size() - 1];

    while(left <= right) {
        int mid = left + (right - left) / 2;
        
        int cnt = 0;
        for(int citation : citations) {
            if(citation >= mid) {
                cnt++;
            }
        }
        
        if(cnt < mid) {
            right = mid - 1;
        } else {
            answer = mid;
            left = mid + 1;
        }
    }
    
    return answer;
}