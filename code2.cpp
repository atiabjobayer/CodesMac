#include <bits/stdc++.h>
#define MAX 100
#define pb(x) push_back(x)
#define pii pair< int, int >
#define read(x) freopen(x, "r", stdin)
#define write(x) freopen(x, "w", stdout)

using namespace std;
typedef long long int lli;

vector< int > adj[MAX];

bool visited[MAX];

void bfs(int src) {
    memset(visited, false, sizeof visited);

    queue< int > q;

    q.push(src);

    visited[src] = 1;

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        for (int i = 0; i < adj[u].size(); i++) {
            int v = adj[u].at(i);

            if (!visited[v]) {
                visited[v] = 1;
                q.push(v);
            }
        }
    }
}

int main() {
    // read("in.txt"); write("out.txt");

    int node, edge;
    cin >> node >> edge;

    for (int i = 0; i < edge; i++) {
        int s, d;
        cin >> s >> d;

        adj[s].pb(d);
    }

    while (1) {
        int a, b;
        cin >> a >> b;

        bfs(a);

        if (visited[b]) {
            cout << "There is a path" << endl;
        }
        else {
            cout << "No path" << endl;
        }
    }

    return 0;
}