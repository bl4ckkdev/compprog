#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;

    while (t--) {
        int n; cin >> n;

        vector<int> nums(n);

        int sum = 0;
        for (int i = 0; i < n; i++) {
            cin >> nums[i];
            sum += nums[i];
        }

        if (sum == n || nums[0] == 1 || nums[n-1 ] == 1) cout << "Alice\n";
        else cout << "Bob\n";
    }
}