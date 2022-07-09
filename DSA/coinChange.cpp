#include <bits/stdc++.h>
#define MAX 100
#define pb(x) push_back(x)
#define pii pair< int, int >
#define read(x) freopen(x, "r", stdin)
#define write(x) freopen(x, "w", stdout)

using namespace std;
typedef long long int lli;

int dp[MAX][MAX];

int coinChange(int coins[], int n, int money) {

    if (money == 0)
        return 1; // no money, one way

    if (money < 0)
        return 0; // negative money, no solution

    if (n <= 0 and money >= 1)
        return 0; // no coin, zero way

    if (dp[n][money] != -1)
        return dp[n][money];

    return dp[n][money] =
               coinChange(coins, n - 1, money) // not taking the coin
               + coinChange(coins, n, money - coins[n - 1]); // taking the coin
}

int main() {
    // read("in.txt"); write("out.txt");

    int i, j;
    int arr[] = {1, 2, 3};
    int m     = sizeof(arr) / sizeof(arr[0]);

    memset(dp, -1, sizeof dp);

    cout << " " << coinChange(arr, m, 4) << endl;

    return 0;
}