#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

long N, M;
long height = 0;
long targetIdx = -1;
long ans = 0;
vector<long> treeHeights;

bool compare(long a, long b) { return a > b; }

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;
    for (long i = 0; i < N; i++) {
        long tmpHeight;
        cin >> tmpHeight;
        treeHeights.push_back(tmpHeight);
    }
    treeHeights.push_back(0);
    N += 1;

    sort(treeHeights.begin(), treeHeights.end(), compare);

    for (long i = 1; true; i++) {
        if (height >= M) {
            targetIdx = i - 1;
            break;
        }
        height += (treeHeights[i - 1] - treeHeights[i]) * i;
    }

    if (height == M) {
        ans = treeHeights[targetIdx];
    } else {
        ans = treeHeights[targetIdx] + (height - M) / targetIdx;
    }
    cout << ans;
    return 0;
}