#include <string>
#include <vector>
#include <queue>
#include <unordered_map>
using namespace std;

vector<string> words;
unordered_map<string, bool> visited;

void init(vector<string> mWords) {
    words = mWords;
}

bool isSafe(string cur, string next) {
    int cnt = 0;
    for(int i = 0; i < cur.length(); i++) {
        if(cur[i] != next[i]) {
            cnt += 1;
        }
    }
    
    return cnt < 2;
}

int bfs(string start, string end) {
    queue<pair<string, int>> q;
    q.push({start, 0});
    visited[start] = true;
    
    while(!q.empty()) {
        pair<string, int> cur = q.front();
        q.pop();
        
        string curWord = cur.first;
        int curCnt = cur.second;
        
        if(curWord == end) {
            return curCnt;
        }
        
        for(int i = 0; i < words.size(); i++) {
            string nextWord = words[i];
            int nextCnt = curCnt + 1;
            if(!visited[nextWord] && isSafe(curWord, nextWord)) {
                q.push({nextWord, nextCnt});
                visited[nextWord] = true;
            }
        }
    }
    
    return 0;
}

int solution(string begin, string target, vector<string> mWords) {
    init(mWords);
    return bfs(begin, target);
}