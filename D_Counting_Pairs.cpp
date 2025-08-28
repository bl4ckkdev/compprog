#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;

    while (t--) {
        int n, x, y; cin >> n >> x >> y;

        vector<int> nums(n);
        int sum = 0;
        for (int i = 0; i < n; i++) {
            cin >> nums[i];
            sum += nums[i];
        }

        sort(nums.begin(), nums.end());
        int mn = -1, mx = -1;
        int pairs = 0;
        for (int i = 0; i < n-1; i++) {
            if (sum - nums[i] - nums[n-1] >= x) {
                mn = i;
            }
        }

        for (int i = n-1; i >= 1; i--) {
            if (sum - nums[0] - nums[i] <= y) {
                mx = i;
            }
        }

        for (int i = 0; i < n; i++) {

            cout << upper_bound(nums.begin(), nums.end(), sum - y - nums[i]) - nums.begin() << endl;
            cout << lower_bound(nums.begin(), nums.end(), sum - x - nums[i]) - nums.begin() << endl;

            cout << endl;

        }

        cout << mn << " " << mx << endl << endl;
    }
}