#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;

    while (t--) {
        int l; cin >> l;
        vector<int> nums(l);

        int min = -1, max = -1;
        for (int i = 0; i < l; i++) {
            int num; cin >> num;

            if (min == -1 || num < min) min = num;
            if (num > max) max = num;

            nums[i] = num;
        }

        sort(nums.begin(), nums.end());

        min = *nums.begin();
        max = *prev(nums.end());
        

        for (int i = 0; i < nums.size(); i++) {
            if ((nums[i] + nums[nums.size()-1]) % 2 == 0) {
                cout << i << endl;
                break;
            }
            else if ((nums[0] + nums[nums.size()-1-i]) % 2 == 0) {
                cout << i << endl;
                break;
            }
        }
    }
}