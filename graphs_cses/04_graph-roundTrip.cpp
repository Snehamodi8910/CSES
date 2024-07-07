#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define endl '\n'

bool bfs_find_cycle(int start, vector<int>& parent, vector<vector<int>>& graph, vector<int>& cycle) {
    int n = graph.size();
    vector<int> vis(n, 0);
    queue<int> q;
    q.push(start);
    vis[start] = 1;

    while (!q.empty()) {
        int node = q.front();
        q.pop();

        for (int neighbor : graph[node]) {
            if (!vis[neighbor]) {
                vis[neighbor] = 1;
                parent[neighbor] = node;
                q.push(neighbor);
            } else if (neighbor != parent[node]) {
                // Cycle detected
                cycle.push_back(neighbor);
                int cur = node;
                while (cur != neighbor) {
                    cycle.push_back(cur);
                    cur = parent[cur];
                }
                cycle.push_back(neighbor);
                reverse(cycle.begin(), cycle.end());
                return true;
            }
        }
    }
    return false;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, m;
    cin >> n >> m;
    vector<vector<int>> graph(n + 1);
    vector<int> parent(n + 1, -1);

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    vector<int> cycle;
    for (int i = 1; i <= n; i++) {
        if (parent[i] == -1) {
            if (bfs_find_cycle(i, parent, graph, cycle)) {
                cout << cycle.size() << endl;
                for (int city : cycle) {
                    cout << city << " ";
                }
                cout << endl;
                return 0;
            }
        }
    }

    cout << "IMPOSSIBLE" << endl;
    return 0;
}
