#include <algorithm>
#include <iostream>
using namespace std;

#define MAX 1000000
int length[MAX];

int N, M;
int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> M >> N;

    for (int i = 0; i < N; i++) {
        cin >> length[i];
    }

    sort(length, length + N);

    int left = 1;
    int right = length[N - 1];
    while (left <= right) {
        int mid = left + (right - left) / 2;

        int sum = 0;
        for (int i = 0; i < N; i++) {
            sum += length[i] / mid;
        }

        if (sum < M) {
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }
    cout << right << "\n";
    return 0;
}