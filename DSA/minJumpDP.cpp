#include <bits/stdc++.h>
#define MAX 100
#define pb(x) push_back(x)
#define pii pair< int, int >
#define read(x) freopen(x, "r", stdin)
#define write(x) freopen(x, "w", stdout)

using namespace std;
typedef long long int lli;

int dp[MAX]; // dp[i] denotes 0 theke i porjonto zaite koyta jump lagbe

int minJump(int ara[], int n) {
    if (n == 0 or ara[0] == 0)
        return INT_MAX;

    dp[0] = 0;

    for (int i = 1; i < n; i++) {
        dp[i] = INT_MAX;

        for (int j = 0; j < i; j++) {
            if (i <= j + ara[j] and ara[j] != INT_MAX) {
                dp[i] = min(ara[i], dp[j] + 1);

                break;
            }
        }
    }

    return dp[n - 1];
}

int main() {
    // read("in.txt"); write("out.txt");

    int arr[] = {1, 3, 5, 8, 9, 2};
    int size  = sizeof(arr) / sizeof(int);
    cout << "Minimum number of jumps to reach end is " << minJump(arr, size)
         << endl;

    return 0;
}