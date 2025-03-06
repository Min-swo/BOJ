#include <cmath>
#include <iostream>
using namespace std;

int curIdx = 0;

void swap(int *heap, int idx1, int idx2) {
    int tmp = heap[idx1];
    heap[idx1] = heap[idx2];
    heap[idx2] = tmp;
}

void push(int *heap, int k) {
    heap[++curIdx] = k;

    int childIdx = curIdx;
    while (1) {
        int parentIdx = childIdx / 2;

        if (parentIdx == 0) {
            break;
        }
        if (abs(heap[parentIdx]) < abs(heap[childIdx])) {
            break;
        }
        if (abs(heap[parentIdx]) == abs(heap[childIdx])) {
            if (heap[parentIdx] <= heap[childIdx]) {
                break;
            }
        }

        swap(heap, parentIdx, childIdx);
        childIdx = parentIdx;
    }
}

int getMinChildIdx(int *heap, int idx1, int idx2) {
    if (idx1 == curIdx) {
        return idx1;
    }

    if (abs(heap[idx1]) < abs(heap[idx2])) {
        return idx1;
    } else if (abs(heap[idx1]) == abs(heap[idx2])) {
        return heap[idx1] < abs(heap[idx2]) ? idx1 : idx2;
    } else {
        return idx2;
    }
}

int pop(int *heap) {
    if (curIdx == 0) {
        return 0;
    }

    int min = heap[1];
    heap[1] = heap[curIdx];
    heap[curIdx--] = 0;

    int parentIdx = 1;
    while (1) {
        int leftChildIdx = parentIdx * 2;
        int rightChildIdx = parentIdx * 2 + 1;

        if (leftChildIdx > curIdx) {
            break;
        }

        int minChildIdx = getMinChildIdx(heap, leftChildIdx, rightChildIdx);

        if (abs(heap[parentIdx]) < abs(heap[minChildIdx])) {
            break;
        }
        if (abs(heap[parentIdx]) == abs(heap[minChildIdx])) {
            if (heap[parentIdx] <= heap[minChildIdx]) {
                break;
            }
        }

        swap(heap, parentIdx, minChildIdx);
        parentIdx = minChildIdx;
    }

    return min;
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;

    int *absMinHeap = new int[n];
    for (int i = 0; i < n; i++) {
        int tmp;
        cin >> tmp;

        if (tmp == 0) {
            cout << pop(absMinHeap) << "\n";
        } else {
            push(absMinHeap, tmp);
        }
    }
    return 0;
}