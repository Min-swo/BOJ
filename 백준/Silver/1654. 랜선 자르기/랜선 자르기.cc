#include <iostream>
using namespace std;

int getSum(int *arr, int div, int K) {
    int sum = 0;
    for (int i = 0; i < K; i++) {
        sum += arr[i] / div;
    }
    return sum;
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int K, N;
    cin >> K >> N;

    int arr[K];
    for (int i = 0; i < K; i++) {
        cin >> arr[i];
    }

    int max = 0;
    for (int i = 0; i < K; i++) {
        if (max < arr[i]) {
            max = arr[i];
        }
    }

    long long left = 1;
    long long right = max;
    long long mid = 0;
    while (left <= right) {
        mid = left + (right - left) / 2;

        if (getSum(arr, mid, K) < N) {
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }

    cout << right << "\n";

    return 0;
}