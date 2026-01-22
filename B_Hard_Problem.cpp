#include <bits/stdc++.h>

using namespace std;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long n; cin >> n;

    vector<long long> nums(n);

    for (long long i = 0; i < n; i++) {
        cin >> nums[i];
    }

    vector<long long> skippables;
    vector<long long> replaceables;

    bool f = 0;
    long long mx = 0;
    for (long long i = 1; i < n; i++) {
        if (i == n-1 && nums[i]<nums[i-1]*2LL) {
            skippables.push_back(nums[i]);
        } else if (nums[i] <= nums[i-1]*2LL && nums[i+1]<=nums[i-1]*2LL) {
            f = 1;
            skippables.push_back(nums[i]);
        }
        else if (nums[i] < nums[i-1]*2LL) {
            replaceables.push_back(nums[i-1]*2LL-nums[i]);
        }
    }

    sort(begin(replaceables), end(replaceables), greater<long long>());

    long long sum = 0;
    for (int i = 0; i < n; i++) sum += nums[i];
    if (replaceables.size()>0) mx = replaceables[0];

    long long sss = 0;
    if (f) sss = nums[nums.size()-1LL]*2LL;
    else sss = nums[nums.size()-2LL]*2LL;

    if (skippables.size()>0 && sss>mx) {
        sum -= skippables[0];

        if (!f) mx = nums[nums.size()-2]*2LL;
        else mx = nums[nums.size()-1]*2LL;

        sum += mx;

    } else if (replaceables.size()>0) {
        sum += replaceables[0];
    } 

    cout << sum;
}