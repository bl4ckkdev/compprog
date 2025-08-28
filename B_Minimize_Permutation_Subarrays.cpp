#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;

    while (t--) {
        int n; cin >> n;
        vector<int> nums(n);

        int ind = -1;
        int indt = -1;
        for (int i = 0; i < n; i++) {
            int num; cin >> num;
            
            nums[i] = num;

            if (nums[i] == 1) ind = i;
            else if (nums[i] == 2) indt = i;
        }

        if (indt > ind) {
            if (ind+1 > n/2) cout << (ind+1) << " " << 1 << endl;
            else cout << (indt+1) << " " << n << endl;
        }
        else {
            if (indt+1 > n/2) cout << (indt+1) << " " << 1 << endl;
            else cout << (ind+1) << " " << n << endl;
        }
    }
}