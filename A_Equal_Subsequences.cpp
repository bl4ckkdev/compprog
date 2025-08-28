#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;

    while (t--) {
        int n, k; cin >> n >> k;

        string a = "";
        
        for (int i = 0; i < n; i++) {
            if (k<=0)  a += "0";
            else {
                a += "1";
                k--;
            }
        }

        cout << a << endl;
    }
}