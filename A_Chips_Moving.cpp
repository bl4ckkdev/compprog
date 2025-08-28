#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; cin >> n;

    vector<int> nums(n);
    vector<int> sums(n, 0);
    for (int i = 0; i < n; i++) {
        int num; cin >> num;
        
        nums[i] = num;
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j) continue;
            sums[i] += ((nums[i] % 2 == nums[j] % 2) ? 0 : 1);
        }
    }

    sort(sums.begin(), sums.end());

    cout << sums[0];
}