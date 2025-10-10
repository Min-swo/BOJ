#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<vector<int>> sizes) {
    for(int i = 0; i < sizes.size(); i++) {
        if(sizes[i][0] < sizes[i][1]) {
            int tmp = sizes[i][0];
            sizes[i][0] = sizes[i][1];
            sizes[i][1] = tmp;
        }
    }
    
    int maxValRow = 0;
    int maxValCol = 0;
    for(int i = 0; i < sizes.size(); i++) {
        maxValRow = max(maxValRow, sizes[i][0]);
        maxValCol = max(maxValCol, sizes[i][1]);
    }
    
    return maxValRow * maxValCol;
}