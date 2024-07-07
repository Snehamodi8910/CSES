#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define endl '\n'

bool check(int start, vector<int>& team, vector<vector<int>>& graph) {
    queue<int> q;
    q.push(start);
    team[start] = 0;  // Start with team 0
    while (!q.empty()) {
        int node = q.front();
        q.pop();
        for (auto it : graph[node]) {
            if (team[it] == -1) {
                team[it] = !team[node];
                q.push(it);
            } else if (team[it] == team[node]) {
                return false;
            }
        }
    }
    return true;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n, m;
    cin >> n >> m;
    vector<vector<int>> graph(n + 1);
    vector<int> team(n + 1, -1);

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    for (int i = 1; i <= n; i++) {
        if (team[i] == -1) {
            if (!check(i, team, graph)) {
                cout << "IMPOSSIBLE" << endl;
                return 0;
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        cout << team[i] + 1 << " ";  // Output 1 and 2 instead of 0 and 1
    }
    cout << endl;

    return 0;
}
