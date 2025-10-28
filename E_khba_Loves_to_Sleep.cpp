#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;

    while (t--) {
        int n, k, x; cin >> n >> k >> x;

        int ork = k;
        vector<int> nums(n);

        for (int i = 0; i < n; i++) {
            cin >> nums[i];
        }

        sort(begin(nums), end(nums));

        vector<pair<int, int>> gaps;

        for (int i = 0; i < n-1; i++) {
            if (nums[i+1] != nums[i]+1)
            gaps.push_back({nums[i+1]-nums[i], i});

            //if (gaps[i] == 1) gaps[i] = 0;
        }

        

        if (nums[0]>0) gaps.push_back({nums[0], -1});
        if (x-nums[n-1]>0) gaps.push_back({x-nums[n-1], 1e9+1});

        sort(begin(gaps), end(gaps), greater<pair<int, int>>());

        int cnt = 0;

        int sz = gaps.size();
        /*for (int i = 0; i < sz-1; i++) {
            if (k <= 0) break;

            if (k>gaps[i]-gaps[i+1]) {
                k -= gaps[i]-gaps[i+1];
                for (int j = i-1; j >= 0; j--) {
                    if (k == 0) break;


                }

                gaps[i] = gaps[i+1];
            } else if (i == 0) {
                gaps[i]-=k;
                k = 0;
            }
        }*/

        //for (auto i : gaps) cout << i.first << " ";
        int j = 0;
        vector<pair<int, int>> gapsv2 = gaps;
        while (k>0) {
            if (j < sz-1) {
                while (gapsv2[j].first == gapsv2[j+1].first) j++;
            }

            if (j >= sz) break;

            for (int i = 0; i<=j; i++) {
                if (k==0) break;

                if (gapsv2[i].first%2==1 && gapsv2[i].second != -1 && gapsv2[i].second != 1e9+1) k--;
                k--;
                gapsv2[i].first--;
            }
        }

        //cout << ",";
        for (auto i : gapsv2) cout << i.first << " " << i.second << "  ";
        for (int i = 0; i < sz; i++) {
            gaps[i].first = gaps[i].first-gapsv2[i].first;
        }

        sort(begin(gaps), end(gaps), [](const auto& a, const auto& b){
            return a.second<b.second;
        });

        
        //cout << "|";
        set<int> placement;

        for (int i = 0; i < sz; i++) {
            int idx = gaps[i].second;

            //cout << idx;

            int start;

            if (idx == -1) {
                start = 0;
                
            } 
            
            else if (idx == 1e9+1) start = x+1-gaps[i].first;
            else start = (nums[idx] + nums[idx+1])/2-(gaps[i].first/2);
            
            for (int j = start; j<start+gaps[i].first; j++) {
                
                placement.insert(j);
            }
        }

        int iter = 0;
        //cout << placement.size() << "a" << k << " ";
        while (placement.size() < ork) {

            while (iter < nums.size() && placement.count(nums[iter])) iter++;
            if (iter>=nums.size()) break;
            placement.insert(nums[iter]);
        }

        for (int i : placement) cout << i << " ";

        cout << endl;

    }
}