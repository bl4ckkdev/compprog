#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;

    while (t--) {
        int l; cin >> l;
        vector<int> nums(l);

        for (int i = 0; i < l; i++) {
            int num; cin >> num;
            nums[i] = num;
        }

        sort(nums.begin(), nums.end(), greater<int>());

        for (int i = 0; i < l; i++) {
            cout << nums[i] << " ";
        }

        cout << endl;
    }
}