#include <bits/stdc++.h>
#define MAX 100
#define pb(x) push_back(x)
#define pii pair< int, int >
#define read(x) freopen(x, "r", stdin)
#define write(x) freopen(x, "w", stdout)

using namespace std;
typedef long long int lli;

vector< int > adj[MAX];

bool visited[MAX], recursing[MAX];

bool detectCycle(int u) {
    if (!visited[u]) {
        visited[u]   = true;
        recursing[u] = true;

        for (int i = 0; i < adj[u].size(); i++) {
            int v = adj[u].at(i);

            if ((!visited[v]) and detectCycle(v)) {
                return true;
            }
            else if (recursing[v])
                return true;
        }
    }

    recursing[u] = false;

    return false;
}

int main() {
    read("in.txt"); // write("out.txt");

    int node, edge;
    cin >> node >> edge;

    for (int i = 0; i < edge; i++) {
        int s, d;
        cin >> s >> d;

        adj[s].push_back(d);
    }

    // process

    memset(visited, false, sizeof visited);
    memset(recursing, false, sizeof recursing);

    bool flag = false;

    for (int i = 0; i < node; i++) {
        if ((!visited[i]) and detectCycle(i)) {
            flag = true;
            break;
        }
    }

    if (flag) {
        cout << "Cycle" << endl;
    }
    else {
        cout << "No cycle" << endl;
    }

    return 0;
}