#include <iostream>
using namespace std;

int T;
long long M, N, x, y;
long long ans;
int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> T;
    for (int t = 0; t < T; t++) {
        cin >> M >> N >> x >> y;

        int i = 1;
        while (1) {
            long long k = x + (i - 1) * M;
            // cout << k << " " << k % N << "\n";
            if (k > M * N) {
                ans = -1;
                break;
            }
            if (y == N) {
                if (k % N == 0) {
                    ans = k;
                    break;
                }
            }

            if (k % N == y) {
                ans = k;
                break;
            }
            i++;
        }

        cout << ans << "\n";
    }
    return 0;
}