#include <iostream>
#include <stack>
using namespace std;

int N;
int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;

    int cnt = 0;
    for (int i = 0; i < N; i++) {
        stack<char> s;
        string str;
        cin >> str;
        for (int i = 0; i < int(str.size()); i++) {
            if (s.empty()) {
                s.push(str[i]);
            } else {
                if (str[i] == s.top()) {
                    s.pop();
                } else {
                    s.push(str[i]);
                }
            }
        }

        if (s.empty()) {
            cnt++;
        }
    }

    cout << cnt << "\n";
    return 0;
}