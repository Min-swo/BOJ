#include <string>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

bool cmp(pair<int, int> a, pair<int, int> b) {
    if (a.first != b.first) return a.first < b.first;
    return a.second > b.second;
}

vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;
    
    map<string, int> gm;
    map<string, vector<pair<int, int>>> pm;
    for(int i = 0; i < genres.size(); i++) {
        gm[genres[i]] += plays[i];
        pm[genres[i]].push_back({plays[i], i});
    }
    
    vector<pair<int, string>> v;
    for(pair<string, int> k : gm) {
        v.push_back({k.second, k.first});
    }
    
    sort(v.begin(), v.end());
    
    for (int i = v.size() - 1; i >= 0; i--) {
        vector<pair<int, int>> g = pm[v[i].second];
        sort(g.begin(), g.end(), cmp);
        for(int j = g.size() - 1; j >= 0 && j >= int(g.size()) - 2; j--) {
            answer.push_back(g[j].second);    
        }
            
    }
    

    return answer;
}