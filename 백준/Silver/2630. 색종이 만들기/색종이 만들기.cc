#include <iostream>
#include <vector>
using namespace std;

#define MAX 128

typedef pair<int, int> pii;

int N;
int map[MAX][MAX];

int white = 0;
int blue = 0;

int check(pii row, pii col) {
    int flag = -1;
    for (int i = row.first; i < row.second; i++) {
        for (int j = col.first; j < col.second; j++) {
            if (map[i][j] == 1) {
                if (flag == 0) {
                    return -1;
                }
                flag = 1;
            } else {
                if (flag == 1) {
                    return -1;
                }
                flag = 0;
            }
        }
    }
    return flag;
}

void getCount(pii row, pii col) {
    int color = check(row, col);
    if (color == 1) {
        blue++;
        return;
    }
    if (color == 0) {
        white++;
        return;
    }

    int rowMid = (row.first + row.second) / 2;
    int colMid = (col.first + col.second) / 2;
    getCount({row.first, rowMid}, {col.first, colMid});
    getCount({row.first, rowMid}, {colMid, col.second});
    getCount({rowMid, row.second}, {col.first, colMid});
    getCount({rowMid, row.second}, {colMid, col.second});
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> map[i][j];
        }
    }

    getCount({0, N}, {0, N});

    cout << white << "\n";
    cout << blue << "\n";

    return 0;
}