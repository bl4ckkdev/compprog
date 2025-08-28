#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;

    while (t--) {
        int n; cin >> n;

        vector<int> nums(n);

        vector<int> appearances(n);

        set<int> uniquenums;
        for (int i = 0; i < n; i++) {
            cin >> nums[i];

            appearances[nums[i]-1]++;
            uniquenums.insert(nums[i]);
        }

        
        int segments = 0;

        set<int> curnums(uniquenums);

        for (int i = n-1; i >= 0; i--) {
            curnums.erase(nums[i]);

            appearances[nums[i]-1]--;

            if (appearances[nums[i]-1] == 0) {
                uniquenums.erase(nums[i]);
            }

            if (curnums.size() == 0) {
                curnums = uniquenums;
                segments++;
            }
        }

        cout << segments << endl;
    }
}