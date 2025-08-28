#include <bits/stdc++.h>

using namespace std;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long n; cin >> n;

    vector<long long> nums(n);

    for (long long i = 0; i < n; i++) {
        cin >> nums[i];
    }

    sort(begin(nums), end(nums));

    long long m = -1;
    long long idx = -1;

    for (long long i = 0; i < n; i++) {
        long long price = nums[i]*(n-i);

        if (price > m) {
            m = price;
            idx = nums[i];
        }
    }

    cout << m << " " << idx;
}