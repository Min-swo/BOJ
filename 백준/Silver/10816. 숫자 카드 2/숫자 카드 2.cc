#include <algorithm>
#include <iostream>
using namespace std;

int binarySearchRight(int *arr, int size, int k) {
    int left = 0;
    int right = size - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] < k) {
            left = mid + 1;
        } else if (arr[mid] > k) {
            right = mid - 1;
        } else {
            if (mid + 1 < size && arr[mid + 1] == k) {
                left = mid + 1;
            } else {
                return mid;
            }
        }
    }

    return -1;
}

int binarySearchLeft(int *arr, int size, int k) {
    int left = 0;
    int right = size - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] < k) {
            left = mid + 1;
        } else if (arr[mid] > k) {
            right = mid - 1;
        } else {
            if (mid - 1 >= 0 && arr[mid - 1] == k) {
                right = mid - 1;
            } else {
                return mid;
            }
        }
    }

    return -1;
}

int getCount(int *arr, int size, int idx, int k) {
    int cnt = 1;
    for (int i = idx + 1; i < size; i++) {
        if (arr[i] != k) {
            break;
        }
        cnt++;
    }
    for (int i = idx - 1; i >= 0; i--) {
        if (arr[i] != k) {
            break;
        }
        cnt++;
    }

    return cnt;
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;

    int arr[N];
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    sort(arr, arr + N);

    int M;
    cin >> M;

    int k;
    for (int i = 0; i < M; i++) {
        cin >> k;
        int rightIdx = binarySearchRight(arr, N, k);

        if (rightIdx == -1) {
            cout << 0 << " ";
        } else {
            int leftIdx = binarySearchLeft(arr, N, k);
            cout << rightIdx - leftIdx + 1 << " ";
        }
    }
    cout << "\n";
    return 0;
}