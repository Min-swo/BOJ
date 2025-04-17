#include <iostream>
#include <map>
using namespace std;

int N, M;
map<string, string> m;
int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;

    string domain, password;
    for (int i = 0; i < N; i++) {
        cin >> domain >> password;
        m.insert({domain, password});
    }

    for (int i = 0; i < M; i++) {
        cin >> domain;
        cout << m[domain] << "\n";
    }
}