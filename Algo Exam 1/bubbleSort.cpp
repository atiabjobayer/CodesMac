#include <bits/stdc++.h>
using namespace std;

void bubbleSort(int ara[], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (ara[i] > ara[j]) {
                swap(ara[i], ara[j]);
            }
        }
    }
}

int main() {
    int ara[10] = {4, 3, 1, 5, 7, 8, 9, 2, 10, 6};

    int n = sizeof(ara) / ara[0];

    cout << "Array size: " << n << endl;

    bubbleSort(ara, n);

    for (int i = 0; i < n; i++) {
        cout << ara[i] << " ";
    }
    cout << endl;

    return 0;
}