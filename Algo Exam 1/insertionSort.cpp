#include <bits/stdc++.h>
#define MAX 100
#define pb(x) push_back(x)
#define pii pair< int, int >
#define read(x) freopen(x, "r", stdin)
#define write(x) freopen(x, "w", stdout)

using namespace std;
typedef long long int lli;

void insertionSort(int ara[], int n) {
    int i, j, key;

    for (i = 1; i < n; i++) {
        key = ara[i];

        j = i - 1;

        while (j >= 0 and ara[j] > key) {
            ara[j + 1] = ara[j];
            j          = j - 1;
        }

        ara[j + 1] = key;
    }
}

int main() {
    // read("in.txt"); write("out.txt");

    int ara[10] = {4, 3, 1, 5, 7, 8, 9, 2, 10, 6};

    int n = sizeof(ara) / ara[0];

    cout << "Array size: " << n << endl;

    insertionSort(ara, n);

    for (int i = 0; i < n; i++) {
        cout << ara[i] << " ";
    }
    cout << endl;

    return 0;
}