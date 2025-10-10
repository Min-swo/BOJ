#include <string>
#include <vector>
#include <algorithm>
using namespace std;

#define OFFSET 30000

vector<vector<int>> inRoutes(60004);
vector<vector<int>> outRoutes(60004);
vector<bool> visited(10004, false);

int solution(vector<vector<int>> routes) {
    for(int i = 0; i < routes.size(); i++) {
        inRoutes[routes[i][0] + OFFSET].push_back(i);
        outRoutes[routes[i][1] + OFFSET].push_back(i);
    }  
    
    int cnt = 0;
    vector<int> tmp;
    for(int i = 0; i < 60001; i++) {
        for(int j = 0; j < inRoutes[i].size(); j++) {
            if(visited[inRoutes[i][j]]) {
                continue;
            }
            
            tmp.push_back(inRoutes[i][j]);
        }
        bool flag = false;
        for(int j = 0; j < outRoutes[i].size(); j++) {
            if(!visited[outRoutes[i][j]]) {
                flag = true;
                break;
            }
        }
        
        if(flag) {
            cnt += 1;
            for(int i = 0; i < tmp.size(); i++) {
                visited[tmp[i]] = true;
            }
            tmp.clear();
        }
    }
    
    return cnt;
}