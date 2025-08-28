#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;

    while (t--) {
        int n; cin >> n;

        vector<int> nums;

        for (int i = 0; i < n; i++) {
            int num; cin >> num;
            if (num != -1) nums.push_back(num);
        }

        n = nums.size();

        bool cooked = false;
        if (nums.size()>0 && nums[0] == 0) cooked = true;
        for (int i = 1; i < n; i++) {
            if (nums[i] == 0 || nums[i] != nums[i-1]) {
                cooked = true;
                break;
            }
        }
        cout << (cooked ? "NO" : "YES") << endl;
    }
}