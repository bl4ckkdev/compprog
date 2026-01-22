#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; cin >> n;

    vector<int> dp(50);

    dp[0] = 0;
    dp[1] = 1;

    for (int i = 2; i < 50; i++) {
        dp[i] = dp[i-1] + dp[i-2];
    }

    cout << dp[n];
}