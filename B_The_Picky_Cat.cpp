#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;

    while (t--) {
        int n; cin >> n;

        vector<int> nums(n);

        for (int i = 0; i < n; i++) {
            cin >> nums[i];
            nums[i] = abs(nums[i]);
        }

        int num = nums[0];
        int place = ceil((double)n/2);

        sort(nums.begin(), nums.end());

        int idx = -1;
        for (int i = 0; i < n; i++) {
            if (nums[i] == num) idx = i;
        }

        if (n-idx>=place) cout << "YES\n";
        else cout << "NO\n";
    }
}