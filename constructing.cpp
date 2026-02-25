#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k, l; cin >> n >> k >> l;
    
    vector<pair<int, int>> ab;

    bool doable = true;

    if (n-k<2) doable = false;
    

    for (int i = 2; i <= k; i++) {
        ab.push_back({i, i-1});
    }

    for (int i = k+1; i <= k+l; i++) {
        ab.push_back({1, i});
    }

    for (int i = k+l+1; i<=n; i++) {
        if (i == k+l+1) {
            ab.push_back({k, i});
        } else if (i == n) {
            ab.push_back({i-1, i});
            ab.push_back({2, i});
        } else {
            ab.push_back({i-1, i});
        }
    }

    cout << ab.size() << endl;
    for (auto& i : ab) {
        cout << i.first << " " << i.second << endl;
    }
}