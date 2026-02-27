#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t; cin >> t;

    while (t--) {
        int n; cin >> n;

        vector<int> nums(n);
        for (int i = 0; i < n; i++) cin >> nums[i];


        if (nums[0] != n)
        for (int i = 0; i <n; i++) {
            if (nums[i] == n) {
                reverse(begin(nums), begin(nums)+i+1);
                break;
            }
        }
        else {
            int ind = 0;
            int fi = 0;
            for (int i = 0; i < n; i++) {
                if (nums[i] < n-i) {
                    ind = i;
                    fi = n-i;

                    break;
                }
            }  


            if (ind + fi != 0)
            for (int i = 0; i < n; i++) {
                if (nums[i] == fi) {
                    //cout << *(begin(nums)+ind) << " " << *(begin(nums)+i+1) << " ";
                    reverse(begin(nums)+ind, begin(nums)+i+1);
                    break;
                }
            } 
        }

        for (auto& i : nums) cout << i << " ";
        cout << "\n";
    }
}