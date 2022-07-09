#include <bits/stdc++.h>
#define MAX 100
#define pb(x) push_back(x)
#define pii pair< int, int >
#define read(x) freopen(x, "r", stdin)
#define write(x) freopen(x, "w", stdout)

using namespace std;
typedef long long int lli;

void heapify(int ara[], int n, int i) {
    int largest = i;
    int l       = 2 * i + 1;
    int r       = 2 * i + 2;

    if (l < n and ara[l] > ara[largest]) {
        largest = l;
    }
    if (r < n and ara[r] > ara[largest]) {
        largest = r;
    }

    if (largest != i) {
        swap(ara[i], ara[largest]);

        heapify(ara, n, largest);
    }
}

void heapSort(int ara[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(ara, n, i);
    }

    for (int i = n - 1; i > 0; i--) {
        swap(ara[0], ara[i]);

        heapify(ara, i, 0);
    }
}

int main() {

    int ara[10] = {4, 3, 1, 5, 7, 8, 9, 2, 10, 6};

    int n = sizeof(ara) / ara[0];

    cout << "Array size: " << n << endl;

    heapSort(ara, n);

    for (int i = 0; i < n; i++) {
        cout << ara[i] << " ";
    }
    cout << endl;

    return 0;
}