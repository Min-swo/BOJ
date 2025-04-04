#include <iostream>
using namespace std;

const int MAX = 10;
int N, K;

int coin[MAX];

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> K;
    for (int i = 0; i < N; i++) {
        cin >> coin[i];
    }

    int cnt = 0;
    for (int i = N - 1; i >= 0; i--) {
        int div = K / coin[i];
        if (div != 0) {
            cnt += div;
            K = K % coin[i];
        }
    }

    cout << cnt << "\n";
    return 0;
}