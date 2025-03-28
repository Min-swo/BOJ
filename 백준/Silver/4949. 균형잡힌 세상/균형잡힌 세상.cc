#include <iostream>
#include <stack>
using namespace std;

int main(void) {
    stack<char> s;
    char c;
    string str;
    int idx;

    while (1) {
        idx = 0;
        str = "";
        getline(cin, str);

        while (!s.empty()) {
            s.pop();
        }

        if (str[0] == '.') {
            break;
        }

        while (1) {
            c = str[idx++];
            if (c == '.') {
                break;
            }

            if (c == '(' || c == '[') {
                s.push(c);
            } else if (c == ')') {
                if (!s.empty() && s.top() == '(') {
                    s.pop();
                } else {
                    s.push(c);
                    break;
                }
            } else if (c == ']') {
                if (!s.empty() && s.top() == '[') {
                    s.pop();
                } else {
                    s.push(c);
                    break;
                }
            }
        }

        if (s.empty()) {
            cout << "yes" << "\n";
        } else {
            cout << "no" << "\n";
        }
    }

    return 0;
}