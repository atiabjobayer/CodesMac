#include <bits/stdc++.h>
#define MAX 100
#define pb(x) push_back(x)
#define pii pair< int, int >
#define read(x) freopen(x, "r", stdin)
#define write(x) freopen(x, "w", stdout)

using namespace std;
typedef long long int lli;

void printUnion(int ara1[], int ara2[], int m, int n) {
    int i = 0, j = 0;

    while (i < m and j < n) {
        if (ara1[i] < ara2[j]) {
            cout << ara1[i++] << " ";
        }
        else if (ara2[j] < ara1[i]) {
            cout << ara2[j++] << " ";
        }
        else {
            cout << ara2[j++] << " ";
            i++;
        }
    }

    while (i < m) {
        cout << ara1[i++] << " ";
    }

    while (j < n) {
        cout << ara2[j++] << " ";
    }

    cout << endl;
}

int main() {
    // read("in.txt"); write("out.txt");

    int arr1[] = {1, 2, 4, 5, 6};
    int arr2[] = {2, 3, 5, 7};

    int m = sizeof(arr1) / sizeof(arr1[0]);
    int n = sizeof(arr2) / sizeof(arr2[0]);

    // Function calling
    printUnion(arr1, arr2, m, n);

    return 0;
}