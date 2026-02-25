#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;

    while (t--) {
        int n; cin >> n;
        
        vector<int> nums(n);

        for (int i = 0; i < n; i++) cin >> nums[i];

        int mx = 0;
        int mid = 0;
        for (int i = 0; i < n; i++) {
            if (nums[i]>mx) {
                mx = nums[i];
            }
        }

        cout << mx*nums.size() << endl;
    }
}