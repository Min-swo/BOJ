#include <iostream>
using namespace std;

int N;
int main(void) {
    cin >> N;

    int k = N % 4;
    if (k == 0 || k == 2) {
        cout << "CY\n";
    } else if (k == 1 || k == 3) {
        cout << "SK\n";
    }

    return 0;
}