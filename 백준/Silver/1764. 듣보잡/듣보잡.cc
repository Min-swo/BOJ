#include <algorithm>
#include <iostream>
#include <map>
#include <vector>
using namespace std;

int N, M;
map<string, bool> m;
vector<string> dup;
int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        string tmp;
        cin >> tmp;
        m.insert({tmp, true});
    }

    for (int i = 0; i < M; i++) {
        string tmp;
        cin >> tmp;
        if (m.find(tmp) != m.end()) {
            dup.push_back(tmp);
        }
    }

    sort(dup.begin(), dup.end());
    cout << dup.size() << "\n";
    for (string name : dup) {
        cout << name << "\n";
    }
    return 0;
}