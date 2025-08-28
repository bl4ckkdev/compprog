#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int64_t t; cin >> t;

    while (t--) {
        int64_t n; cin >> n;

        vector<int64_t> nums(n);

        for (int64_t i = 0; i < n; i++) {
            cin >> nums[i];
        }

        sort(nums.begin(), nums.end(), greater<int64_t>());

        int64_t ways = 0;

        

        /*for (int64_t i = 1; i < n; i++) {
            for (int64_t j = i+1; j < n; j++) {
                if (nums[i]+nums[j]>nums[0]) {
                    cout << 0 << " " << i << " " << j << "  ";
                    ways++;
                } 
                else break;
            }
        }

        cout << "\n";*/

        for (int64_t i = 0; i < n; i++) {
            bool br = false;
            for (int64_t j = i+1; j < n; j++) {
                for (int64_t k = j+1; k < n; k++) {
                    if (nums[i]+nums[j]+nums[k]>nums[0] && nums[j]+nums[k]>nums[i]) {
                        //cout << i << " " << j << " " << k << "  ";
                        ways++;
                    } else {
                        //cout << nums[i] << " " << nums[j] << " " << nums[k] << "  ";
                        br = true;
                        break;
                    }
                }
                if (br) break;
            }
            if (br) continue;
        }

        //cout << "\n";

        cout << ways << endl;
    }
}