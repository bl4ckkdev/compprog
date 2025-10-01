#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    freopen("outofplace.in", "r", stdin);
    freopen("outofplace.out", "w", stdout);

    int n; cin >> n;

    vector<int> nums(n);

    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    } 

    int idx = -1;
    bool b = 0;

    for (int i = 1; i < n; i++) {
        if (nums[i] < nums[i-1]) {
            if (i == 1 || nums[i] >= nums[i-2]) {
                b = 1;
                idx = i-1;
            } else {
                b = 0;
                idx = i;
            } 
        }
    }

    int steps = 0;

    if (idx != -1)
    if (b) {
        for (int i = idx; i < n; i++) {
            if (nums[i] <= nums[idx] && (i == n-1 || nums[i+1]>=nums[idx])) {
                break;
            } 

            if (i < n-1 && nums[i]!=nums[i+1])
            steps++;
        }
    } else {
        for (int i = idx; i >= 0; i--) {
            if (nums[i] >= nums[idx] && (i == 0 || nums[i-1]<=nums[idx])) {
                break;
            } 

            if (i > 0 && nums[i]!=nums[i-1]) {
                steps++;
            } 
        }
    }

    cout << steps;
}