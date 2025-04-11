#include <iostream>
using namespace std;

int main(void) {
    int num;
    int flag = 0;
    char op;

    cin >> num;
    int plusSum = num;
    int minusSum = 0;
    while (1) {
        op = cin.get();
        if (op == '\n') {
            break;
        }

        if (flag) {
            cin >> num;
            minusSum += num;
        } else {
            if (op == '-') {
                flag = 1;
                cin >> num;
                minusSum += num;
            } else {
                cin >> num;
                plusSum += num;
            }
        }
    }

    cout << plusSum - minusSum << "\n";

    return 0;
}