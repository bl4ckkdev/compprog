#include <bits/stdc++.h>

using namespace std;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; cin >> n;

    vector<int> ways(n+1);
    ways[0] = 1;

    for (int i = 0; i < n; i++) {
        for (int j = 1; j <= 6; j++) {
            if (i+j > n) break;
            ways[i+j] += (ways[i] % (1000000000+7));

            ways[i+j] %= (1000000000+7);
        }
    }

    cout << ways[n];
}