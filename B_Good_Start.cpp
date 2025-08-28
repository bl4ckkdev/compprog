#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;

    while (t--) {
        int w, h, a, b; cin >> w >> h >> a >> b;
        int x1, y1, x2, y2; cin >> x1 >> y1 >> x2 >> y2;

        if ((abs(x1-x2)-a) % a != 0 && abs((y1-y2)-b) % b != 0) {
            cout << "No" << endl;
        } else if (((abs(x1-x2)-a) % a != 0 && y1-y2 == 0) || ((abs(y1-y2)-b) % b != 0 && x1-x2 == 0)) {
             cout << "No\n";
        }
         else cout << "Yes\n";
    }
}