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
        }

        int target = -1;

        target = accumulate(nums.begin(), nums.end(), 0);
        bool cooked = false;

        if ((double)target/n != target/n) cooked = true;


        for (int i = 1; i < n-1; i++) {
            nums[i+1] = nums[i] - (target-nums[i-1])
            nums[i-1] = target;
        }

        cout << target << endl;
    }
}