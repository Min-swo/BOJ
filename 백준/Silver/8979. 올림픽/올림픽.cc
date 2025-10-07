#include <iostream>
#include <vector>
using namespace std;

struct Medal {
    int gold;
    int silver;
    int bronze;

    bool operator>(Medal a) {
        if (gold == a.gold) {
            if (silver == a.silver) {
                return bronze > a.bronze;
            }
            return silver > a.silver;
        }

        return gold > a.gold;
    }
};

int N, K;
vector<Medal> medals(1004);

int main(void) {
    cin >> N >> K;
    for (int i = 1; i <= N; i++) {
        int idx, g, s, b;
        cin >> idx >> g >> s >> b;
        medals[idx] = {g, s, b};
    }

    int cnt = 0;
    for (int i = 1; i <= N; i++) {
        if (i == K) {
            continue;
        }

        if (medals[i] > medals[K]) {
            cnt++;
        }
    }

    cout << cnt + 1 << "\n";
    return 0;
}