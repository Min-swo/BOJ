#include <string>
#include <vector>
#include <deque>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;
    for(vector<int> command : commands) {
        deque<int> copy(array.begin(), array.end());
        int size = copy.size();
        
        int i = command[0];
        int j = command[1];
        int k = command[2];
        
        for(int cnt = 0; cnt < i - 1; cnt++) {
            copy.pop_front();
        }
        
        for(int cnt = 0; cnt < size - j; cnt++) {
            copy.pop_back();
        }
        
        sort(copy.begin(), copy.end());
        
        answer.push_back(copy[k-1]);
    }
    return answer;
}