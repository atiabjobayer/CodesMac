#include <bits/stdc++.h>
#define MAX 100
#define pb(x) push_back(x)
#define pii pair< int, int >
#define read(x) freopen(x, "r", stdin)
#define write(x) freopen(x, "w", stdout)

using namespace std;
typedef long long int lli;

void selectionSort(int ara[], int n) {
    int i, j, minIndex;

    for (i = 0; i < n - 1; i++) {
        minIndex = i;

        for (j = i + 1; j < n; j++) {
            if (ara[j] < ara[minIndex]) {
                minIndex = j;
            }
        }

        swap(ara[minIndex], ara[i]);
    }
}

int main() {
    // read("in.txt"); write("out.txt");

    int ara[10] = {4, 3, 1, 5, 7, 8, 9, 2, 10, 6};

    int n = sizeof(ara) / ara[0];

    cout << "Array size: " << n << endl;

    selectionSort(ara, n);

    for (int i = 0; i < n; i++) {
        cout << ara[i] << " ";
    }
    cout << endl;

    return 0;
}