#include <algorithm>
#include <iostream>
using namespace std;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M;

    cin >> N;
    int *targetArray = new int[N];
    for (int i = 0; i < N; i++) {
        cin >> targetArray[i];
    }
    sort(targetArray, targetArray + N);

    cin >> M;
    for (int i = 0; i < M; i++) {
        int search;
        cin >> search;
        if (binary_search(targetArray, targetArray + N, search)) {
            cout << 1 << "\n";
        } else {
            cout << 0 << "\n";
        }
    }

    return 0;
}