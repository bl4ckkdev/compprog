#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int m; cin >> m;
    vector<int> nums(m);

    for (int i = 0; i < m; i++) cin >> nums[i];
    int x, y; cin >> x >> y;

    vector<int> prefix(m+1);
    prefix[0] = 0;
    for (int i = 1; i <= m; i++) {
        prefix[i] = prefix[i-1] + nums[i-1];
    }

    int pos = -1;
    for (int i = 1; i <= m; i++) {
        int l = prefix[i];
        int r = prefix[m]-prefix[i];

        if (l >= x && l <= y && r >= x && r <= y) {
            pos = i;
            break;
        }
    }

    cout << pos+1;
}