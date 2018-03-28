#include <iostream>
#include <stack>

using namespace std;

void qSort(int A[], int n);

int main() {
    int A[10] = {9, 2, 1, 3, 4, 1, 3, 5, 23, 5};

    qSort(A, 10);

    for (int i = 0; i < 10; ++i) {
        cout << A[i] << " ";
    }
    return 0;
}

struct lp {
    int left;
    int right;
};

int partition(int A[], int left, int right) {
    int border = left - 1;
    int i = left;
    int pivot = A[right];

    while (i < right) {
        if (A[i] < pivot) {
            border++;
            swap(A[i], A[border]);
        }
        i++;
    }

    swap(A[i], A[border + 1]);
    return border + 1;
}

void qSort(int A[], int n) {
    int left = 0;
    int right = n - 1;
    stack<lp> stos;

    while (left < right || !stos.empty()) {
        if (left < right) {
            int q = partition(A, left, right);
            lp nowy = {q + 1, right};
            stos.push(nowy);
            right = q - 1;
        } else {
            left = stos.top().left;
            right = stos.top().right;
            stos.pop();
        }
    }
}