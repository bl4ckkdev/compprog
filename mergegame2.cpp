#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; cin >> n;

    vector<long long> nums(n);

    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    multiset<long long> art, per;

    for (int i = 0; i < n; i++) {
        if (nums[i]%2 == 0) {
            art.insert(nums[i]);
        } else {
            per.insert(nums[i]);
        }
    }

    long long cost = 0;
    if (art.size()>0 && per.size()>0) {
        cout << -1 << endl;
    } else if (art.size()>0) {

        while (art.size()>1) {

            int nc = *begin(art) + *next(begin(art));
            cout << nc+8 << " ";
            cost += nc+8;

            art.erase(begin(art));
            art.erase(begin(art));

            art.insert(nc+8);

        }

        cout << cost;
    } else {
        cout << "aa";
    }
}