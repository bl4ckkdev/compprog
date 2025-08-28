#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;

    while (t--) {
        int n; cin >> n;

        vector<int> nums(n);
        bool cooked = false;

        for (int i = 0; i < n; i++) {
            cin >> nums[i];
        }

        cooked = true;
        if (nums.size()<3) cooked = true;
        else for (int i = 0; i < n-2; i++) {
            if (nums[i+2] <= max(nums[i], nums[i+1]) && nums[i+2] >= min(nums[i], nums[i+1])) {
                cooked = false;
                break;
            } 
        }

        if (nums.size()>=3 && cooked) {
            for (int i = n-1; i >= 2; i--) {
            if (nums[i-2] <= max(nums[i-1], nums[i]) && nums[i-2] >= min(nums[i], nums[i-1])) {
                cooked = false;
                break;
            } 
        }
        }

        bool cco = false;
        for (int i = 0; i < n-1; i++) {
            if (nums[i] == nums[i+1]) cco = true;
        }
        if (!cco)
        cout << (cooked ? -1 : 1) << endl;
        else cout << 0 << endl;
    }
}