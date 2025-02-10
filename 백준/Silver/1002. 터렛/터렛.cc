#include <cmath>
#include <iostream>
using namespace std;

double getDist(pair<int, int> pos1, pair<int, int> pos2) {
    return sqrt(pow(pos1.first - pos2.first, 2) +
                pow(pos1.second - pos2.second, 2));
}

int getAns(pair<int, int> pos1, pair<int, int> pos2, int r1, int r2) {
    double dist = getDist(pos1, pos2);
    if (dist == 0) {
        if (r1 == r2) {
            return -1;
        }
        return 0;
    } else {
        if (dist == r1 + r2) {
            return 1;
        } else if (dist > r1 + r2) {
            return 0;
        } else {
            if (r1 < r2) {
                if (dist + r1 == r2) {
                    return 1;
                } else if (dist + r1 < r2) {
                    return 0;
                } else {
                    return 2;
                }
            } else {
                if (dist + r2 == r1) {
                    return 1;
                } else if (dist + r2 < r1) {
                    return 0;
                } else {
                    return 2;
                }
            }
        }
    }
}

int main(void) {
    int t;
    int x1, y1, x2, y2;
    int r1, r2;

    cin >> t;
    for (int i = 0; i < t; i++) {
        cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;
        cout << getAns({x1, y1}, {x2, y2}, r1, r2) << "\n";
    }
}