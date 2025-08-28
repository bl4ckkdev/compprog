#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; cin >> n;

    vector<int> nums(n);
    int hm = 0;
    int days = 0;
    for (int i = 0; i < n; i++) {
        int num; cin >> num;
        nums[i] = num;
    }

    for (int i = 0; i < n; i++) {
        if (i >= hm) days++;
        if (nums[i] > hm) hm = nums[i];
    }

    cout << days;
    return 0;
}