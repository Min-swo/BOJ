#include <iostream>
using namespace std;

int T, N, M;

unsigned long long answer(unsigned long long a, unsigned long long b) {
    unsigned long long u = 1;
    unsigned long long d = 1;
    int l, s;
    if (b < a - b) {
        l = a - b;
        s = b;
    } else {
        l = b;
        s = a - b;
    }
    for (int i = a; i > l; i--) {
        u *= i;
    }
    for (int i = 2; i <= s; i++) {
        d *= i;
    }

    return u / d;
}

int main(void) {
    cin >> T;
    for (int tc = 0; tc < T; tc++) {
        cin >> N >> M;
        cout << answer(M, N) << "\n";
    }
    return 0;
}