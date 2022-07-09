#include <bits/stdc++.h>
#define MAX 100
#define pb(x) push_back(x)
#define pii pair< int, int >
#define read(x) freopen(x, "r", stdin)
#define write(x) freopen(x, "w", stdout)
#define R 6
#define C 5

using namespace std;
typedef long long int lli;

void printMaxSubSquare(int M[R][C]) {
    int S[R][C];

    for (int i = 0; i < C; i++) {
        S[0][i] = M[0][i];
    }

    for (int i = 0; i < R; i++) {
        S[i][0] = M[i][0];
    }

    int mx = -1;

    for (int i = 1; i < R; i++) {
        for (int j = 1; j < C; j++) {
            if (M[i][j] == 1) {
                S[i][j] =
                    min(S[i][j - 1], min(S[i - 1][j], S[i - 1][j - 1])) + 1;
            }
            else {
                S[i][j] = 0;
            }

            mx = max(mx, S[i][j]);
        }
    }

    cout << mx << endl;
}

int main() {
    // read("in.txt"); write("out.txt");

    int M[R][C] = {{0, 1, 1, 0, 1}, {1, 1, 0, 1, 0}, {0, 1, 1, 1, 0},
                   {1, 1, 1, 1, 0}, {1, 1, 1, 1, 1}, {0, 0, 0, 0, 0}};

    printMaxSubSquare(M);

    return 0;
}