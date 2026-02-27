#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;

    while (t--) {
        int n, s, x; cin >> n >> s >> x;

        vector<int> nums(n);
        long long sum = 0;
        for (int i = 0; i < n; i++) {
            cin >> nums[i];

            sum += nums[i];
        }

        cout << ((s-sum >= 0) == (x>=0) && abs(sum-s)%x == 0 ? "YES" : "NO") << endl;
    }
}