#include <iostream>
using namespace std;

#define MAX 1000001

int top = -1;
int stack[MAX];

void push(int data) { stack[++top] = data; }

int pop() {
    if (top == -1) {
        return -1;
    }

    return stack[top--];
}

int size() { return top + 1; }

int empty() { return top == -1 ? 1 : 0; }

int peek() {
    if (top == -1) {
        return -1;
    }

    return stack[top];
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;

    int cmd, data;
    for (int i = 0; i < N; i++) {
        cin >> cmd;

        switch (cmd) {
        case 1:
            cin >> data;
            push(data);
            break;
        case 2:
            cout << pop() << "\n";
            break;
        case 3:
            cout << size() << "\n";
            break;
        case 4:
            cout << empty() << "\n";
            break;
        case 5:
            cout << peek() << "\n";
            break;
        default:
            cout << "Error\n";
            break;
        }
    }
}