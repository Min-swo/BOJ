#include <iostream>
#include <string>
#include <vector>
using namespace std;

int N;
vector<string> chs(101);

int main(void) {
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin.ignore();
        cin >> chs[i];
    }

    int idx1, idx2;
    for (int i = 0; i < N; i++) {
        if (chs[i] == "KBS1") {
            idx1 = i;
        } else if (chs[i] == "KBS2") {
            idx2 = i;
        }
    }

    if (idx1 < idx2) {
        for (int i = 0; i < idx1; i++) {
            cout << "1";
        }

        for (int i = 0; i < idx1; i++) {
            cout << "4";
        }

        for (int i = 0; i < idx2; i++) {
            cout << "1";
        }

        for (int i = 0; i < idx2 - 1; i++) {
            cout << "4";
        }
    } else {
        for (int i = 0; i < idx1 - 1; i++) {
            cout << "3";
        }
        cout << "1";
        for (int i = 0; i < idx1; i++) {
            cout << "4";
        }

        for (int i = 0; i < idx2; i++) {
            cout << "1";
        }

        for (int i = 0; i < idx2 - 1; i++) {
            cout << "4";
        }
    }
    cout << "\n";
    return 0;
}