#include <string>
#include <vector>
#include <map>

using namespace std;

int solution(vector<vector<string>> clothes) {
    int answer = 1;
    
    map<string, int> m;
    for(vector<string> clothe : clothes) {
        m[clothe[1]]++;
    }
    
    for(pair<string, int> p : m) {
        answer = answer * (p.second + 1);
    }
    answer--;
    
    return answer;
}