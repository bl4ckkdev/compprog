#include <bits/stdc++.h>

using namespace std;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;

    while (t--) {
        int n, x, y; cin >> n >> x >> y;

        vector<int> nums(n);

        for (int i = 0; i < n; i++) {
            cin >> nums[i];
        }

        vector<int> lp, mp, rp;

        for (int i = 0; i < n; i++) {
            if (i >= x && i < y) {
                mp.push_back(nums[i]);
            } else if (i < x) {

                lp.push_back(nums[i]);

            } else if (i >= y) {
                rp.push_back(nums[i]);
            } else cout << "no!";
        }

        /*for (auto& i : lp) cout << i << " ";
        cout << "O";
        for (auto& i : mp) cout << i << " ";
        cout << "O";
        for (auto& i : rp) cout << i << " ";*/

        int mps = mp.size();
        int mpshift = 0;
        int mn = 1e9;
        for (int i = 0; i < mps; i++) {
            mn = min(mp[i], mn);
        }

        for (int i = 0; i < mps; i++) {
            if (mp[i] == mn) {
                mpshift = i;
                break;
            }
        }

        int rmin = 1e9;
        for (int i = 0; i < rp.size(); i++) {
            rmin = min(rmin, rp[i]);
        }

        int rminindex = 0;
        for (int i = 0; i < rp.size(); i++) {
            if (rp[i] == rmin) {
                rminindex = i;
            }
        }

        rotate(begin(mp), begin(mp)+mpshift, end(mp));

        int cutlp = lp.size();
        for (int i = 0; i < lp.size(); i++) {
            if (lp[i] > mn) {
                cutlp = i;
                break;
            }
        }

        int cutrp = rp.size();
        for (int i = 0; i < rp.size(); i++) {
            if (rp[i] > mn) {
                cutrp = i;
                break;
            }
        }

        if (cutlp != lp.size()) {
            for (int i = 0; i < cutlp; i++) {
                cout << lp[i] << " ";
            }

            for (int i = 0; i < mps; i++) {
                cout << mp[i] << " ";
            }

            for (int i = cutlp; i < lp.size(); i++) {
                if (cutlp == -1) break;

                cout << lp[i] << " ";
            }

            for (int i = 0; i < rp.size(); i++) {
                cout << rp[i] << " ";
            }
        } else {
            for (int i = 0; i < lp.size(); i++) {
                cout << lp[i] << " ";
            }

            for (int i = 0; i < cutrp; i++) {
                cout << rp[i] << " ";
            }

            for (int i = 0; i < mps; i++) {
                cout << mp[i] << " ";
            }

            for (int i = cutrp; i < rp.size(); i++) {
                if (cutrp == -1) break;
                cout << rp[i] << " ";
            }
        }


        cout << endl;
    }
}