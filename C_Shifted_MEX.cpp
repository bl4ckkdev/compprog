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

        int left = 0, right = 0;

        sort(begin(nums), end(nums));
        int max = 1;
        int ml = 0, mr = 0;
        for (int i = 0; i < n-1; i++) {
            if (nums[i+1]-nums[i] > 1) {
                left = i+1;
                right = i+1;
            } else {
                right++;
            }

            if (nums[right]-nums[left]>=max) {
                max = nums[right]-nums[left]+1;
                ml = left; mr = right;
            }
        }

        cout << max << endl;
    }
}