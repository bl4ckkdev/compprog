#include <bits/stdc++.h>

using namespace std;

void calculate_diamonds(int n, int m, int k, vector<int> u, vector<int> v, vector<int> d) {
    vector<pair<int, int>> adj(n);

    int mxd = 0;
    for (int i = 0; i < m; i++) {
        adj[u[i]] = {v[i], d[i]};

        mxd = max(mxd, d[i]);
    }


    vector<pair<int, int>> indexes;
    for (int i = 0; i < m; i++) {
        if (d[i] == mxd) {
            indexes.push_back({u[i], u[i]});
        }
    }

    for (int i = 0; i < m; i++) {
        int mx = 0;

        for (int j = 0; j < indexes.size(); j++) {
            mx = max(mx, adj[indexes[j].first].second);
        }

        for (int j = 0; j < indexes.size(); j++) {
            if (adj[indexes[j].first].second != mx) {
                indexes.erase(begin(indexes) + j);
                j--;
            }
        }

        for (int j = 0; j < indexes.size(); j++) {
            indexes[j].first = adj[indexes[j].first].first;
        }
    }


    long long uv = indexes[0].second;
    long long s = 0;


    for (long long i = 0; i < min(n, k); i++) {
        //cout << uv << " " << adj[uv].second << "  ";
        s += adj[uv].second;

        uv = adj[uv].first;
    }

    long long acs = 0;

    acs += s*(k/n);

    
    uv = indexes[0].second;

    for (long long i = 0; i < k%n; i++) {
        acs += adj[uv].second;

        uv = adj[uv].first;
    }

    cout << acs << endl;;

    /*for (auto& i : adj) {
        cout << "neighbours: ";
        cout << i.first << " " << i.second;

        cout << endl;
    }*/
}

int main() {
    int n, m, k; cin >> n >> m >> k;

    vector<int> u(m), v(m), d(m);

    for (int i = 0; i < m; i++) {
        cin >> u[i] >> v[i] >> d[i];
    }

    calculate_diamonds(n, m, k, u, v ,d);
}