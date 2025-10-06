#include <iostream>
using namespace std;

int H, W, N, M;

int main(void) {
    cin >> H >> W >> N >> M;

    int a = H / (N + 1);
    if (H % (N + 1) != 0) {
        a++;
    }
    int b = W / (M + 1);
    if (W % (M + 1) != 0) {
        b++;
    }

    cout << a * b << "\n";
    return 0;
}