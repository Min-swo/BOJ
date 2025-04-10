#include <iostream>
#include <queue>
using namespace std;

typedef pair<int, char> pic;

string target;
string bomb;
deque<pic> dq;
int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> target;
    cin >> bomb;

    for (int i = 0; i < int(target.size()); i++) {
        char c = target[i];
        if (dq.empty() || dq.back().first == 0) {
            if (bomb[0] == c) {
                dq.push_back({1, c});
            } else {
                dq.push_back({0, c});
            }
        } else {
            for (int j = 1; j < int(bomb.size()); j++) {
                if (dq.back().first == j) {
                    if (bomb[j] == c) {
                        dq.push_back({j + 1, c});
                    } else if (bomb[0] == c) {
                        dq.push_back({1, c});
                    } else {
                        dq.push_back({0, c});
                    }
                    break;
                }
            }
        }

        if (dq.back().first == int(bomb.size())) {
            while (!dq.empty() && dq.back().first != 1) {
                dq.pop_back();
            }
            dq.pop_back();
        }
    }

    if (int(dq.size()) == 0) {
        cout << "FRULA\n";
    } else {
        while (!dq.empty()) {
            cout << dq.front().second;
            dq.pop_front();
        }
        cout << "\n";
    }
    return 0;
}