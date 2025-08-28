#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;

    while (t--) {
        int n, x; cin >> n >> x;

        bool started = false;
        bool can = false;

        for (int i = 0; i < n; i++) {
            int num; cin >> num;
            //cout << num << endl;
            if (!started && num == 1) started = true;

            //cout << started << " " << num << " " << x << endl;;
            if (started && num == 1 && x <= 0) {
                can = true;
            }
            if (started) {
                x--;
            }
        }
        //cout << x << endl;
        //cout << first << " " << last << " " << x << endl;
        cout << (can? "NO" : "YES") << endl;
    }
}