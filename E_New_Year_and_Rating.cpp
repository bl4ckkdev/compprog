#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; cin >> n;

    vector<pair<int, int>> nums(n);

    for (int i = 0; i < n; i++) {
        cin >> nums[i].first >> nums[i].second;
    }

    int status = -3; // -1 impossible, 1e9 inf
    for (int i = 0; i < n-1; i++) {
        if (status == -3 && nums[i].second == 1) {
            status = 1e9;
        } else if (status == -3 && nums[i].second == 2) {
            status = 1899+nums[i].first;
        } else if (status == 1e9 && nums[i].second == 2) {
            status = 1899+nums[i].first;
        }
    }

    cout << status;
}