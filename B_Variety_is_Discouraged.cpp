#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;

    while (t--) {
        int n; cin >> n;

        vector<int> nums(n);

        unordered_map<int, int> freq;

        for (int i = 0; i < n; i++) {
            cin >> nums[i];

            freq[nums[i]]++;
        }

        /*for (auto& i : freq) {
            cout << i.first << " ";
        }*/

        int l = -1, r = -1;
        for (int i = 0; i < n; i++) {
            if (freq[nums[i]] == 1) {
                int kl = i+1;
                int kr = kl;

                for (int j = i+1; j < n; j++) {
                    if (freq[nums[j]] == 1) {
                        kr = j+1;
                    }
                    else break;
                }


                if (kr-kl >= r-l) {
                    l = kl;
                    r = kr;
                }

                i = kr;
            }
        }

        if (l == -1) cout << 0 << endl;
        else cout << l << " " << r << endl;
    }
}