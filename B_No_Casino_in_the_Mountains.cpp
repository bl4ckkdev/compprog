#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;

    while (t-- ) {
        int n, k; cin >> n >> k;

        vector<int> nums(n);
        vector<int> nears(n, -1);

        for (int i = 0; i < n; i++) {
            cin >> nums[i];

            if (nums[i] == 1 && i>=k && (nears[i-k] == -1 || nears[i-k]>0)) {
                if (nums[i-k] != 1) nears[i-k] = k;
                
            }
            if (nums[i] == 1) {
                for (int j = i-1; j > max(-1, i-k); j--) {
                    
                    if (nums[j] == 1) break;

                    nears[j] = -3;
                }

                nears[i] = -2;
            } 
        }

        for (int i = n-1; i > n-k; i--) {
            nears[i] = -3;
        }

        //for (auto& i : nears) cout << i << " ";
        int peaks = 0;
        for (int i = 0; i < n; i++) {
            if (nears[i] >= 1 || nears[i] == -1) {
                peaks++;

                i += k;
            }
        }
        cout << peaks << endl;
    }
}