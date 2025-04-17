#include <iostream>
#include <map>
using namespace std;

int T, N;
map<string, int> m;
int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> T;
    for (int t = 0; t < T; t++) {
        cin >> N;
        string name, type;

        m.clear();
        for (int i = 0; i < N; i++) {
            cin >> name >> type;
            if (m.find(type) != m.end()) {
                m[type]++;
            } else {
                m[type] = 1;
            }
        }

        int cnt = 1;
        for (pair<string, int> p : m) {
            cnt *= (p.second + 1);
        }
        cnt -= 1;

        cout << cnt << "\n";
    }
    return 0;
}