#include <algorithm>
#include <deque>
#include <iostream>
#include <string>
using namespace std;

int T;
int len;
string cmd, arr;
deque<int> deq;
int r = 0;

void del() {
    if (r == 0) {
        deq.pop_front();
    } else {
        deq.pop_back();
    }
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> T;
    for (int t = 0; t < T; t++) {
        int flag = 0;
        cin >> cmd >> len >> arr;
        int start, end;
        if (len != 0) {
            for (int i = 0; i < int(arr.size()); i++) {
                if (arr[i] == '[') {
                    start = i + 1;
                }

                if (arr[i] == ',' || arr[i] == ']') {
                    end = i;
                    int tmp = stoi(arr.substr(start, end - start));
                    deq.push_back(tmp);
                    start = end + 1;
                }
            }
        }

        r = 0;
        for (int i = 0; i < int(cmd.size()); i++) {
            if (cmd[i] == 'R') {
                r = !r;
            } else if (cmd[i] == 'D') {
                if (deq.empty()) {
                    flag = 1;
                    break;
                }

                del();
            }
        }

        if (flag == 0) {
            cout << "[";
            if (r == 0) {
                for (int i = 0; i < int(deq.size()); i++) {
                    cout << deq[i];
                    if (i != int(deq.size()) - 1) {
                        cout << ",";
                    }
                }
            } else {
                for (int i = int(deq.size()) - 1; i >= 0; i--) {
                    cout << deq[i];
                    if (i != 0) {
                        cout << ",";
                    }
                }
            }

            cout << "]\n";
        } else {
            cout << "error\n";
        }

        deq.clear();
    }
    return 0;
}