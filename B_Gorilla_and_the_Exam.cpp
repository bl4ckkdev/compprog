#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;

    while (t--) {
        int n, k; cin >> n >> k;

        vector<int> nums(n);
        for (int i = 0; i < n; i++) {
            cin >> nums[i];
        }

        sort(nums.begin(), nums.end());

        int f = 0;

        map<int, int> occ;

        
        for (int i = 0; i < n; i++) {
            occ[nums[i]]++;
        }
        /*for (auto& a : occ) {
            cout << a.first << " " << a.second << endl;
        }*/

        int budget = k;

        cout << "LAST: " << occ.rbegin()->first;
        for (auto& a : occ) {
            for (int i = 0; i < n; i++) {
                if (budget <= 0) break;
                //cout << a.first << endl << endl;
                if (nums[i] == a.first) {
                    nums[i] = occ.rbegin()->first;
                    budget--;
                }
            }

            if (budget <= 0) break;
            //cout << a.first << " " << a.second << endl;
        }

        for (int i = f; i < min(n, f+k); i++) {
            nums[i] = nums[0];
        }

        int count = 1;

        sort(nums.begin(), nums.end());
        //for (auto& i : nums) cout << i << endl;
        int last = nums[0]; 
        for (int i = 1; i < n; i++) {
            if (nums[i] != last) count++;

            last = nums[i];
        }

        //cout << endl;
        cout << count << endl;
        cout << endl;
    }
}