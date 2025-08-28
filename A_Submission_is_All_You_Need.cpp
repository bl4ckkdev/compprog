#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int64_t t; cin >> t;

    while (t--) {
        int64_t n; cin >> n;
        vector<int64_t> nums(n);

        int64_t z = 0, o = 0;
        for (int64_t i = 0; i < n; i++) {
            int64_t num; cin >> num;
            if (num == 0) z++;
            else if (num == 1) o++;
            else nums.push_back(num);
        }

        int64_t s = 0;

        s += z;
        s += o;

        s += accumulate(nums.begin(), nums.end(), 0);

        cout << s << endl;
    }
}