#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    freopen("mixmilk.in", "r", stdin);
    freopen("mixmilk.out", "w", stdout);

    int64_t c1, a1, c2, a2, c3, a3; cin >> c1 >> a1 >> c2 >> a2 >> c3 >> a3;

    for (int64_t i = 0; i < 100; i++) {
        if (a2+a1 > c2) {
            a1 -= (c2-a2);
            a2 = c2;
        } else {
            a2 += a1;
            a1 = 0;
        }

        i++;

        if (i+1 >= 100) break;

        if (a3+a2 > c3) {
            a2 -= (c3-a3);
            a3 = c3;
        } else {
            a3 += a2;
            a2 = 0;
        }    
        
        i++;

        if (a3+a1 > c1) {
            a3 -= (c1-a1);
            a1 = c1;
        } else {
            a1 += a3;
            a3 = 0;
        }    
    }

    cout << a1 << endl << a2 << endl << a3;
}