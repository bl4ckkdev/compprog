#include <bits/stdc++.h>

using namespace std;
vector<vector<int>> cans((1e7)/3);
bool found = false;

void dfs(int idx, int target) {
    vector<int> adj = cans[idx];
    //for (auto& i : adj) cout << "a" << i << " ";
    //cout << "s" << adj.size() << " ";
    for (int i = 0; i < adj.size(); i++) {
        //cout << adj[i] << " ";
        if (adj[i] == target) {
            //cout << "HELLO?" << endl;
            found = true;
            //return;
        }
        if (adj[i]%3 == 0) dfs(adj[i]/3, target);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;


    for (int i = 3; i <= 1e7; i+=3) {
        cans[i/3].push_back(i/3);
        cans[i/3].push_back(2*i/3);
    }

    while (t--) {
        int a, b; cin >> a >> b;

        if (a % 3 == 0) dfs(a/3, b);
        if (a == b) found = true;

        cout << (!found ? "NO\n" : "YES\n");

        found = false;
    }
}