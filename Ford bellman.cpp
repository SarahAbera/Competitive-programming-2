#include <iostream>
#include <vector>
#include <limits>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> graph;
    vector<int> dis(n, numeric_limits<int>::max());

    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        graph.push_back({u, v, w});
    }

    dis[0] = 0;

    for (int i = 0; i < n - 1; i++) {
        for (const auto& edge : graph) {
            int u = edge[0];
            int v = edge[1];
            int w = edge[2];

            if (dis[u - 1] != numeric_limits<int>::max() && dis[u - 1] + w < dis[v - 1]) {
                dis[v - 1] = dis[u - 1] + w;
            }
        }
    }

    for (int i = 0; i < n; i++) {
        if (dis[i] == numeric_limits<int>::max()) {
            dis[i] = 30000;
        }
    }

    for (int i = 0; i < n; i++) {
        cout << dis[i] << " ";
    }

    return 0;
}
