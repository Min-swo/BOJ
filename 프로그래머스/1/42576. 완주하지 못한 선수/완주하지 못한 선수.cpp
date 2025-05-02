#include <string>
#include <map>
#include <vector>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    map<string, int> m;
    
    // for(string s : participant) {
    //     m[s] = 0;
    // }
    
    for(string s : participant) {
        m[s]++;
    }
    
    for(string s : completion) {
        m[s]--;
    }
    
    string answer = "";
    for(string s : participant) {
        if(m[s] != 0) {
            answer = s;
        }
    }
    return answer;
}