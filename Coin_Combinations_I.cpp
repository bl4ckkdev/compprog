#include <bits/stdc++.h>
 
using namespace std;
 
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
 
    int n, x; cin >> n >> x;
 
    vector<int> coins(n);
    vector<int> ways(x+1);
 
    for (int i = 0; i < n; i++) {
        cin >> coins[i];
    }
 
    ways[0] = 1;
 
    for (int i = 0; i <= x; i++) {
        for (int j = 0; j < n; j++) {
            if (i+coins[j] > x) continue;
            ways[i+coins[j]] += (ways[i] % (1000000000+7));
 
            ways[i+coins[j]] %= (1000000000+7);
        }
    }
 
    cout << ways[x];
}
