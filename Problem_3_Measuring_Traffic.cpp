#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ///freopen("traffic.in", "r", stdin);
    ///freopen("traffic.out", "w", stdout);

    int n; cin >> n;

    vector<string> ons(n);
    vector<int> l(n);
    vector<int> r(n);

    for (int i = 0; i < n; i++) {
        string status;
        int low, high; cin >> status >> low >> high;

        ons[i] = status;
        l[i] = low;
        r[i] = high;
    }

    int apl = 0, apr = 10e5;
    for (int i = 0; i < n; i++) {
        if (ons[i] == "on") {
            apl += l[i];
            apr += r[i];
        }

        if (ons[i] == "none") {
            apl = max(apl, l[i]);
            apr = min(apr, r[i]);
        }

        if (ons[i] == "off") {
            apl -= l[i];
            apr -= r[i];

            apl = max(apl, 0);
        }
    }

    int xapl = 0;
    int xapr = 10e5;


    for (int i = 0; i < n; i++) {
        if (ons[i] == "on") {
            xapl -= l[i];
            xapr -= r[i];
        }

        if (ons[i] == "none") {
            xapl = max(apl, l[i]);
            xapr = min(apr, r[i]);
        }

        if (ons[i] == "off") {
            xapl += l[i];
            xapr += r[i];

            xapl = max(xapl, 0);
        }
    }

    cout << xapl << " " << xapr << endl << apl << " " << apr;
}