#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; cin >> n;

    vector<int> nums(n);

    for (int i = 0; i < n; i++) cin >> nums[i];

    int mi = 1e9;

    for (int i = 0; i < n; i++) {
        mi = min(nums[i], mi);
    }

    int lastmi = -1, bestmi = 1e9;

    for (int i = 0; i < n; i++) {
        if (nums[i] == mi && lastmi == -1) {
            lastmi = i;
        }

        else if (nums[i] == mi && lastmi != -1) {
            bestmi = min(bestmi, i-lastmi);

            lastmi = i;
        }

        if (nums[i] == mi) lastmi = i;
    }

    cout << bestmi;
}