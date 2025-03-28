#include <algorithm>
#include <iostream>
using namespace std;

bool binarySearch(int *arr, int max, int k) {
    int left = 0;
    int right = max - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] == k) {
            return true;
        } else if (arr[mid] < k) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    return false;
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M;

    cin >> N;
    int target[N];
    for (int i = 0; i < N; i++) {
        cin >> target[i];
    }
    sort(target, target + N);

    cin >> M;
    int check;
    for (int i = 0; i < M; i++) {
        cin >> check;
        if (binarySearch(target, N, check)) {
            cout << 1 << " ";
        } else {
            cout << 0 << " ";
        }
    }
    cout << "\n";
    return 0;
}