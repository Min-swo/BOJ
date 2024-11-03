#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int N;
vector<long> pos;
vector<long> neg;
int zeroCnt = 0;
int cnt = 0;

bool compare(long a, long b) { return a > b; }

int getPosSize() { return int(pos.size()); }
int getNegSize() { return int(neg.size()); }

bool isGoodNumber0(int idx, vector<long> v1, vector<long> v2) {
    for (int j = idx - 1; j > 0; j--) {
        for (int k = 0; k < j; k++) {
            if (v1[idx] == v1[k] + v1[j]) {
                return true;
            }
        }
    }

    for (int j = idx + 1; j < int(v1.size()); j++) {
        for (int k = 0; k < int(v2.size()); k++) {
            if (v1[idx] == v1[j] + v2[k]) {
                return true;
            }
        }
    }

    return false;
}

bool isDuplicate(int idx, vector<long> v) {
    if (idx > 0 && v[idx] == v[idx - 1]) {
        return true;
    }
    if (idx < int(v.size()) - 1 && v[idx] == v[idx + 1]) {
        return true;
    }

    return false;
}

bool isGoodNumber1(int idx, vector<long> v1, vector<long> v2) {
    if (isDuplicate(idx, v1)) {
        return true;
    }

    for (int j = idx - 1; j > 0; j--) {
        for (int k = 0; k < j; k++) {
            if (v1[idx] == v1[k] + v1[j]) {
                return true;
            }
        }
    }

    for (int j = idx + 1; j < int(v1.size()); j++) {
        for (int k = 0; k < int(v2.size()); k++) {
            if (v1[idx] == v1[j] + v2[k]) {
                return true;
            }
        }
    }

    return false;
}

bool isZero() {
    for (int i = 0; i < int(pos.size()); i++) {
        for (int j = 0; j < int(neg.size()); j++) {
            if (pos[i] + neg[j] == 0) {
                return true;
            }
        }
    }
    return false;
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    for (int i = 0; i < N; i++) {
        long tmp;
        cin >> tmp;

        if (tmp > 0) {
            pos.push_back(tmp);
        } else if (tmp < 0) {
            neg.push_back(tmp);
        } else {
            zeroCnt += 1;
        }
    }
    sort(pos.begin(), pos.end());
    sort(neg.begin(), neg.end(), compare);

    if (zeroCnt == 0) {
        for (int i = 0; i < getPosSize(); i++) {
            if (isGoodNumber0(i, pos, neg)) {
                cnt += 1;
            }
        }
        for (int i = 0; i < getNegSize(); i++) {
            if (isGoodNumber0(i, neg, pos)) {
                cnt += 1;
            }
        }
    } else if (zeroCnt == 1 || zeroCnt == 2) {
        if (isZero()) {
            cnt += zeroCnt;
        }

        for (int i = 0; i < getPosSize(); i++) {
            if (isGoodNumber1(i, pos, neg)) {
                cnt += 1;
            }
        }
        for (int i = 0; i < getNegSize(); i++) {
            if (isGoodNumber1(i, neg, pos)) {
                cnt += 1;
            }
        }
    } else {
        cnt += zeroCnt;

        for (int i = 0; i < getPosSize(); i++) {
            if (isGoodNumber1(i, pos, neg)) {
                cnt += 1;
            }
        }
        for (int i = 0; i < getNegSize(); i++) {
            if (isGoodNumber1(i, neg, pos)) {
                cnt += 1;
            }
        }
    }

    cout << cnt << "\n";
    return 0;
}
