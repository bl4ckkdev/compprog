#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    freopen("cowqueue.in", "r", stdin);
    freopen("cowqueue.out", "w", stdout);

    int n; cin >> n;

    vector<pair<int, int>> p(n);

    for (int i = 0; i < n; i++) {
        cin >> p[i].first >> p[i].second;
    }

    sort(begin(p), end(p));

    int time = 0;
    for (int i = 0; i < n; i++) {
        if (time < p[i].first) time += (p[i].first-time);

        time += p[i].second;
    }

    cout << time;
}