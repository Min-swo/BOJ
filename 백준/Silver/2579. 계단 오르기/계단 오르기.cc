#include <iostream>
using namespace std;

int getMax(int a, int b) {
    if (a < b) {
        return b;
    }
    return a;
}

int main(void) {
    int N;
    cin >> N;

    int scores[N];
    for (int i = 0; i < N; i++) {
        cin >> scores[i];
    }

    int dpOne[N];
    int dpTwo[N];
    dpOne[0] = scores[0];
    dpTwo[0] = 0;
    dpOne[1] = dpOne[0] + scores[1];
    dpTwo[1] = scores[1];
    dpOne[2] = dpTwo[1] + scores[2];
    dpTwo[2] = dpOne[0] + scores[2];

    for (int i = 3; i < N; i++) {
        dpOne[i] = dpTwo[i - 1] + scores[i];
        dpTwo[i] = getMax(dpOne[i - 2], dpTwo[i - 2]) + scores[i];
    }

    int max = getMax(dpOne[N - 1], dpTwo[N - 1]);
    cout << max << "\n";
    return 0;
}