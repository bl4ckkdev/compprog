#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; cin >> n;

    vector<int> nums(n);
    for (int i = 0; i < n; i++) {
        int num; cin >> num;
        nums[i] = num;
    }

    sort(nums.begin(), nums.end());

    int a = n;
    for (int i = 1; i < a; i++) {
        if (nums[i] == nums[i-1]) n--;
    }

    cout << n << endl;
}