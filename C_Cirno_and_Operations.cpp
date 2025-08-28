#include <bits/stdc++.h>

using namespace std;

int main() {
    int t; cin >> t;

    while (t--) {
        int n; cin >> n;

        vector<int> ornums(n);
        for (int i = 0; i < n; i++) {
            cin >> ornums[i];
        }

        int mx = 0;

        int sm = -1001;

        vector<int> nums(n);

        for (int i = 0; i <n; i++) {
            nums[i] = ornums[i];
        }


        for (int j = 0; j < n; j++) {
            sm += nums[j];
        }

        mx = sm;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n-1; j++) {
                nums[j] = nums[j+1] - nums[j];
            }

            nums[n-1] = 0;

            int sum = 0;
            for (int j = 0; j < n; j++) {
                sum += nums[j];
            }

            mx = max(abs(sum), mx);
        }

        for (int i = 0; i <n; i++) {
            nums[i] = ornums[i];
        }

        sm = -1001;

        for (int j = 0; j < n; j++) {
            sm += nums[j];
        }

        mx = max(sm, mx);

        reverse(nums.begin(), nums.end());

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n-1; j++) {
                nums[j] = nums[j+1] - nums[j];
            }

            nums[n-1] = 0;

            int sum = 0;
            for (int j = 0; j < n; j++) {
                sum += nums[j];
            }

            mx = max(n > 1 ? abs(sum) : sum, mx);
        }

        cout << mx <<endl;
    }
}