#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long t; cin >> t;

    while (t--) {
        long long n, k; cin >> n >> k;

        vector<long long> nums(n);

        long long mine = 1e9+1, maxe = -1, sum = 0;

        bool twomaxes = false;
        for (long long i = 0; i < n; i++) {
            cin >> nums[i];

            if (nums[i] < mine) mine = nums[i];
            if (nums[i] > maxe) maxe = nums[i];

            sum += nums[i];
        }

        for (long long i = 0; i < n; i++) {
            if (!twomaxes && nums[i] == maxe) twomaxes = true;
            else if (twomaxes && nums[i]==maxe) maxe++;
        }

        if (maxe-mine-1>k) cout << "Jerry\n";
        else if (sum % 2 == 1) cout << "Tom\n";
        else cout << "Jerry\n";
    }
}