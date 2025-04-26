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
int freq[257];

int minH = 257;
int maxH = -1;
int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M >> B;
    for (int i = 0; i < N * M; i++) {
        int h;
        cin >> h;
        freq[h]++;
        minH = min(minH, h);
        maxH = max(maxH, h);
    }

    pii minVal = {N * M * maxH * 2, 0};
    for (int h = minH; h <= maxH; h++) {
        int del = 0;
        int put = 0;

        for (int i = 0; i <= 256; i++) {
            if (freq[i] == 0) {
                continue;
            }

            int diff = i - h;
            if (diff > 0) {
                del = del + diff * freq[i];
            } else {
                put = put + diff * -1 * freq[i];
            }
        }
        if (B + del >= put) {
            minVal = min(minVal, {del * 2 + put, h}, cmp);
        }
    }

    cout << minVal.first << " " << minVal.second << "\n";
    return 0;
}