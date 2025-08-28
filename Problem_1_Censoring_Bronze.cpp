#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    string s; cin >> s;
    string c; cin >> c;

    int n = s.length();

    for (int i = 0; i < n; i++) {
        if (s.substr(i, c.size()) == c) {
            if (i > 0 && i < n-1) {
                
            }
            occ++;
        }
    }
    cout << occ;
}