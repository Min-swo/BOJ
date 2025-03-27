#include <deque>
#include <iostream>
using namespace std;

int main(void) {
    int N;
    cin >> N;

    deque<int> d;
    for (int i = 1; i <= N; i++) {
        d.push_back(i);
    }

    while (d.size() != 1) {
        d.pop_front();

        if (d.size() == 1) {
            break;
        }

        int tmp = d.front();
        d.pop_front();
        d.push_back(tmp);
    }

    cout << d.front() << "\n";
    return 0;
}