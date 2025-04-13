#include <iostream>
#include <queue>
#include <stack>
using namespace std;

int N;
stack<int> s;
queue<int> q;
int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;

    int tmp;
    for (int i = 0; i < N; i++) {
        cin >> tmp;
        q.push(tmp);
    }

    for (int i = 1; i <= N; i++) {
        if (!q.empty() && !s.empty()) {
            if (s.top() == i) {
                s.pop();
            } else if (q.front() == i) {
                q.pop();
            } else {
                s.push(q.front());
                q.pop();
                i--;
            }
        } else if (q.empty() && !s.empty()) {
            if (s.top() == i) {
                s.pop();
            } else {
                break;
            }
        } else if (!q.empty() && s.empty()) {
            if (q.front() == i) {
                q.pop();
            } else {
                s.push(q.front());
                q.pop();
                i--;
            }
        }
    }

    if (s.empty() && q.empty()) {
        cout << "Nice\n";
    } else {
        cout << "Sad\n";
    }
    return 0;
}