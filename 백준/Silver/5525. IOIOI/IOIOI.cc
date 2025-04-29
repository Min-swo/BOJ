#include <iostream>
#include <vector>
using namespace std;

int N, M;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;

    char tmp;
    int state = 0;
    int cnt = 0;

    vector<int> v;
    for (int i = 0; i < M; i++) {
        cin >> tmp;
        if (tmp == 'I') {
            if (state == 2) {
                cnt++;
            } else {
                if (cnt != 0) {
                    v.push_back(cnt);
                    cnt = 0;
                }
            }
            state = 1;
        } else {
            if (state == 1) {
                state++;
            } else {
                state = 0;
            }
        }
    }

    if (cnt != 0) {
        v.push_back(cnt);
        cnt = 0;
    }

    int total = 0;
    for (int i : v) {
        if (i > N) {
            total += i - N + 1;
        } else if (i == N) {
            total += 1;
        }
    }
    cout << total << "\n";
    return 0;
}