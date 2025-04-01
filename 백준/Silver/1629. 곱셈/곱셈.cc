#include <iostream>
using namespace std;

unsigned long long pow(unsigned long a, int k) {
    unsigned long long result = 1;
    for (int i = 0; i < k; i++) {
        result = result * a;
    }
    return result;
}

unsigned long long getRem(unsigned long long a, unsigned long long b,
                          unsigned long long c, int depth) {
    unsigned long long k;

    if (b == 1) {
        return a % c;
    }

    if (a == c) {
        return 0;
    } else if (a < c) {
        unsigned long long r = 0;
        k = c - a;
        if (k < a) {
            r = pow(k, 2) % c;
        } else {
            r = pow(a, 2) % c;
        }

        if (b % 2 == 0) {
            return getRem(r, b / 2, c, depth + 1);
        } else {
            return getRem(getRem(r, b / 2, c, depth + 1) *
                              getRem(a, 1, c, depth + 1),
                          1, c, depth + 1);
        }
    } else if (a > c) {
        unsigned long long r = a % c;
        return getRem(r, b, c, depth + 1);
    }

    return 0;
}

int main(void) {
    unsigned long long a, b, c;
    cin >> a >> b >> c;

    cout << getRem(a, b, c, 0) << "\n";
    return 0;
}