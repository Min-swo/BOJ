#include <string>
#include <vector>

using namespace std;

typedef pair<int, int> pii;

int getBrown(int yW, int yH) {
    return (yW + 2) * (yH + 2) - yW * yH;
}

vector<pii> getYellows(int yellow) {
    vector<pii> yellows;
    for(int i = 1; i * i <= yellow; i++) {
        if(yellow % i == 0) {
            yellows.push_back({yellow / i, i});
        }
    }
    return yellows;
}

vector<int> solution(int brown, int yellow) {
    vector<int> answer;
    
    vector<pii> yellows = getYellows(yellow);
    for(int i = 0; i < yellows.size(); i++) {
        int yW = yellows[i].first;
        int yH = yellows[i].second;
        
        if(brown == getBrown(yW, yH)) {
            answer.push_back(yW + 2);
            answer.push_back(yH + 2);
        }
    }
    
    return answer;
}