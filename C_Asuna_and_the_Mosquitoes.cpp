#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int64_t t; cin >> t;

    while (t--) {
        int64_t n; cin >> n;

        vector<int64_t> nums(n);

        int64_t mx = -1;
        vector<int64_t> evens, odds;
        for (int64_t i = 0; i < n; i++) {
            cin >> nums[i];

            mx = max(nums[i], mx);
            if (nums[i] % 2 == 0) evens.push_back(nums[i]);
            else odds.push_back(nums[i]);
        }


        int64_t sum = accumulate(nums.begin(), nums.end(), 0);
        sort(odds.begin(), odds.end());

        int64_t sz = odds.size()-evens.size()-1;

        

        if (evens.size()>=odds.size() || odds.size() == 2 && evens.size() == 1) sz = 1;
        //cout << sz << " ";
        int64_t odd = odds.size();
        for (int64_t i = 0; i < min(sz, odd-1); i++) {
            sum -= odds[i];
        }

        if (odds.size() == 0) sum = mx;
        cout << (evens.size() == 0 || odds.size() == 0 ? mx : accumulate(nums.begin(), nums.end(), 0LL) - odds.size()+1) << endl;
    }
}