#include <bits/stdc++.h>

using namespace std;

vector<int> primefactor(int n) {
    vector<int> f;
    if (n==1) f.push_back(1);
    for (int i = 2; i * i <= n; i++) {
        while (n % i == 0) {
            f.push_back(i);
            n /= i;
        }
    }

    if (n>1) f.push_back(n);

    return f;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;

    while (t--) {
        int n; cin >> n;

        vector<int> nums(n);

        for (int i = 0; i < n; i++) {
            cin >> nums[i];
        }
        bool be = 1;

        for (int i = 1; i < n; i++) {
            be &= nums[i] >= nums[i-1];
        }

        //for (auto& i : primefactor(8)) cout << i << "  ";

        if (be) {
            cout << "Bob\n";
            continue;
        }

        vector<vector<int>> td(n);

        for (int i = 0; i < n; i++) {
            td[i] = primefactor(nums[i]);
        }
        

        bool bob = true;

        vector<int> f;

        for (int i = 0; i < n; i++) {

            if (td[i].size()>0) f.push_back(td[i][0]);

            for (int j = td[i].size()-1; j >= 1; j--) {
                if (td[i][j] != td[i][j-1]) {
                    bob = false;
                }

                f.push_back(td[i][j]);
            }
        }

        //for (auto& i : f) cout << i << " ";

        for (int i = 1; i < f.size(); i++) {
            if (f[i] < f[i-1]) {
                bob = false;
                break;
            }
        }

        cout << (bob ? "Bob" : "Alice");
        cout << endl;
    }
}