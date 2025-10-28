#include <bits/stdc++.h>

using namespace std;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long t; cin >> t;

    while (t--) {
        long long n; cin >> n;

        vector<long long> nums(n);

        for (long long i = 0; i < n; i++) cin >> nums[i];

        long long pr = 1e9;
        bool br = 0;
        for (long long i = 2; i < 200; i++) {
            for (long long j = 0; j < n; j++) {
                if (__gcd<long long>(nums[j], i) == 1) {
                    pr = min(i, pr);
                } 
            }
        }

        if (pr == 1e9) pr = -1;

        cout << pr << "\n";
    }
}