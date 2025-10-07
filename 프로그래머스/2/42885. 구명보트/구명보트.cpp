#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<int> people, int limit) {
    int cnt = 0;
    sort(people.begin(), people.end());
    
    int left = 0;
    int right = people.size() - 1;
    while(left <= right) {
        if(people[left] + people[right] <= limit) {
            left += 1;
        }
        right -= 1;
        cnt += 1;
    }

    return cnt;
}