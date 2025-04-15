#include <iostream>
#include <set>
#include <vector>
using namespace std;

typedef pair<string, string> pss;

int N;
vector<pss> logs;
set<string, greater<string>> entered;
set<string> leaved;
int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    string name, action;
    for (int i = 0; i < N; i++) {
        cin >> name >> action;
        logs.push_back({name, action});
    }

    for (auto it = logs.rbegin(); it != logs.rend(); it++) {
        pss log = *it;
        name = log.first;
        action = log.second;

        if (entered.find(name) == entered.end()) {
            if (action.compare("leave") == 0) {
                leaved.insert(name);
            } else {
                if (leaved.find(name) == leaved.end()) {
                    entered.insert(name);
                }
            }
        }
    }

    for (string name : entered) {
        cout << name << "\n";
    }
    return 0;
}