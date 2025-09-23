#include <string>
#include <vector>
#include <queue>

using namespace std;

struct Priority_deque {
    priority_queue<int, vector<int>, greater<int>> minQueue;
    priority_queue<int> maxQueue;
    priority_queue<int, vector<int>, greater<int>> rMinQueue;
    priority_queue<int> rMaxQueue;
    
    void push(int val) {
        minQueue.push(val);
        maxQueue.push(val);
    }
    
    void popMin() {
        if(minQueue.empty()) {
            return;
        }
        
        int minVal;
        minVal = minQueue.top();
        minQueue.pop();

        int flag = 0;
        while(!rMinQueue.empty() && minVal == rMinQueue.top()) {
            rMinQueue.pop();

            if(minQueue.empty()) {
                flag = 1;
                break;
            }

            minVal = minQueue.top();
            minQueue.pop();
        }
        
        if(flag == 0) {
            rMaxQueue.push(minVal);
        }
    }
    
    void popMax() {
        if(maxQueue.empty()) {
            return;
        }
        
        int maxVal;
        maxVal = maxQueue.top();
        maxQueue.pop();

        int flag = 0;
        while(!rMaxQueue.empty() && maxVal == rMaxQueue.top()) {
            rMaxQueue.pop();

            if(maxQueue.empty()) {
                flag = 1;
                break;
            }

            maxVal = maxQueue.top();
            maxQueue.pop();
        }
        
        if(flag == 0) {
            rMinQueue.push(maxVal);
        }
    }
    
    int getMin() {
        if(minQueue.empty()) {
            return 0;
        }
        
        int minVal;
        minVal = minQueue.top();
        minQueue.pop();

        int flag = 0;
        while(!rMinQueue.empty() && minVal == rMinQueue.top()) {
            rMinQueue.pop();

            if(minQueue.empty()) {
                flag = 1;
                break;
            }

            minVal = minQueue.top();
            minQueue.pop();
        }
        
        if(flag == 0) {
            minQueue.push(minVal);
            return minVal;
        }
        
        return 0;
    }
    
    int getMax() {
        if(maxQueue.empty()) {
            return 0;
        }
        
        int maxVal;
        maxVal = maxQueue.top();
        maxQueue.pop();

        int flag = 0;
        while(!rMaxQueue.empty() && maxVal == rMaxQueue.top()) {
            rMaxQueue.pop();

            if(maxQueue.empty()) {
                flag = 1;
                break;
            }

            maxVal = maxQueue.top();
            maxQueue.pop();
        }
        
        if(flag == 0) {
            maxQueue.push(maxVal);
            return maxVal;
        }
        
        return 0;
    }
};

using namespace std;

Priority_deque pdq;

vector<int> solution(vector<string> operations) {
    vector<int> answer;
    
    for(int i = 0; i < operations.size(); i++) {
        char cmd = operations[i][0];
        int val = stoi(operations[i].substr(2));
        if(cmd == 'I') {
            pdq.push(val);
        }
        else if(cmd == 'D') {
            if(val == 1) {
                pdq.popMax();
            } else {
                pdq.popMin();
            }
        }
    }
    
    answer.push_back(pdq.getMax());
    answer.push_back(pdq.getMin());
    
    return answer;
}