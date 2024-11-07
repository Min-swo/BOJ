#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int N, M;
string tmp;
vector<string> before;
vector<string> result;
int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;

    for (int i = 0; i < N; i++) {
        cin >> tmp;
        before.push_back(tmp);
    }
    sort(before.begin(), before.end());

    for (int i = 0; i < M; i++) {
        cin >> tmp;
        if (binary_search(before.begin(), before.end(), tmp)) {
            result.push_back(tmp);
        }
    }

    sort(result.begin(), result.end());
    cout << result.size() << "\n";
    for (string r : result) {
        cout << r << "\n";
    }
    return 0;
}