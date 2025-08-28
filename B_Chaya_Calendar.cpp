#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;

    while (t--) {
        int l; cin >> l;

        int year; cin >> year;
        for (int i = 0; i < l-1; i++) {
            int n; cin >> n;

            if (n == 1) year++;
            else if (year % n == 0) year = year+n;
            else year = n * ceil((double)year/n);
            //cout << year << endl;
        }

        //cout << endl;
        cout << year << endl;
    }
}