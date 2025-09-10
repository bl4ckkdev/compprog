#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    freopen("herding.in", "r", stdin);
    freopen("herding.out", "w", stdout);

    vector<int> nums(3);

    for (int i = 0; i < 3; i++) {
        cin >> nums[i];
    }

    sort(begin(nums), end(nums));

    int a = nums[0], b = nums[1], c = nums[2];

    int right = c-b-1, left = b-a-1;
    int rightm = min(right, 2), leftm = min(left, 2);

    if (rightm == 0) rightm = 1e9;
    if (leftm == 0) leftm = 1e9;

    //if (c ==)


    if (nums[1] == nums[0]+1) left = -1;
    else if (nums[2] == nums[1]+1) right = -1;

    if (b == a+1 && c == b+1) cout << "0\n0";
    else cout << min(leftm, rightm) << endl << max(right, left);
}