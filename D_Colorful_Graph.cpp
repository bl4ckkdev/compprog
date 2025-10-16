#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m; cin >> n >> m;

    vector<int> colors(n);
    
    for (int i = 0; i < n; ++i) cin >> colors[i];

    vector<vector<int>> adj(1e5+1);

    for (int i = 0; i < m; ++i) {
        int a, b; cin >> a >> b;

        //cout << colors[a-1] << " " << colors[b-1] << "  ";
        if (colors[a-1] == colors[b-1]) continue;
        //adj[colors[a-1]].push_back(colors[a-1]);
        //adj[colors[b-1]].insert(colors[b-1]);

        adj[colors[b-1]].push_back(colors[a-1]);
        adj[colors[a-1]].push_back(colors[b-1]);
    }
    cout << endl;

    int mx = 0;
    int aaa = 0;
    for (int i = 0; i <= 1e5; i++) {
        if (adj[i].size()>0) {
            //cout << i << " ";
            //for (auto& j : adj[i]) cout << j << " ";
            //cout << endl;
        }
        if ((int)adj[i].size()>mx || ((int)adj[i].size()==mx&&i<aaa)) {
            aaa = i;
        }  
        mx = max(mx, (int)adj[i].size());

        //for (auto& j : adj[i]) cout << j << " ";
        //cout << "  ";
        //cout << aaa << " " << i << " " << mx << "  " << endl;
    }

    cout << aaa;
}