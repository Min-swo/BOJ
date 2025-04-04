#include <iostream>
using namespace std;

int M;
int set = 0;

void add(int data) {
    int flag = 1 << (data - 1);
    set = set | flag;
}

void remove(int data) {
    int flag = ~(1 << (data - 1));
    set = set & flag;
}

void check(int data) {
    int flag = 1 << (data - 1);
    if ((set & flag) == flag) {
        cout << "1\n";
    } else {
        cout << "0\n";
    }
}

void toggle(int data) {
    int flag = 1 << (data - 1);
    set = set ^ flag;
}

void all() {
    int flag = ~0;
    set = set | flag;
}

void empty() { set = 0; }

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> M;

    string cmd;
    int data;
    for (int i = 0; i < M; i++) {
        cin >> cmd;

        if (cmd == "add") {
            cin >> data;
            add(data);
        } else if (cmd == "remove") {
            cin >> data;
            remove(data);
        } else if (cmd == "check") {
            cin >> data;
            check(data);
        } else if (cmd == "toggle") {
            cin >> data;
            toggle(data);
        } else if (cmd == "all") {
            all();
        } else if (cmd == "empty") {
            empty();
        } else {
            cout << "Error\n";
        }
    }

    return 0;
}