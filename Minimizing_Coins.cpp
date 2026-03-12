#include <bits/stdc++.h>

using namespace std;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long n, x; cin >> n >> x;

    vector<long long> nums(n), dp(x+1, 1e9+1);
    
    dp[0] = 0;


    for (long long i = 0; i < n; i++) cin >> nums[i];

    for (long long i = 0; i <= x; i++) {
        for (long long j = 0; j < n; j++) {
            if (i + nums[j] > x) continue;

            dp[i+nums[j]] = min(dp[i+nums[j]], dp[i]+1);
        }
    }

    //for (auto& i : dp) cout << i << " ";

    cout << (dp[x] == 1e9+1 ? -1 : dp[x]);
}