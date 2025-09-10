#include <bits/stdc++.h>

using namespace std;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int64_t d, k; cin >> d >> k;

    vector<int64_t> days(d);

    for (int64_t i = 0; i < d; i++) {
        cin >> days[i];
    }

    int64_t subs = 0;
    for (int64_t i = 0; i < d; i++) {
        int64_t subscr = k+1;

        while (i < d-1 && days[i+1]-days[i] < k+1) {
            subscr += days[i+1]-days[i];
            i++;
        }

        subs += subscr;
    }

    cout << subs;
}