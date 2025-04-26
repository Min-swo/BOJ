#include <iostream>
#include <vector>
using namespace std;

int N;
vector<int> v;
int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;

    int tmp;
    for (int i = 0; i < N; i++) {
        cin >> tmp;
        v.push_back(tmp);
    }

    int cnt = 1;

    int first = v[0];
    int second = 0;

    int startIdx = 0;
    int firstIdx = 0;
    int secondIdx = -1;
    for (int i = 1; i < N; i++) {
        cnt++;
        if (v[i] != first) {
            second = v[i];
            secondIdx = i;
            firstIdx = i - 1;
            break;
        }
    }

    int maxVal = cnt;
    for (int i = secondIdx + 1; i < N; i++) {
        if (secondIdx == -1) {
            break;
        }

        if (v[i] == first) {
            firstIdx = i;
        } else if (v[i] == second) {
            secondIdx = i;
        } else {
            cnt -= firstIdx - startIdx + 1;

            startIdx = firstIdx + 1;

            first = second;
            firstIdx = secondIdx;

            second = v[i];
            secondIdx = i;
        }
        cnt++;
        maxVal = max(maxVal, cnt);
    }

    cout << maxVal << "\n";
    return 0;
}