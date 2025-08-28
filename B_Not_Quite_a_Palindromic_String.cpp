#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;

    while (t--) {
        int n, k; cin >> n >> k;
        vector<int> nums(n);
        int s1 = 0, s2 = 0;
        for (int i = 0; i < n; i++) {
            char num; cin >> num;

            if (num - '0' == 0) s1++;
            else s2++;

            nums[i] = num - '0';
        }
        
        int pairs0 = s1/2;
        int pairs1 = s2/2;

        if (abs((s2 > s1 ? s2 : s1) - (s2 > s1 ? s1 : s2)) /2 > k) cout << "NO" << endl;
        else {
            if (pairs0 + pairs1 >= k && k % 2 == (pairs0+pairs1)%2) cout << "YES" << endl;
            else cout << "NO" << endl;
        }
    }
}