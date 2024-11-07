#include <cmath>
#include <iostream>
using namespace std;

int N, r, c;
int map[2][2];

int main(void) {
    cin >> N >> r >> c;

    int cnt = 0;
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            map[i][j] = cnt++;
        }
    }

    int count = 0;
    int k = N - 1;
    while (k > 0) {
        int sr = r / pow(2, k);
        int sc = c / pow(2, k);
        if (sr == 0 && sc == 0) {
            count += pow(pow(2, k), 2) * 0;
        } else if (sr == 0 && sc == 1) {
            count += pow(pow(2, k), 2) * 1;
        } else if (sr == 1 && sc == 0) {
            count += pow(pow(2, k), 2) * 2;
        } else if (sr == 1 && sc == 1) {
            count += pow(pow(2, k), 2) * 3;
        }
        r = fmod(r, pow(2, k));
        c = fmod(c, pow(2, k));
        k--;
    }

    count += map[r][c];

    cout << count << "\n";
}