#include <iostream>
using namespace std;

#define MAX 100000

int arr[MAX];
int N, K;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> K;

    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    int maxValue = 0;
    int pSum = 0;
    for (int i = 0; i < K; i++) {
        pSum += arr[i];
    }

    maxValue = pSum;
    for (int i = 0; i < N - K; i++) {
        pSum -= arr[i];
        pSum += arr[i + K];

        maxValue = max(maxValue, pSum);
    }

    cout << maxValue << "\n";
    return 0;
}