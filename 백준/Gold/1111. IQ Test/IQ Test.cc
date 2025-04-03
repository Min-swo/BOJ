#include <iostream>
using namespace std;

#define MAX 51
int arr[MAX];

int N;
int a, b;
int flag = 0;

int getGradient(int n1, int n2, int n3) {
    float dY = (n3 - n2);
    float dX = (n2 - n1);

    if (dY == 0) {
        return 0;
    } else if (dY != 0 && dX == 0) {
        flag = 1;
        return 0;
    }

    float gradient = dY / dX;
    if (gradient - int(gradient) != 0) {
        flag = 1;
    }

    return int(gradient);
}

int getBias(int n1, int n2, int gradient) { return n2 - n1 * gradient; }

bool isAllSame() {
    int s = arr[0];
    for (int i = 1; i < N; i++) {
        if (s != arr[i]) {
            return false;
        }
    }
    return true;
}

int main(void) {
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    if (N == 1) {
        cout << "A\n";
    } else if (N == 2) {
        if (isAllSame()) {
            cout << arr[0] << "\n";
        } else {
            cout << "A\n";
        }
    } else {
        int gradient = getGradient(arr[0], arr[1], arr[2]);
        for (int i = 1; i < N - 2; i++) {
            int tmp = getGradient(arr[i], arr[i + 1], arr[i + 2]);

            if (tmp != gradient) {
                flag = 1;
                break;
            }
        }

        a = gradient;
        b = getBias(arr[0], arr[1], gradient);

        if (flag) {
            cout << "B\n";
        } else {
            cout << a * arr[N - 1] + b << "\n";
        }
    }
    return 0;
}