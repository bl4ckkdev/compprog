#include <bits/stdc++.h>

using namespace std;

set<int> dfs(int cur, vector<vector<int>>& adj, vector<bool>& visited, set<int>& haa) {
    visited[cur] = 1;
    haa.insert(cur);

    vector<int>& neighb = adj[cur];

    for (int i = 0; i < neighb.size(); i++) {
        if (!visited[neighb[i]]) {
            dfs(neighb[i], adj, visited, haa);
        }
    }


    return haa;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, s; cin >> n >> s;

    vector<vector<int>> adj(n);

    for (int i = 0; i < n; i++) {
        int u, v; cin >> u >> v;
        adj[u-1].push_back(v-1);
        adj[v-1].push_back(u-1);
    }

    vector<pair<pair<int, int>, int>> tr(s);
    for (int i = 0; i < s; i++) {
        cin >> tr[i].first.first >> tr[i].first.second >> tr[i].second;
    }

    for (int i = 0; i < n; i++) {
        vector<bool> visited(n);

        visited[i] = true;

        vector<int>& neighb = adj[i];

        int mxc = 0;
        for (int j = 0; j < neighb.size(); j++) {
            set<int> bb;
            set<int> d = dfs(j, adj, visited, bb);
            vector<bool> visited2(n);
            visited2[j] = 1;
            

            int cc = 0;

            for (int k = 0; k < neighb.size(); k++) {
                set<int> nn;
                set<int> d2 = dfs(k, adj, visited2, nn);

                for (auto& l : tr) {
                    if (d.count(l.first.first) && d2.count(l.first.second)) {
                        cc += l.second;
                    } else if (d2.count(l.first.first) && d.count(l.first.second)) {
                        cc += l.second;
                    } else if (d.count(l.first.first) && d.count(l.first.second)) {
                        cc += l.second;
                    } else if (d2.count(l.first.first) && d2.count(l.first.second)) {
                        cc += l.second;
                    }
                }

                mxc = max(mxc, cc);
            }
        }

        cout << mxc << " ";
    }
}