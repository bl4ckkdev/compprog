#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    //freopen("cownomics.in", "r", stdin);
    //freopen("cownomics.out", "w", stdout);

    int n, m; cin >> n >> m;

    vector<string> spotty(n);
    for (int i = 0; i < n; i++) {
        cin >> spotty[i];
    }

    vector<string> plain(n);
    for (int i = 0; i < n; i++) {
        cin >> plain[i];
    }

    int nm = m;
    for (int i = 0; i < m; i++) {
        bool same = true;
        for (int k = 0; k < m; k++) {
            for (int j = 0; j < n; j++) {
                if (plain[j][i] == spotty[j][k]) {
                    same = false;
                }
            }
        }

        if (!same) --nm;
    }
    
    cout << nm;
}