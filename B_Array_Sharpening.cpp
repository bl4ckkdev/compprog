#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;

    while (t--) {
        int n; cin >> n;

        vector<int> nums(n);

        int peak = -1;
        bool broken = false;
        for (int i = 0; i < n; i++) {
            cin >> nums[i];

            if (nums[i] == 0 && (i != 0 && i != n-1)) {
                broken = true;
            }
            if (nums[i] > peak) peak = i;
        }
        //if (broken) continue;

        if (nums[peak] >= peak && nums[peak] >= n-peak-1 && !broken) {
            cout << "Yes\n";
        } else cout << "No\n";//nums[peak] << " " << peak << " NO\n";
    }
}