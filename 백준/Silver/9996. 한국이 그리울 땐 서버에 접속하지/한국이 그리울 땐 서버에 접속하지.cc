#include <iostream>
#include <vector>
using namespace std;

int N;
vector<char> startStr;
string endStr;
int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    char tmp;
    while (1) {
        cin >> tmp;
        if (tmp == '*') {
            break;
        }
        if (tmp == '\n') {
            continue;
        }
        startStr.push_back(tmp);
    }

    cin >> endStr;

    int startSize = startStr.size();
    int endSize = endStr.size();
    string target;

    for (int i = 0; i < N; i++) {
        bool flag = true;
        cin >> target;
        int targetSize = target.size();

        if (targetSize < startSize + endSize) {
            flag = false;
        } else {
            for (int j = 0; j < startSize; j++) {
                if (startStr[j] != target[j]) {
                    flag = false;
                    break;
                }
            }
            for (int j = 0; j < endSize; j++) {
                if (endStr[endSize - 1 - j] != target[targetSize - 1 - j]) {
                    flag = false;
                    break;
                }
            }
        }

        if (flag) {
            cout << "DA\n";
        } else {
            cout << "NE\n";
        }
    }

    return 0;
}