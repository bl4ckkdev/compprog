#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; cin >> n;

    vector<int> p(n), en(n), my(n);

    for (int i = 0; i < n; i++) cin >> p[i];
    for (int i = 0; i < n; i++) cin >> en[i];
    for (int i = 0; i < n; i++) cin >> my[i];

    sort(begin(my), end(my));

    set<int> enn;
    set<int> myy;
    for (auto& i : en) {
        enn.insert(i);
    } 

    for (auto& i : my) myy.insert(i);
    
    /*for (auto& i : en) cout << i << " ";
    cout << endl;
    for (auto& j : my) cout << j << " ";*/

    int l = 0, r = 0;
    int ore = 0;
    for (int i = 0; i < n; i++) {
        auto x = upper_bound(begin(enn), end(enn), my[i]);
        auto y = upper_bound(begin(menn), end(menn), my[i]);

        if (y == end(menn)) {
            ore++;
        } else menn.erase(y);

        if (x != begin(enn)) {
            x = prev(x);

            if (*x >= my[i]) continue;
            cout << *x << " ";
            enn.erase(x);
            r++;
        }
    }

    if (ore >= ceil((long double)n/2)) cout << 0;
    else if (n-r < ceil((long double)n/2)) cout << n-r;
    else cout << -1;
}