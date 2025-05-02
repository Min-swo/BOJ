#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool cmp(int a, int b) {
    string sa = to_string(a);
    string sb = to_string(b);
    return sa + sb > sb + sa;
}

string solution(vector<int> numbers) {
    string answer = "";
    
    sort(numbers.begin(), numbers.end(), cmp);
    
    for(int number : numbers) {
        answer += to_string(number);
    }
    
    if(answer[0] == '0') {
        answer = "0";
    }
    return answer;
}