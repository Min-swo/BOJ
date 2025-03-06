#include <iostream>
using namespace std;

int curIdx = 0;

void swap(int *arr, int idx1, int idx2) {
    int tmp = arr[idx1];
    arr[idx1] = arr[idx2];
    arr[idx2] = tmp;
}

void push(int *heap, int k) {
    heap[++curIdx] = k;

    int childIdx = curIdx;
    while (1) {
        int pIdx = childIdx / 2;

        if (pIdx == 0) {
            break;
        }
        if (heap[pIdx] <= heap[childIdx]) {
            break;
        }

        swap(heap, pIdx, childIdx);
        childIdx = pIdx;
    }
}

int pop(int *heap) {
    if (curIdx == 0) {
        return 0;
    }

    int minValue = heap[1];
    heap[1] = heap[curIdx];
    heap[curIdx--] = 0;

    int pIdx = 1;
    while (1) {
        int lIdx = pIdx * 2;
        int rIdx = pIdx * 2 + 1;

        if (lIdx > curIdx) {
            break;
        }

        int minIdx = (lIdx == curIdx || heap[lIdx] < heap[rIdx]) ? lIdx : rIdx;

        if (heap[pIdx] <= heap[minIdx]) {
            break;
        }

        swap(heap, minIdx, pIdx);
        pIdx = minIdx;
    }

    return minValue;
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;

    int *minHeap = new int[n];

    for (int i = 0; i < n; i++) {
        int tmp;
        cin >> tmp;

        if (tmp == 0) {
            cout << pop(minHeap) << "\n";
        } else {
            push(minHeap, tmp);
        }
    }

    return 0;
}