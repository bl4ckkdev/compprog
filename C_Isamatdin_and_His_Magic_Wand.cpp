#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;

    while (t--) {
        int n; cin >> n;

        vector<int> nums(n);

        bool even = 0, odd = 0;
        for (int i = 0; i < n; i++) {
            cin >> nums[i];

            if (nums[i] % 2 == 0) odd = 1;
            else even = 1;
        }

        if (odd && even) sort(begin(nums), end(nums));

        for (auto i : nums) cout << i << " ";
        cout << endl;
    }
}