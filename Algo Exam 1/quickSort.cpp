#include <bits/stdc++.h>
#define MAX 100
#define pb(x) push_back(x)
#define pii pair< int, int >
#define read(x) freopen(x, "r", stdin)
#define write(x) freopen(x, "w", stdout)

using namespace std;
typedef long long int lli;

void swap(int *a, int *b) {
    int t = *a;
    *a    = *b;
    *b    = t;
}

int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i     = (low - 1);

    for (int j = low; j <= high - 1; j++) {

        if (arr[j] < pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);

        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int main() {

    int ara[10] = {4, 3, 1, 5, 7, 8, 9, 2, 10, 6};

    int n = sizeof(ara) / ara[0];

    cout << "Array size: " << n << endl;

    quickSort(ara, 0, n - 1);

    for (int i = 0; i < n; i++) {
        cout << ara[i] << " ";
    }
    cout << endl;

    return 0;
}