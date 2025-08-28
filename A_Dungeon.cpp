#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;

    while (t--) {
        long long a, b, c; cin >> a >> b >> c;

        if ((a+b+c) % 9 != 0) {
            cout << "NO" << endl;
        } else {
            if ((a+b+c)/(double)9 <= min(a, min(b, c))) {
                cout << "YES" << endl;
            } else cout << "NO" << endl;
        } 
        
    }

    return 0;
}