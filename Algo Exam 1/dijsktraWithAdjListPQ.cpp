#include "bits/stdc++.h"

using namespace std;

map< int, vector< pair< int, int > > > mp;

void addEdge(int u, int v, int dist) { mp[u].push_back(make_pair(v, dist)); }

void startDijkstra(int u) {
    vector< int > dist(1e2 + 1, 1e9);

    set< pair< int, int > > st;
    st.insert(make_pair(0, u));
    dist[u] = 0;

    while (!st.empty()) {
        pair< int, int > now = *st.begin();
        st.erase(st.begin());

        int v = now.second;
        int w = now.first;

        const vector< pair< int, int > > &edges = mp[v];
        for (const pair< int, int > &to : edges) {
            if (w + to.second < dist[to.first]) {
                st.erase(make_pair(dist[to.first], to.first));
                dist[to.first] = w + to.second;
                st.insert(make_pair(dist[to.first], to.first));
            }
        }
    }

    for (int i = 1; i <= 8; i++) {
        cout << i << ' ' << dist[i] << endl;
    }
}

int main() {
    addEdge(1, 2, 2);
    addEdge(1, 3, 4);

    addEdge(2, 4, 7);
    addEdge(2, 3, 1);

    addEdge(3, 5, 3);

    addEdge(4, 6, 1);
    addEdge(5, 6, 5);

    addEdge(5, 4, 2);

    startDijkstra(1);

    return 0;
}