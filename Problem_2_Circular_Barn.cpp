#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    freopen("cbarn.in", "r", stdin);
    freopen("cbarn.out", "w", stdout);

    int n; cin >> n;

    vector<int> nums(n);
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }


    int orsoom = accumulate(nums.begin(), nums.end(), 0);
    int mxs = 1e9;
    for (int i = 0; i < n; i++) {
        int sum = 0;
        int soom = orsoom;

        for (int j = 0; j < n; j++) {
            soom -= nums[(j+i)%n];
            sum += soom;
        }

        if (sum < mxs) mxs = sum;
    }

    cout << mxs;
}