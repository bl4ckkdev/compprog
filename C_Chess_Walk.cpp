#include <bits/stdc++.h>

using namespace std;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long n, m; cin >> n >> m;
    
    vector<pair<long long, long long>> nums(m);

    for (long long i = 0; i < m; i++) {
        cin >> nums[i].second >> nums[i].first;
    }

    sort(begin(nums), end(nums));

    vector<long long> ways(8, 1);

    vector<long long> oldways = ways;

    long long r = nums[0].first;
    for (long long i = 0; i < m; i++) {
        if (nums[i].first != r) {
            oldways = ways;
        }

        r = nums[i].first;
        

        long long c = nums[i].second;
        //cout << r << " " << c << "  ";
        ways[c-1] = 0;
        if (c < 8) ways[c-1] += oldways[c]%1000000007;
        if (c > 1) ways[c-1] += oldways[c-2]%1000000007;
    }

    for (auto& i : ways) cout << i%1000000007 << " ";

}