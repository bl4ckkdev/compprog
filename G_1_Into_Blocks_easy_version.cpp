#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q; cin >> n >> q;

    
    vector<int> nums(n);

    vector<int> freq(200001);
    vector<int> lastocc(200001);

    for (int i = 0; i < n; i++) {
        cin >> nums[i];

        lastocc[nums[i]] = i;
        freq[nums[i]]++;
    }

     

    vector<int> segments;
    segments.push_back(0);

    
    int locc = 0;
    for (int i = 0; i < n; i++) {
        locc = max(locc, lastocc[nums[i]]);

        if (i == locc) {
            if (i == n-1) break;
            segments.push_back(i+1);
        }

        freq[nums[i]]--;
    }

    
    int sz = segments.size();


    for (auto& i : segments) {
        //cout << i << " ";
    }
    

    int moves = 0;
    for (int i = 0; i < sz; i++) {
        map<int, int> sfreq;
        int b = segments[i], f;
        
        if (i == sz-1) f = n;
        else f = segments[i+1];

        

        for (int j = b; j < f; j++) {
            sfreq[nums[j]]++;
        }

        pair<int, int> big = {-1, -1};

        for (auto& j : sfreq) {
            if (j.second>big.second) {
                big.first = j.first;
                big.second = j.second;
            }
        }

        //cout << b << " " << f << " " << big.first << endl;
        for (int j = b; j < f; j++) {
            if (nums[j] != big.first) {
                moves++;
            }
        }
    }

    cout << moves;
}