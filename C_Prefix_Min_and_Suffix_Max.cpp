#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long t; cin >> t;
    while (t--) {
        long long n; cin >> n;

        vector<long long> nums(n);
        vector<int> peakss(n, -1);
        vector<int> lowss(n, 1e6+1);
        vector<int> peaksp(n, -1);
        vector<int> lowsp(n, 1e6+1);
        
        for (long long i = 0; i < n; i++) {
            cin >> nums[i];

            if (i == 0 || nums[i] > peaksp[i-1]) peaksp[i] = nums[i];
            else peaksp[i] = peaksp[i-1];

            if (i == 0 || nums[i] < lowsp[i-1]) lowsp[i] = nums[i];
            else lowsp[i] = lowsp[i-1];
        }

        for (long long i = n-1; i >= 0; i--) {
            if (i == n-1 || nums[i] > peakss[i+1]) peakss[i] = nums[i];
            else peakss[i] = peakss[i+1];

            if (i == n-1 || nums[i] < lowss[i+1]) lowss[i] = nums[i];
            else lowsp[i] = lowss[i+1];
        }
        
        for (long long i = 0; i < n; i++) {
            if (i == 0 || i == n-1) cout << 1;
            //else if (nums[i] == nums[peak] || nums[i] == nums[low]) cout << 1;
            //else cout << 0;

            else if (nums[i] > lowsp[i] && nums[i] < peakss[i]) cout << 0;
            else cout << 1;
        }
            
        cout << endl;
    }
}