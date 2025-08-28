#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;

    while (t--) {
        vector<int> occurances(3*1e3+1);

        int n; cin >> n;
        vector<pair<int, int>> adj(n);
        vector<vector<int>> neighb(2*n);

        
        
        for (int i = 0; i < n; i++) {
            cin >> adj[i].first >> adj[i].second;

            for (int j = adj[i].first-1; j < adj[i].second-1; j++) {
                occurances[j]++;
            }
        }

        for (int i = 0; i < n; i++) {
            neighb[adj[i].first-1].push_back(adj[i].second-1);
            neighb[adj[i].second-1].push_back(adj[i].first-1);
        }

        vector<bool> visited(3*1e3+1);
        vector<int> tradeoff(n);

        int cycles = 0;
        
        for (int i = 0; i < 2*n; i++) {
            if (visited[i]) continue;

            if (neighb[i].size()>=2) {
                deque<pair<int, int>> tovisit;
                tovisit.push_front(make_pair(i, -1));

                while (!tovisit.empty()) {
                    pair<int, int> node = tovisit.front();
                    tovisit.pop_front();

                    if (visited[node.first]) {
                        cycles++;
                    } 

                    else for (int j = 0; j < neighb[node.first].size(); j++) {
                        if (neighb[node.first][j] != node.second) 
                            tovisit.push_front(make_pair(neighb[node.first][j], node.first));
                    }

                    visited[node.first] = true;
                }
            }
        }

        for (int i = 0; i < n; i++) {
            int L = 0;
            int C = 0;

            for (int j = adj[i].first-1; j < adj[i].second-1; j++) {
                if (occurances[j] == 1) L++;
            }
        }

        cycles /= 2;

        cout << cycles << endl;
    }
}