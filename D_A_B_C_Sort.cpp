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

        vector<int> nnums = nums;

        sort(nnums.begin(), nnums.end());

        int middle = nnums[nnums/2];


        vector<int> newarr(n);

        for (int i = n-1; i >= 0; i--) {
            if (nums[i] > middle) {
                newarr[i] = nums[i];
            } else {
                newarr[n-(n-i)]
            }
        }
    }
}