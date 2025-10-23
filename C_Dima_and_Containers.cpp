#include <bits/stdc++.h>

using namespace std;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int64_t n; cin >> n;

    vector<vector<int64_t>> nums(1);
    vector<int64_t> breaks;

    int64_t ni = 0;
    for (int64_t i = 0; i < n; i++) {
        int64_t num; cin >> num;

        
        if (num == 0) {
            breaks.push_back(i);
            nums.push_back({});
            ni++;
        } else nums[ni].push_back(num);
    }

    vector<vector<int64_t>> snums(nums.size());
    for (int64_t i = 0; i < nums.size(); i++) {
        snums[i] = nums[i];
        sort(begin(snums[i]), end(snums[i]), greater<int64_t>());
    }

    for (int64_t i = 0; i < nums.size(); i++) {
        bool f = 0, s = 0, t = 0;

        
        for (int64_t j = 0; j < nums[i].size(); j++) {
            if (!f && nums[i][j] == snums[i][0]) {
                f = 1;
                cout << "pushFront\n";
            } else if (!s && nums[i].size()>1 && nums[i][j] == snums[i][1]) {
                s = 1;
                cout << "pushStack\n";
            } else if (!t && nums[i].size()>2 && nums[i][j] == snums[i][2]) {
                t = 1;
                cout << "pushQueue\n";
            } else cout << "pushBack\n";
        }

        if (i != nums.size()-1) {
            cout << f+s+t;
            if (f) cout << " " << "popFront";
            if (s) cout << " " << "popStack";
            if (t) cout << " " << "popQueue";
            cout << endl;
        }
        
    }

    //cout << "0\npushStack\n1 popStack\npushStack\npushQueue\n2 popStack popQueue\npushStack\npushQueue\npushFront\n3 popStack popQueue popFront";
}