#include <string>
#include <vector>

using namespace std;

string numbers;
vector<bool> visited(10000000, false);
vector<bool> tmpVisited(8, false);

bool isPrime(int num) {
    if(num == 0 || num == 1) {
        return false;
    }
    
    if(num == 2) {
         return true;
    }
    
    for(int i = 2; i * i <= num; i++) {
        if(num % i == 0) {
            return false;
        }
    }
    
    return true;
}

int dfs(string str, int depth, int end) {
    if(depth == end) {
        int num = stoi(str);
        if(!visited[num] && isPrime(num)) {
            visited[num] = true;
            return 1;
        }
        return 0;
    }
    
    int result = 0;
    result += dfs(str, depth + 1, end);
    for(int i = 0; i < end; i++) {
        if(tmpVisited[i]) {
            continue;
        }
        
        tmpVisited[i] = true;
        result += dfs(str + numbers[i], depth + 1, end);
        tmpVisited[i] = false;
    }
    return result;
}

int solution(string mNumbers) {
    numbers = mNumbers;
    return dfs("0", 0, numbers.length());
}



// 1234
// 0  1
// 