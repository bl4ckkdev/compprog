#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n; cin >> n;

    vector<char> nums(n);
    vector<int> occ(100);
    set<char> st;

    vector<vector<int>> app(100);
    for (int i = 0; i < n; i++) {
        char a; cin >> a;

        nums[i] = a;
        occ[nums[i]]++;

        app[a-'A'].push_back(i);

        st.insert(a);
    }

    int left = 0, right = 0;

    //for (auto& i : st) {
        //if (i.second != -1) left = min(left, i.second);
        //right = max(right, i.second);
    //}

    //cout << left << " " << right;

    
    int l = 0, r = n-1;
    bool bl = 0, br = 0;
    
    int mn = 1e9;

    map<char, int> la;
    set<char> st2;

    int laa = 0;

    

    for (int i = 0; i < n; i++) {
        if (st2.size() == st.size()) {
            laa = i-1;
            break;
        } 
        st2.insert(nums[i]);
        la[nums[i]] = i;
    }

    for (int i = laa+1; i < n; i++) {
        la[nums[i]] = i;

        int mxx = 0;
        for (auto& j : la) mxx = max(mxx, i-j.second);
        left = mxx;
        right = i;

        bool br = 0;
        for (auto& j : la) {
            int a = *lower_bound(begin(app[j.first-'A']), end(app[j.first-'A']), left);
            
            if (a == *app[j.first-'A'].end()) {
                br = 1;
                break;
            }
            else j.second = a;
        } 
        if (br) break;
        mn = min(mn, right-left);
    }

    cout << mn;

    //cout << r-l+1 << endl;
}