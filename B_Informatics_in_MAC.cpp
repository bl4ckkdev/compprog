#include <bits/stdc++.h>

using namespace std;

int mex(vector<int>& arr, int N)
{
    // Create a map to store the frequency of each element
    map<int, int> mp;
    for (int i = 0; i < N; i++) {
        mp[arr[i]]++;
    }

    // Initialize MEX to 0
    int mex = 0;

    // Iterate through non-negative integers from 0 to N
    for (int i = 0; i <= N; i++) {
        // Find the first integer with a frequency of 0 in the map
        if (mp[i] == 0) {
            mex = i;
            break;
        }
    }

    // Return MEX as the answer
    return mex;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;

    while (t--) {
        int n; cin >> n;

        

        vector<int> nums(n);

        for (int i = 0; i < n; i++) cin >> nums[i];

        int m = mex(nums, nums.size());
        vector<bool> e(n);
        int count = 0;
        int l = 0;

        vector<pair<int, int>> r;

        
        
        //cout << "aa!" << endl;
        for (int i = 0; i < n; i++) {
            if (e[nums[i]] != 1 && nums[i] < m) count++;

            e[nums[i]] = 1;

            if (count == m) {
                e = vector<bool>(n);
                count = 0;
                
                r.push_back({l+1, i+1});

                l = i+1;
            }
        }
        
        

        r[r.size()-1].second = n;

        int check = 0;

        for (int i = 0; i < r.size(); i++) {
            check += r[i].second - r[i].first + 1;

            

            if (i == r.size()-1) {
                vector<int> whaa;
                int le = r[i].first;
                int ri = r[i].second;

                for (int j = le-1; j <= ri-1; j++) {
                    whaa.push_back(nums[j]);
                }

                int mee = mex(whaa, whaa.size());

                if (mee != m) check = 0;
            }


        }

        if (check == nums.size() && r.size() > 1) {
            cout << r.size() << endl;
            for (auto& i : r) {
                cout << i.first << " " << i.second << endl;
            }
        } else cout << -1 << endl;

        
    }
}