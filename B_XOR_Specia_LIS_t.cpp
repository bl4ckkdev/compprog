#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int tc; cin >> tc;

    while (tc--) {
        int l; cin >> l;

        vector<int> nums(l);

        bool prev = false;
        bool count = true;

        for (int i = 0; i < l; i++) {
            int num; cin >> num;

            if (i > 0) count &= num>nums[i-1];

            nums[i] = num;
        }

        
        if (l % 2 == 0 || !count) {
            cout << "YES" << endl;
        }
        else {
            cout << "NO" << endl;
        } 
    }

    return 0;
}