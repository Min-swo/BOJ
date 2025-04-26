#include <iostream>
using namespace std;

typedef std::pair<int, int> pii;

bool cmp(const pii &a, const pii &b) {
    if (a.first != b.first)
        return a.first < b.first;
    return a.second > b.second;
}

#define MAX 501
int N, M, B;
int map[MAX * MAX];

int minH = 257;
int maxH = -1;
int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M >> B;
    for (int i = 0; i < N * M; i++) {
        cin >> map[i];
        minH = min(minH, map[i]);
        maxH = max(maxH, map[i]);
    }

    pii minVal = {N * M * maxH * 2, 0};
    for (int h = minH; h <= maxH; h++) {
        int del = 0;
        int put = 0;

        for (int i = 0; i < N * M; i++) {
            int diff = map[i] - h;
            if (diff > 0) {
                del = del + diff;
            } else {
                put = put + diff * -1;
            }
        }
        if (B + del >= put) {
            minVal = min(minVal, {del * 2 + put, h}, cmp);
        }
    }

    cout << minVal.first << " " << minVal.second << "\n";
    return 0;
}