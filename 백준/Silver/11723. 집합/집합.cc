#include <iostream>
using namespace std;

int M;
int set[21];

int check(int data) { return set[data]; }

void add(int data) {
    if (check(data)) {
        return;
    }

    set[data] = 1;
}

void remove(int data) {
    if (!check(data)) {
        return;
    }

    set[data] = 0;
}

void toggle(int data) { set[data] = !set[data]; }

void all() {
    for (int i = 1; i < 21; i++) {
        set[i] = 1;
    }
}

void empty() {
    for (int i = 1; i < 21; i++) {
        set[i] = 0;
    }
}

void commander(string cmd) {
    int data;
    if (cmd == "add") {
        cin >> data;
        add(data);
    } else if (cmd == "remove") {
        cin >> data;
        remove(data);
    } else if (cmd == "check") {
        cin >> data;
        cout << check(data) << "\n";
    } else if (cmd == "toggle") {
        cin >> data;
        toggle(data);
    } else if (cmd == "all") {
        all();
    } else if (cmd == "empty") {
        empty();
    } else {
        cout << "Unexpected Cmd\n";
    }
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    for (int i = 1; i < 21; i++) {
        set[i] = 0;
    }
    cin >> M;

    string cmd;
    for (int i = 0; i < M; i++) {
        cin >> cmd;
        commander(cmd);
    }
    return 0;
}