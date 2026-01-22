#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; cin >> n;

    vector<int> nums(n);
    vector<bool> attached(n);

    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    int l = 0, r = n-1;

    int suml = 0, sumr = 0;


    attached[l] = 1;
    attached[r] = 1;
    vector<int> owner(n);

    vector<int> time(n);

    while (l<n) {
        suml += nums[l];
        time[l] = suml;

        l++;
    }

    while (r>=0) {
        sumr += nums[r];

        if (sumr<time[r]) {
            owner[r] = 1;
            time[r] = sumr;
        }
        r--;
    }

    int left = 0, right = 0;

    for (int i = 0; i < n; i++) {
        if (owner[i]) right++;
        else left++;
    }

    cout << left << " " << right;
}