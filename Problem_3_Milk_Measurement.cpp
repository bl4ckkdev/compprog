#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    freopen("measurement.in", "r", stdin);
    freopen("measurement.out", "w", stdout);

    int n; cin >> n;

    vector<pair<int, pair<string, int>>> pairs(n);

    for (int i = 0; i < n; i++) {
        cin >> pairs[i].first >> pairs[i].second.first >> pairs[i].second.second;
    }

    sort(pairs.begin(), pairs.end(), [](pair<int, pair<string, int>> &a, pair<int, pair<string, int>> &b) {
        return a.first < b.first;
    });

    bool ad = false, bd = false, cd = false;
    int a = 7, b = 7, c = 7;
    int maxe = 0;
    int moves = 0;

    for (int i = 0; i < n; i++) {
        //cout << moves << " " << maxe << " " << a << " " << b << " " << c << endl;

        if (pairs[i].second.first == "Mildred") {
            c += pairs[i].second.second;

            if (cd && c < maxe) {
                maxe = max(a, max(b, c));
                if (c <= a || c <= b) moves++;
            }
            if (c >= maxe && !cd) {
                cd = true;

                if (c > maxe) {
                    ad = false;
                    bd = false;
                }

                maxe = c;
                moves++;
            }
        } else if (pairs[i].second.first == "Elsie") {
            b += pairs[i].second.second;

            if (bd && b < maxe) {
                maxe = max(a, max(b, c));
                if (b <= a || b <= c) moves++;
            }

            if (b >= maxe && !bd) {
                bd = true;

                if (b>maxe) {
                    ad = false;
                    cd = false;
                }

                maxe = b;
                moves++;
            }
        } else if (pairs[i].second.first == "Bessie") {
            a += pairs[i].second.second;

            if (ad && a < maxe) {
                maxe = max(a, max(b, c));
                if (a <= b || a <= c) moves++;
            }

            if (a >= maxe && !ad) {
                ad = true;

                if (a>maxe) {
                    cd = false;
                    bd = false;
                }

                maxe = a;
                moves++;
            }
        }
    }

    cout << moves;
}