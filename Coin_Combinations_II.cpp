#include <bits/stdc++.h>

using namespace std;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, x; cin >> n >> x;

    vector<int> coins(n);
    vector<vector<int>> ways(n, vector<int>(x+1, 0)); // ways, latest number

    for (int i = 0; i < n; i++) {
        cin >> coins[i];
    }

    sort(begin(coins), end(coins));

    for (int i = 0; i < n; i++) {
        if (coins[i]>x) break;

        ways[i][coins[i]] = 1;
    }

    for (int i = 0; i <= x; i++) {
        for (int j = 0; j < n; j++) {
            if (i+coins[j] > x) continue;
            ways[j][i+coins[j]] += ways[j][i] % ((int)1e9+7);

            ways[j][i+coins[j]] %= (int)1e9+7;
        }
    }

    
    /*for (auto& i : ways) {
        int ctr = 0;
        for (auto& j : i) {
            //if (ctr > 100 && ctr < 1000000-20) continue;
            if (j < 0)
            cout << j << " ";
            ctr++;
        } 
        cout << endl;
    }*/

    int mn = 0;
    for (int i = 0; i < n; i++) {
        mn += ways[i][x];
        mn %= (int)1e9+7;
    }

    cout << mn;
}