#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long t; cin >> t;

    while (t--) {
        long long n, k; cin >> n >> k;

        if (k % 2 == 0) {
            vector<long long> nums(n);

            for (long long i = 0; i < n; i++) {
                nums[i] = n-1;

                if (i == n-2) nums[i] = n;
            }

            for (auto& i : nums) cout << i << " ";
            cout << endl;
        } else {
            vector<long long> nums(n);

            for (long long i = 0; i < n; i++) {
                nums[i] = n;

                if (i == n-1) nums[i] = n-1;
            }

            for (auto& i : nums) cout << i << " ";
            cout << endl;
        }
    }
}