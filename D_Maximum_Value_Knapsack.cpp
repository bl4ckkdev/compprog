#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k; cin >> n >> k;

    vector<int> c(n+1), v(n+1);

    for (int i = 1; i <= n; i++) {
        cin >> c[i];
    }

    for (int i = 1; i <= n; i++) {
        cin >> v[i];
    }

    vector<vector<int>> dp(n+1, vector<int>(k+1));

    for (int i = 1; i <= n; i++) {
        dp[i] = dp[i-1];

        for (int w = c[i]; w <= k; w++) {
            if ()
        }
    }
}