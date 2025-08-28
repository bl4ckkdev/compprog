#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long t; cin >> t;

    while (t--) {
        long long n, c; cin >> n >> c;

        vector<long long> nums(n);

        long long least = 10e9+1;
        long long leasti = 0;

        for (long long i = 0; i < n; i++) {
            cin >> nums[i];
        }

        sort(nums.begin(), nums.end());

        for (long long i = 0; i < n; i++) {
            if (nums[i] <= c && abs(c - nums[i]) < least) {
                least = abs(c - nums[i]);

                leasti = i;
            } 
        }

        long long coins = 0;
        long long multiplier = 1;


        vector<bool> marked(n);
        for (long long i = leasti; i >= 0; i--) {
            if (nums[i]*multiplier<=c) {
                marked[i] = true;

                //cout << nums[i] << " ";

                multiplier*=2;
            } 
        }


        for (long long i = 0; i < n; i++) {
            if (marked[i]) continue;

            if (nums[i]*multiplier>c) {
                coins++;
            } 

            multiplier*=2;
        }

        cout << coins << endl;
    }
}