#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;

    while (t--) {
        int n; cin >> n;
        int k; cin >> k;

        vector<int> nums(n);

        for (int i = 0; i < n; i++) {
            cin >> nums[i];
        }

        vector<int> freq(n+1);

        set<int> extr;

        set<int> cur;
        for (int i = 0; i < k; i++) {
            freq[nums[i]]++;
            cur.insert(nums[i]);
            if (nums[i]>k || freq[nums[i]]>1) extr.insert(nums[i]);
        }

        set<int> missing;
        

        for (int i = 0; i < n+1; i++) {
            if (freq[i] == 0) missing.insert(i);
        }
        
        int mex = *missing.begin()-1 + ((extr.size()>0) || ((*end(cur))>(*begin(missing))));


        for (int i = 1; i <= n-k; i++) {
            freq[nums[i-1]]--;

            freq[nums[i+k-1]]++;
            if (freq[nums[i-1]] <= 1) extr.erase(nums[i-1]);


            if (nums[i+k-1]>k || freq[nums[i+k-1]]>1) extr.insert(nums[i+k-1]);

            if (freq[nums[i-1]] == 0) {
                missing.insert(nums[i-1]);
                cur.erase(nums[i-1]);
            } 
            //cout << freq[nums[i-1]] << "/"; 

            cur.insert(nums[i+k-1]);
            missing.erase(nums[i+k-1]);

            //for (auto& i : missing) cout << i;
            //cout << i << "+" << *missing.begin() << ",";
            if ((*missing.begin()-1 + ((extr.size()>0) || ((*end(cur))>(*begin(missing))))) > mex) {
                mex = *missing.begin()-1 + ((extr.size()>0) || ((*end(cur))>(*begin(missing))));
            }
        }

        cout << mex << endl;
    }
}