#include <bits/stdc++.h>

using namespace std;

vector<int> parent;
vector<int> siz;

vector<bool> visited;


int find_set(int v) {
    if (v == parent[v])
        return v;
    return parent[v] = find_set(parent[v]);
}

void make_set(int v) {
    parent[v] = v;
    siz[v] = 1;
}

void union_sets(int a, int b) {
    a = find_set(a);
    b = find_set(b);
    if (a != b) {
        if (siz[a] < siz[b])
            swap(a, b);
        parent[b] = a;
        siz[a] += siz[b];
    }
}

vector<int> final;
    vector<vector<int>> adjfa;
    vector<vector<int>> adjfr;

void dfs(int v, int p) {
    //cout << v << " " << p;
    //cout << v << " " << parent[v] << " " << p << "  ";
    if (parent[v] != p) return;

    if (visited[v]) return;
    visited[v] = true;

    final[p]++;

    vector<int> adjj = adjfa[v];

    for (int i = 0; i < adjj.size(); i++) {
        dfs(adjj[i], p);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m; cin >> n >> m;

    parent = vector<int>(n);
    iota(begin(parent), end(parent), 0);
    siz = vector<int>(n, 1);


    final = vector<int>(n);
    adjfa = vector<vector<int>>(n);
    adjfr = vector<vector<int>>(n);
    visited = vector<bool>(n);

    for (int i = 0; i < m; i++) {
        int a, b, c; cin >> a >> b >> c;

        if (c == 1) {
            adjfa[a-1].push_back(b-1);
            adjfa[b-1].push_back(a-1);
        } 
        else {
            adjfr[a-1].push_back(b-1);
            adjfr[b-1].push_back(a-1);
        }   
    }

    for (int i = 0; i < n; i++) {
        for (auto& j : adjfr[i]) {
            union_sets(i, j);
        }
    }

    
    for (int i = 0; i < n; i++) {
        dfs(i, parent[i]);
    }

    for (int i = 0; i < n; i++) {
        cout << final[parent[i]]-1 << " ";
    }
}