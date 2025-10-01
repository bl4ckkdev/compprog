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

        for (int i = 1; i < n-1; i++) {
                int op = min(nums[i]/2, min(nums[i-1], nums[i+1]));

                nums[i] -= op*2;
                nums[i+1] -= op;
                nums[i-1] -= op;
        }

        if (accumulate(begin(nums), end(nums), 0) == 0) cout << "YES\n"; else cout << "NO\n";
    }
}