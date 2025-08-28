#include <bits/stdc++.h>

using namespace std;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    freopen("angry.in", "r", stdin);
    freopen("angry.out", "w", stdout);

    int64_t n; cin >> n;

    vector<int64_t> nums(n);

    for (int64_t i = 0; i < n; i++) {
        cin >> nums[i];
    }

    sort(begin(nums), end(nums));

    int mx = 0;
    for (int i = 0; i < n; i++) {
        queue<pair<int, int>> q;
        vector<bool> exploded(n);
        q.push({i, 1});
        exploded[i] = 1;

        while (!q.empty()) {
            pair<int, int> a = q.front();

            //cout << a.first << " " << a.second << endl;
            q.pop();

            for (int j = i-1; j >= 0; j--) {
                if (nums[a.first] - nums[j] <= a.second && !exploded[j]) {
                    exploded[j] = true;
                    q.push({j, a.second+1});
                } else if (nums[a.first] - nums[j] > a.second) break;
            }

            for (int j = i+1; j < n; j++) {
                if (nums[j] - nums[a.first] <= a.second && !exploded[j]) {
                    exploded[j] = true;
                    q.push({j, a.second+1});
                } else if (nums[j] - nums[a.first] > a.second) break;
            }
        }

        mx = max(accumulate(exploded.begin(), exploded.end(), 0), mx);
    }

    cout << mx;
}