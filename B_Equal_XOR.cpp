#include <bits/stdc++.h>

using namespace std;

int main() {
    int t; cin >> t;

    while (t--) {
        int n, k; cin >> n >> k;

        vector<int> nums(2*n);
        set<int> l, r;

        for (int i = 0; i < 2*n; i++) {
            cin >> nums[i];

            if (i<n) l.insert(nums[i]);
            else r.insert(nums[i]);
        }

        vector<int> pairs, cancelsl, cancelsr;

        for (int i = 0; i < 2*n; i++) {
            if (i<n) {
                if (r.find(nums[i]) != r.end()) {
                    pairs.push_back(nums[i]);
                } else {
                    cancelsl.push_back(nums[i]);
                }
            } else {
                if (l.find(nums[i]) == l.end()) {
                    cancelsr.push_back(nums[i]);
                }
            }
        }

        sort(cancelsl.begin(), cancelsl.end());
        sort(cancelsr.begin(), cancelsr.end());

        int j = 2*k;

        int sz = min(2*k, (int)pairs.size());
        
        for (int i = 0; i < sz; i++) {
            if (i != sz-1 || (sz % 2 == 0 ||pairs.size()>= 2*k))
                cout << *(pairs.begin()+i) << " ";
            
            if (i == sz-1) j -= i+1;
        }

        //cout << j << "aa";
        
        for (int i = 0; i < min(j, (int)cancelsl.size()); i++) {
            cout << cancelsl[i] << " ";
        }

        cout << endl;

        j = 2*k;

        for (int i = 0; i < sz; i++) {
            if (i != sz-1 || (sz % 2 == 0 ||pairs.size()>= 2*k))
                cout << *(pairs.begin()+i) << " ";
            
            if (i == sz-1) j -= i+1;
        }

        for (int i = 0; i < min(j, (int)cancelsr.size()); i++) {
            cout << cancelsr[i] << " ";
        }

        cout << endl;
    }
    return 0;
}