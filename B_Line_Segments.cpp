#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long t; cin >> t;

    while (t--) {
        long long n, px, py, qx, qy; cin >> n >> px >> py >> qx >> qy;

        vector<long long> nums(n);

        long long mx = -1;

        for (long long i = 0; i < n; i++) {
            cin >> nums[i];

            mx = max(mx, nums[i]);
        }

        long double dist = sqrt(pow(px - qx, 2LL) + pow(py - qy, 2LL));

        long long euc = accumulate(nums.begin(), nums.end(), 0LL);


        //cout << dist << " " << euc << endl;

        if (n == 1) {
            if (dist != euc) {
                cout << "No" << endl;
            } else cout << "Yes" << endl;
        }
        else if (n == 2 && dist == 0) {
            if (nums[0] != nums[1]) cout << "No" << endl;
            else cout << "Yes" << endl;
        } else {
            if (euc>= dist && (mx < dist || mx-dist <= euc-mx)) cout << "Yes" << endl;
            else cout << "No" << endl;
        }
    }
}