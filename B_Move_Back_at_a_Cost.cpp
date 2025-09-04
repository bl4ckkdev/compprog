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

        vector<int> sm(n);
        
        sm[n-1] = nums[n-1];
        for (int i = n-2; i >= 0; i--) {
            sm[i] = min(nums[i], sm[i+1]);
        }

        int smp = -1;

        int idx = -1;

        for (int i = 0; i < n; i++) {
            if (sm[i] != nums[i] || (smp != -1 && smp < nums[i])) {
                nums[i]++;
                if (smp == -1) smp = nums[i];
                else smp = min(smp, nums[i]);
            } 
            //cout << smp << " ";
        }

        //cout << endl;
        sort(begin(nums), end(nums));

        for (auto& i : nums) cout << i << " ";

        cout << endl;
    }
}